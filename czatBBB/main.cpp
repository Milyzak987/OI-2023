#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k;
    long long a, b;
    cin >> n >> k >> a >> b;
    string s;
    cin >> s;

    vector<int> suffix_counts(26, 0);

    for (int i = 0; i < k; i++) {
        suffix_counts[s[i] - 'a']++;
    }

    string result;
    for (int i = 0; i < b - n; i++) {
        string suffix = s.substr(i, k);
        int max_count = 0;
        char most_common = 'a';

        for (int j = 0; j < 26; j++) {
            if (suffix_counts[j] > max_count) {
                max_count = suffix_counts[j];
                most_common = 'a' + j;
            }
        }

        result += most_common;
        suffix_counts[s[i + 1] - 'a']++;
    }

    cout << result << endl;

    return 0;
}
