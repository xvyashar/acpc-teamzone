// problem: https://quera.org/problemset/10936
#include <iostream>

using namespace std;

int main() {
    // get inputs
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // find best number sequence
    int cs = 1, bs = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - 1 == a[i - 1]) cs++;
        else if (cs != 1) {
            if (cs > bs) bs = cs;
            cs = 1;
        }
    }

    // print answer
    std::cout << min(bs + k, n) << std::endl;

    return 0;
}