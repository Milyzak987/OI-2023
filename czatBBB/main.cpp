#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

const int p = 31; // wartość pierwsza dla hashy
const int m = 1e9 + 9; // modulo

// Funkcja do obliczania hashy dla słowa
vector<long long> computeHash(const string& s) {
    int n = s.length();
    vector<long long> hash(n + 1, 0);
    vector<long long> power(n + 1, 0);
    power[0] = 1;

    for (int i = 0; i < n; ++i) {
        hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * power[i]) % m;
        power[i + 1] = (power[i] * p) % m;
    }

    return hash;
}

// Funkcja do obliczania hasha dla danego przedziału [l, r] w słowie s
long long getHash(const vector<long long>& hash, const vector<long long>& power, int l, int r) {
    return (hash[r + 1] - hash[l] + m) % m * power[hash.size() - l - 1] % m;
}

int main() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    string s;
    cin >> s;

    vector<long long> hashes = computeHash(s);

    unordered_map<long long, char> mostFrequentLetter;

    // Szukanie sufiksów i zliczanie liter
    for (int i = n - k; i < n; ++i) {
        long long sufHash = getHash(hashes, hashes, i - k + 1, i);
        char nextChar = (i == n - 1) ? 'a' : s[i + 1];

        if (mostFrequentLetter.find(sufHash) == mostFrequentLetter.end() || mostFrequentLetter[sufHash] <= nextChar) {
            mostFrequentLetter[sufHash] = nextChar;
        }
    }

    // Rozszerzenie słowa S′
    string extendedWord = s;
    for (int i = 0; i < b - n + 1; ++i) {
        long long sufHash = getHash(hashes, hashes, extendedWord.length() - k, extendedWord.length() - 1);
        extendedWord += mostFrequentLetter[sufHash];
    }

    // Wypisanie literek na odpowiednich pozycjach
    for (int i = a - 1; i <= b - 1; ++i) {
        cout << extendedWord[i];
    }
    cout << endl;

    return 0;
}