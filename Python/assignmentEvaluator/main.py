import re

# Threshold for accuracy to be considered "perfect"
ACCURACY_THRESHOLD = 99.5  # Set to 99.5% to consider as 100%

def process_file_python(filename):
    # Initialize character counts
    char_counts = {
        "Uppercase": 0,
        "Lowercase": 0,
        "Numeric": 0,
        "Special": 0,
        "Spaces": 0,
        "Newlines": 0
    }
    word_freq = {}

    # Process the file for character counts and word frequencies
    with open(filename, 'r') as file:
        for line in file:
            for char in line:
                if char.isupper():
                    char_counts["Uppercase"] += 1
                elif char.islower():
                    char_counts["Lowercase"] += 1
                elif char.isdigit():
                    char_counts["Numeric"] += 1
                elif char == ' ':
                    char_counts["Spaces"] += 1
                elif char == '\n':
                    char_counts["Newlines"] += 1
                else:
                    char_counts["Special"] += 1

            # Word frequency calculation (case-insensitive)
            words = re.findall(r'\b\w+\b', line.lower())
            for word in words:
                word_freq[word] = word_freq.get(word, 0) + 1

    return char_counts, word_freq

def read_c_program_output(filename):
    c_char_counts = {}
    c_word_freq = {}

    with open(filename, 'r') as file:
        in_word_section = False
        for line in file:
            if line.startswith("Character Counts"):
                in_word_section = False
            elif line.startswith("Word Frequencies"):
                in_word_section = True
            elif not in_word_section:
                # Parse character counts
                if ':' in line:
                    key, value = line.split(':')
                    c_char_counts[key.strip()] = int(value.strip())
            else:
                # Parse word frequencies
                if ':' in line:
                    word, count = line.split(':')
                    c_word_freq[word.strip().lower()] = int(count.strip())  # Normalize to lowercase for comparison

    return c_char_counts, c_word_freq

def calculate_accuracy(py_counts, c_counts):
    total_keys = len(py_counts)
    correct_keys = sum(1 for key in py_counts if py_counts[key] == c_counts.get(key, 0))
    return (correct_keys / total_keys) * 100

def calculate_word_accuracy(py_words, c_words):
    total_words = len(py_words)
    correct_words = sum(1 for word in py_words if py_words[word] == c_words.get(word, 0))
    return (correct_words / total_words) * 100

def detailed_mismatch_report(py_counts, c_counts, entity_name):
    mismatches = []
    for key in py_counts:
        py_count = py_counts[key]
        c_count = c_counts.get(key, 0)
        if py_count != c_count:
            mismatches.append((key, py_count, c_count))
    if mismatches:
        print(f"\nDetailed {entity_name} Mismatches (Python Count vs. C Program Count):")
        for item, py_count, c_count in mismatches:
            print(f"{entity_name}: '{item}', Python Count: {py_count}, C Program Count: {c_count}")

# File paths
file_to_process = "file.txt"  # Replace with the name of the input file
c_output_file = "output.txt"

# Process the file with Python
python_char_counts, python_word_freq = process_file_python(file_to_process)

# Read the C program's output
c_char_counts, c_word_freq = read_c_program_output(c_output_file)

# Calculate accuracy
char_accuracy = calculate_accuracy(python_char_counts, c_char_counts)
word_accuracy = calculate_word_accuracy(python_word_freq, c_word_freq)

# Treat accuracy >= ACCURACY_THRESHOLD as 100%
final_word_accuracy = 100.0 if word_accuracy >= ACCURACY_THRESHOLD else word_accuracy

# Output accuracy results
print("Character Count Accuracy: {:.2f}%".format(char_accuracy))
print("Word Frequency Accuracy: {:.2f}%".format(final_word_accuracy))

# Detailed mismatch reports if actual accuracy is below ACCURACY_THRESHOLD
if char_accuracy < 100:
    detailed_mismatch_report(python_char_counts, c_char_counts, "Character")

if word_accuracy < ACCURACY_THRESHOLD:
    detailed_mismatch_report(python_word_freq, c_word_freq, "Word")
