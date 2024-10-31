#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 10000

// Structure to hold results from each child
typedef struct {
    int uppercase, lowercase, numeric, special, spaces, newlines;
} ProcessResult;

// Structure to hold word frequency
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

// Function to convert a string to lowercase
void to_lowercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Function to add or update a word in the frequency list
void add_word(WordFrequency *words, int *word_count, char *word) {
    to_lowercase(word);
    for (int i = 0; i < *word_count; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    // New word
    strcpy(words[*word_count].word, word);
    words[*word_count].count = 1;
    (*word_count)++;
}

// Function to process a portion of the file and save results to a file
void process_file_section(const char *filename, long start, long end, ProcessResult *result, WordFrequency *words, int *word_count, int child_id) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file in child");
        exit(1);
    }

    if (fseek(file, start, SEEK_SET) != 0) {  // Start reading at the designated segment
        printf("Child %d: Failed to seek to position %ld\n", child_id, start);
        fclose(file);
        exit(1);
    }

    char ch;
    char word_buffer[MAX_WORD_LENGTH] = {0};
    int buffer_index = 0;

    result->uppercase = result->lowercase = result->numeric = result->special = result->spaces = result->newlines = 0;

    //printf("Child %d: Processing segment from position %ld to %ld\n", child_id, start, end);

    // Process characters in the segment
    while (ftell(file) < end && (ch = fgetc(file)) != EOF) {
        if (isupper(ch)) {
            result->uppercase++;
        } else if (islower(ch)) {
            result->lowercase++;
        } else if (isdigit(ch)) {
            result->numeric++;
        } else if (ch == ' ') {
            result->spaces++;
        } else if (ch == '\n') {
            result->newlines++;
        } else {
            result->special++;
        }

        // Word extraction
        if (isalnum(ch)) {
            if (buffer_index < MAX_WORD_LENGTH - 1) {
                word_buffer[buffer_index++] = ch;
            }
        } else if (buffer_index > 0) {
            word_buffer[buffer_index] = '\0'; // Null-terminate the word
            add_word(words, word_count, word_buffer);
            buffer_index = 0;
        }
    }

    // In case the segment ends with a word
    if (buffer_index > 0) {
        word_buffer[buffer_index] = '\0';
        add_word(words, word_count, word_buffer);
    }

    fclose(file);  // Close the file in the child

    // Write character counts to a text file
    char filename_result[30];
    snprintf(filename_result, sizeof(filename_result), "child_%d.txt", child_id);
    FILE *outfile = fopen(filename_result, "w");
    if (outfile) {
        fprintf(outfile, "%d %d %d %d %d %d\n", result->uppercase, result->lowercase,
                result->numeric, result->special, result->spaces, result->newlines);
        fclose(outfile);
    } else {
        perror("Failed to open result file");
        exit(1);
    }

    // Write word frequencies to a separate text file
    snprintf(filename_result, sizeof(filename_result), "child_%d_words.txt", child_id);
    outfile = fopen(filename_result, "w");
    if (outfile) {
        for (int i = 0; i < *word_count; i++) {
            fprintf(outfile, "%s %d\n", words[i].word, words[i].count);
        }
        fclose(outfile);
    } else {
        perror("Failed to open word result file");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file_name> <num_processes>\n", argv[0]);
        exit(1);
    }

    int num_processes = atoi(argv[2]);
    const char *filename = argv[1];

    // Determine file size and segment size
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    long segment_size = file_size / num_processes;
    fclose(file);  // Close the main file after determining size

    ProcessResult aggregated_result = {0};
    WordFrequency global_words[MAX_WORDS];
    int global_word_count = 0;

    for (int i = 0; i < num_processes; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {  // Child process
            long start = i * segment_size;
            long end = (i == num_processes - 1) ? file_size : (i + 1) * segment_size;
            ProcessResult result;
            WordFrequency words[MAX_WORDS];
            int word_count = 0;
            process_file_section(filename, start, end, &result, words, &word_count, i);
            exit(0);  // End child process
        }
    }

    // Parent process waits for each child to finish
    for (int i = 0; i < num_processes; i++) {
        wait(NULL);
    }

    // Parent process reads results from each child file, displays them, and aggregates
    for (int i = 0; i < num_processes; i++) {
        char filename_result[30];
        snprintf(filename_result, sizeof(filename_result), "child_%d.txt", i);
        FILE *infile = fopen(filename_result, "r");
        if (infile) {
            ProcessResult result;
            fscanf(infile, "%d %d %d %d %d %d", &result.uppercase, &result.lowercase,
                   &result.numeric, &result.special, &result.spaces, &result.newlines);
            fclose(infile);
            // Display individual child results
            printf("\nResults from Child %d:\n", i);
            printf("Uppercase: %d\n", result.uppercase);
            printf("Lowercase: %d\n", result.lowercase);
            printf("Numeric: %d\n", result.numeric);
            printf("Special: %d\n", result.special);
            printf("Spaces: %d\n", result.spaces);
            printf("Newlines: %d\n", result.newlines);
            // Aggregate character counts
            aggregated_result.uppercase += result.uppercase;
            aggregated_result.lowercase += result.lowercase;
            aggregated_result.numeric += result.numeric;
            aggregated_result.special += result.special;
            aggregated_result.spaces += result.spaces;
            aggregated_result.newlines += result.newlines;
        } else {
            perror("Failed to open child result file");
            exit(1);
        }

        snprintf(filename_result, sizeof(filename_result), "child_%d_words.txt", i);
        infile = fopen(filename_result, "r");
        if (infile) {
            char word[MAX_WORD_LENGTH];
            int count;
            while (fscanf(infile, "%s %d", word, &count) == 2) {
                int found = 0;
                for (int j = 0; j < global_word_count; j++) {
                    if (strcmp(global_words[j].word, word) == 0) {
                        global_words[j].count += count;
                        found = 1;
                        break;
                    }
                }
                if (!found && global_word_count < MAX_WORDS) {
                    strcpy(global_words[global_word_count].word, word);
                    global_words[global_word_count++].count = count;
                }
            }
            fclose(infile);
        } else {
            perror("Failed to open child word result file");
            exit(1);
        }
    }

    // Display aggregated results
    printf("\nAggregated Results:\n");
    printf("Total Uppercase: %d\n", aggregated_result.uppercase);
    printf("Total Lowercase: %d\n", aggregated_result.lowercase);
    printf("Total Numeric: %d\n", aggregated_result.numeric);
    printf("Total Special: %d\n", aggregated_result.special);
    printf("Total Spaces: %d\n", aggregated_result.spaces);
    printf("Total Newlines: %d\n", aggregated_result.newlines);

    // Display word frequencies
    printf("\nAggregated Word Frequencies:\n");
    for (int i = 0; i < global_word_count; i++) {
        printf("%s: %d\n", global_words[i].word, global_words[i].count);
    }




    //THE CODE FROM HERE ONWARDS IS FOR SELF EVALUATION/////
    // Open output file to write the aggregated results
    FILE *output_file = fopen("output.txt", "w");
    if (output_file) {
        // Write aggregated character counts REPLACE WITH THE VARIABLES THAT HOLD COUNT IN YOUR CASE
        fprintf(output_file, "Character Counts:\n");
        fprintf(output_file, "Uppercase: %d\n", aggregated_result.uppercase);
        fprintf(output_file, "Lowercase: %d\n", aggregated_result.lowercase);
        fprintf(output_file, "Numeric: %d\n", aggregated_result.numeric);
        fprintf(output_file, "Special: %d\n", aggregated_result.special);
        fprintf(output_file, "Spaces: %d\n", aggregated_result.spaces);
        fprintf(output_file, "Newlines: %d\n\n", aggregated_result.newlines);

        // Write aggregated word frequencies
        fprintf(output_file, "Word Frequencies:\n");
        for (int i = 0; i < global_word_count; i++) {
            fprintf(output_file, "%s: %d\n", global_words[i].word, global_words[i].count);
        }

        fclose(output_file);
    } else {
        perror("Failed to open output file");
    }
    ///CODE BLOCK END// 
    return 0;
}
