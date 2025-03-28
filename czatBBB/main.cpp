#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

<<<<<<< HEAD
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
=======
vector<int> v(5000, 0);

bool odd(int n, const vector<pair<int, int>>& buttons) {
    vector<int> rows(n, 0), cols(n, 0);

    for (const auto& button : buttons) {
        int r = button.first - 1;
        int c = button.second - 1;
        rows[r]++;
        cols[c]++;
    }

    sort(rows.begin(), rows.end());
    sort(cols.begin(), cols.end());

    if (rows[0] == 0 || rows[n - 1] == n || cols[0] == 0 || cols[n - 1] == n) {
        return false;
    }

    return true;
}

bool odd1(int n, const vector<pair<int, int>>& buttons) {
    unordered_set<int> rows, cols;

    for (const auto& button : buttons) {
        rows.insert(button.first);
        cols.insert(button.second);
    }

    return rows.size() == n && cols.size() == n;
}

bool even(int n, const vector<pair<int, int>>& buttons) {
    unordered_map<int, vector<int>> rows, cols;
    for (const auto& button : buttons) {
        rows[button.first].push_back(button.second);
        cols[button.second].push_back(button.first);
    }

    for (const auto& row : rows) {
        const vector<int>& colsInRow = row.second;
        for (size_t i = 0; i < colsInRow.size(); ++i) {
            for (size_t j = i + 1; j < colsInRow.size(); ++j) {
                int col1 = colsInRow[i], col2 = colsInRow[j];
                for (const int& otherRow : cols[col1]) {
                    if (otherRow != row.first) {
                        auto it = find(cols[col2].begin(), cols[col2].end(), otherRow);
                        if (it != cols[col2].end()) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] += a;
        v[i + 1] += a;
    }
    cout << n;
    for (int i = 0; i <= n; i++) {
        cout << v[i] << " ";
    }
>>>>>>> 4a807d888a1340dc2cbfa2fb769ffdb8a7b62207
}