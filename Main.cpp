#include "FindSchedule.hpp"

using namespace std;

int main() {
    vector<Job> vec;

    int choice;
    cout << "How would you like to add items? (1 - manulay, 2 - using existing list) ";
    cin >> choice;
    if (choice == 1) {
        int counter = 1;
        while (true) {
            int u_j, v_j, LD_j;
            cout << "#" << counter << ":" << endl;
            cout << "u_j: ";
            cin >> u_j;
            cout << "v_j: ";
            cin >> v_j;
            cout << "LD_j: ";
            cin >> LD_j;

            vec.push_back({counter, u_j, v_j, LD_j});

            cout << "add another?(1 - yes, 0 - no) ";
            cin >> choice;
            if (choice) counter++;
            else break;
        }
    } else {
        vec = {
            {1, 31, 11, 130},
            {2, 33, 21, 132},
            {3, 33, 18, 135},
            {4, 47, 15, 137},
            {5, 30, 6, 147},
            {6, 47, 19, 155},
            {7, 29, 4, 176},
            {8, 32, 4, 176}
        };
    }

    cout << endl << "Jobs:" << endl;
    printVectorOfJobs(vec);

    pair<vector<Job>, int> best = findBestSchedule(vec);
    cout << endl << "best time: " << best.second << endl;
    printSchedule(best.first);
}