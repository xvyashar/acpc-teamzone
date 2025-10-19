// problem: https://www.geeksforgeeks.org/dsa/job-sequencing-problem/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // get inputs
    int n;
    cin >> n;
    int d[n];
    for (int i = 0; i < n; i++)
        cin >> d[i];
    int p[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    // make a unit of jobs
    pair<int, int> j[n];
    for (int i = 0; i < n; i++)
        j[i] = {p[i], d[i]};

    // sort in desc by profit first
    sort(j, j + n, greater());

    // get the job that has the latest deadline
    int maxD = 0;
    for (int i = 0; i < n; i++) {
        if (j[i].second > maxD) maxD = j[i].second;
    }

    // track our days
    bool days[maxD];
    fill(days, days + maxD, false);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int pp = j[i].first;
        int dd = j[i].second;

        if (!days[dd - 1]) {
            ans += pp;
            days[dd - 1] = true;
        } else if (dd != 1) {
            for (int ii = dd - 1; ii > 0; ii--) {
                if (!days[ii - 1]) {
                    ans += pp;
                    days[ii - 1] = true;
                    break;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}