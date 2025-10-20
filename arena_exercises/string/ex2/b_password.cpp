// problem: https://codeforces.com/problemset/problem/126/B
#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    size_t n = s.size();
    string fR = "Just a legend";

    // create LPS (Longest Prefix Suffix) table
    // O(m)
    int lps[n];
    lps[0] = 0;
    int len = 0; // prefix end pointer
    for (size_t i = 1; i < n;) { // i: suffix end pointer
        if (s[i] == s[len])
            lps[i++] = ++len;
        else if (len != 0) // maybe there is a smaller prefix that matches current suffix
            len = lps[len - 1]; // fallback to the longest prefix of the previous matched suffix prefix
        else
            lps[i++] = 0;
    }

    if (lps[n-1] == 0) {
        cout << fR << endl;
        return 0;
    }

    int cLen = lps[n - 1];
    for (size_t i = 0; i < n - 1; i++) {
        if (lps[i] == cLen) {
            cout << s.substr(0, lps[i]) << endl;
            return 0;
        }

        if (i == n - 2 && cLen != 0) {
            cLen = lps[cLen - 1];
            if (cLen != 0) i = 0;
        }
    }

    cout << fR << endl;

    return 0;
}