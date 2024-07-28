#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Represents a job
* u_j: Basic processing time
* v_j: Improved processing time
* LD_j: The learning-date
*/
struct Job
{
    int j;
    int u_j;
    int v_j;
    int LD_j;
};

// printing a vector of jobs with al their parameter
void printVectorOfJobs(const vector<Job>& jobs);

// gets vector of jobs in a certain order and calculate the finish time
int calculateFinishTime(const vector<Job>& jobs);

// finds all the permutation of order and cheks which one is the shortest
// return the schedule and its working time
pair<vector<Job>, int> findBestSchedule(const vector<Job>& jobs);

// print a given schedule
void printSchedule(const vector<Job>& schedule);