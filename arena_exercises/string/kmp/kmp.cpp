// ref: https://www.geeksforgeeks.org/dsa/kmp-algorithm-for-pattern-searching/
#include <iostream>

using namespace std;

int main() {
    string s, pat;
    int n, m;
    cin >> n >> s >> m >> pat;

    // create LPS (Longest Prefix Suffix) table
    // O(m)
    int lps[m];
    lps[0] = 0;
    int len = 0; // prefix end pointer
    for (int i = 1; i < m;) { // i: suffix end pointer
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else if (len != 0) // maybe there is a smaller prefix that matches current suffix
            len = lps[len - 1]; // fallback to the longest prefix of the previous matched suffix prefix
        else
            lps[i++] = 0;
    }

    // compare pattern to main string
    // O(n)
    int i = 0;
    int j = 0;
    int ans = 0; // number of matching patterns
    while (i < n) {
        if (s[i] == pat[j]) {
            i++;
            j++;

            if (j == m) {
                ans++;
                j = lps[j - 1];
            }
        } else if (j != 0) j = lps[j - 1];
        else i++;
    }

    cout << ans << endl;

    // O(n + m)

    return 0;
}