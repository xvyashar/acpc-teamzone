// problem: https://quera.org/problemset/34082
#include <iostream>

using namespace std;

int main() {
    // get inputs
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // count possible groups
    int cg = a[0], g_s = 1;
    for (int i = 1; i < n; i++) {
        if (cg + a[i] <= k) cg += a[i];
        else {
            g_s++;
            cg = a[i];
        }
    }

    // print groups
    cout << g_s << endl;

    return 0;
}