#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;
const int BASE = 131;

long long pow_mod(int base, int exp) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    string S;
    cin >> S;

    vector<long long> power(n + 1);
    power[0] = 1;
    for (int i = 1; i <= n; ++i) {
        power[i] = (power[i - 1] * BASE) % MOD;
    }

    unordered_map<long long, int> occurrences;
    long long hash_value = 0;
    for (int i = 0; i < n; ++i) {
        hash_value = (hash_value * BASE + S[i]) % MOD;
    }

    occurrences[hash_value]++;
    char most_common = S[n - k - 1];

    for (int i = n; i < b; ++i) {
        char new_char = most_common;

        hash_value = (hash_value * BASE + new_char) % MOD;
        hash_value = (hash_value - (power[n] * S[i - n]) % MOD + MOD) % MOD;
        S.push_back(new_char);

        if (occurrences.find(hash_value) != occurrences.end()) {
            int count = occurrences[hash_value];
            if (new_char == most_common || count > occurrences[most_common]) {
                most_common = new_char;
            }
        } else {
            most_common = 'a';
        }

        occurrences[hash_value]++;
    }

    for (int i = a - 1; i < b; ++i) {
        cout << S[i];
    }
    cout << endl;

    return 0;
}
