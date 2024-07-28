#include "FindSchedule.hpp"
#include <climits>

void printVectorOfJobs(const vector<Job>& jobs) {
    for (const auto& job : jobs) {
        cout << "#" << job.j << " u_j: " << job.u_j << ", v_j: " << job.v_j << ", LD_j: " << job.LD_j << endl;
    }
}

int calculateFinishTime(const vector<Job>& jobs) {
    int time = 0;
    for (const auto &job : jobs) {
        int processTime;
        if (job.LD_j > time) processTime = job.u_j;
        else processTime = job.v_j;
        time += processTime;
    }
    return time;
}

pair<vector<Job>, int> findBestSchedule(const vector<Job>& jobs) {

    // for current permutation
    std::vector<int> indices(jobs.size());
    for (int i = 0; i < indices.size(); ++i) {
        indices[i] = i;
    }

    // save the best schedule found
    int minFinishTime = INT_MAX;
    std::vector<Job> bestSchedule;

    // go over all permutations
    do {
        // set schedule by permotation
        std::vector<Job> currentSchedule;
        for (int i : indices) {
            currentSchedule.push_back(jobs[i]);
        }

        int finishTime = calculateFinishTime(currentSchedule);

        if (finishTime < minFinishTime) {
            minFinishTime = finishTime;
            bestSchedule = currentSchedule;
        }
    } while (std::next_permutation(indices.begin(), indices.end()));

    return pair<vector<Job>, int>{bestSchedule, minFinishTime};
}

void printSchedule(const vector<Job>& schedule) {
    int currentTime = 0;
    cout << endl << "Schedule:" << endl;
    for (const auto& job : schedule) {
        cout << "Job " << job.j << ", took: ";

        int timeTook;
        if (job.LD_j > currentTime) timeTook = job.u_j; // took basic time
        else timeTook = job.v_j; // took improved time

        cout << timeTook << endl;
        currentTime += timeTook;
    }
}