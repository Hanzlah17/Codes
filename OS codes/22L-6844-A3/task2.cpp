#include <iostream>

#include <list>

#include <vector>

using namespace std;

int jobid=0;

struct Job 

{

    int id;

    int length;



    Job(int job_id, int job_length) : id(job_id), length(job_length) {}

};



bool compareJobs(const Job& a, const Job& b)

{

    if (a.length == b.length) 

    {

        return a.id < b.id; //same lengths then make decisions based on ids

    }

    return a.length < b.length;

}



class PriorityQueue

{

private:

    list<Job> jobList;

    int totalJobs;



    void sort() 

    {

        jobList.sort(compareJobs);

    }



public:

    PriorityQueue() : totalJobs(0) {}



    

    void enqueue(int length)

    {

    	jobid++;

        Job newJob(jobid, length);

        jobList.push_back(newJob);

        totalJobs++;

        sort();

    }



    Job dequeue() 

    {

        Job temp = jobList.front();

        jobList.pop_front();

        totalJobs--;

        return temp;

    }

    bool empty()

    {

        return (totalJobs == 0);

    }

    int size()

    {

        return totalJobs;

    }

    void AddMultilpleJobs(const vector<int>& jobs)

    {

        int size = jobs.size();

        for (int i = 0;i < size;i++)

        {

            enqueue(jobs[i]);

        }

    }

};



void simulateSJF(const vector<int>& jobs)

{

    cout << "Simulation of Shortest Job First (SJF) Scheduling Algorithm\n";

    cout << "Jobs:\n";

    int size = jobs.size();

    for (int i = 0;i < size;i++)

    {

        cout << "Job " << i+1 << ": Length = " << jobs[i] << " units\n";

    }



    cout << "\n-- Starting SJF Scheduling Simulation --\n";



    PriorityQueue pq;

    pq.AddMultilpleJobs(jobs);

    int totalJobs = pq.size();

    vector<int> tempJobs(totalJobs);

    for (int i = 0; i < totalJobs; i++) 

    {

        Job job = pq.dequeue();

        cout << "Processing Job " << job.id << " (Length = " << job.length << " units)\n";

        tempJobs[i] = job.id;

    }



    cout << "\n-- SJF Scheduling Simulation Complete --\n";

    cout << "\n-- Job Processing Order: --\n";

    for (int i = 0; i < totalJobs; i++)

    {

        cout << "JOB " << tempJobs[i] << "-> ";

    }

    cout << endl << endl;

}



int main()

{

    vector<int> jobs = {4,1,2,5,5,6};



    simulateSJF(jobs);



    return 0;

}

