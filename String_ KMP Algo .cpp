#include <bits/stdc++.h>
using namespace std;

void LPSArray(string& pattern, vector<int>& lps) {
    int m = pattern.size();
    int length = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<int> search(string pat, string text) {
    int m = pat.length();
    int n = text.length();
    vector<int> ans;
    vector<int> lps(m, 0);
    LPSArray(pat, lps);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pat[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            ans.push_back(i - j + 1);
            j = lps[j - 1];
        } else if (i < n && pat[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return ans;
}

int main() {
    
    string text, pattern;
    cin >> text;
    cin >> pattern;

    vector<int> positions = search(pattern, text);
    for (int pos : positions) {
        cout << pos << " ";
    }
    cout << "\n";
}
