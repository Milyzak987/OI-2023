#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 100000;
const int MAX_M = 500000;

int n, m;
vector<pair<int, int>> buttons;
vector<bool> active(MAX_M);

bool solve() {
    // Calculate the parity of rows and columns
    vector<int> rowParity(n + 1);
    vector<int> colParity(n + 1);

    for (const auto& [r, c] : buttons) {
        rowParity[r]++;
        colParity[c]++;
    }

    // Check if all rows and columns have the same parity
    int parity = rowParity[1];
    for (int i = 2; i <= n; ++i) {
        if (parity != rowParity[i]) {
            return false;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (parity != colParity[i]) {
            return false;
        }
    }

    // Find a valid solution
    int k = 0;
    vector<int> activatedButtons;

    for (int i = 1; i <= m; ++i) {
        if (active[i]) {
            continue;
        }

        // Check if activating this button maintains parity
        bool validRow = (k + 1) % 2 == parity;
        bool validCol = (k + 1) % 2 == parity;

        for (const auto& [r, c] : buttons) {
            if (r == buttons[i].first && !active[c]) {
                validRow = false;
                break;
            }

            if (c == buttons[i].second && !active[r]) {
                validCol = false;
                break;
            }
        }

        if (validRow && validCol) {
            active[i] = true;
            activatedButtons.push_back(i);
            k++;
        }
    }

    return true;
}

int main() {
    cin >> n >> m;

    buttons.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> buttons[i].first >> buttons[i].second;
    }

    if (!solve()) {
        cout << "NIE" << endl;
    } else {
        cout << "TAK" << endl;
        cout << k << endl;

        for (int i : activatedButtons) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}