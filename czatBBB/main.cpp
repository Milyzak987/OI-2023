#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;
const int BASE = 131;

vector<long long> powers;
vector<long long> prefixHashes;

void precomputePowers(int n) {
    powers.resize(n + 1);
    powers[0] = 1;
    for (int i = 1; i <= n; ++i) {
        powers[i] = (powers[i - 1] * BASE) % MOD;
    }
}

void computePrefixHashes(const string& S) {
    int n = S.length();
    prefixHashes.resize(n + 1);
    prefixHashes[0] = 0;
    for (int i = 0; i < n; ++i) {
        prefixHashes[i + 1] = (prefixHashes[i] * BASE + (S[i] - 'a' + 1)) % MOD;
    }
}

long long getSubstringHash(int left, int right) {
    return (prefixHashes[right + 1] - (prefixHashes[left] * powers[right - left + 1]) % MOD + MOD) % MOD;
}

char findMostFrequentChar(const string& S, int k) {
    unordered_map<long long, vector<char>> suffixCounts;
    long long hashR = getSubstringHash(S.length() - k, S.length() - 1);

    for (int i = 0; i + k < S.length(); ++i) {
        long long curHash = getSubstringHash(i, i + k - 1);
        char nextChar = S[i + k];
        suffixCounts[curHash].push_back(nextChar);
    }

    if (suffixCounts.find(hashR) == suffixCounts.end()) {
        return 'a'; // Jeśli R nie wystąpiło nigdzie indziej, przyjmujemy c = a
    }

    const vector<char>& charsAfterR = suffixCounts[hashR];
    unordered_map<char, int> charCount;

    int maxCount = 0;
    char mostFrequentChar = 'a';

    for (char c : charsAfterR) {
        charCount[c]++;
        if (charCount[c] > maxCount || (charCount[c] == maxCount && c < mostFrequentChar)) {
            maxCount = charCount[c];
            mostFrequentChar = c;
        }
    }

    return mostFrequentChar;
}

int main() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    string S;
    cin >> S;

    precomputePowers(max(n, k));

    computePrefixHashes(S);

    string extendedWord = S;
    for (int i = n; i <= b; ++i) {
        char mostFrequentChar = findMostFrequentChar(extendedWord, k);
        extendedWord += mostFrequentChar;
    }

    cout << extendedWord.substr(a - 1, b - a + 1) << endl;

    return 0;
}
