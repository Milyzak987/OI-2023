#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

<<<<<<< HEAD
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

=======
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

>>>>>>> 4a807d888a1340dc2cbfa2fb769ffdb8a7b62207
int main() {
    cin >> n >> m;
<<<<<<< HEAD

    buttons.resize(m);
=======
    vector<pair<int, int>> buttons(m);
>>>>>>> 4a807d888a1340dc2cbfa2fb769ffdb8a7b62207
    for (int i = 0; i < m; ++i) {
        cin >> buttons[i].first >> buttons[i].second;
    }
<<<<<<< HEAD

    if (!solve()) {
        cout << "NIE" << endl;
=======
    
    bool result = (even(n, buttons) || odd1(n, buttons) || odd(n, buttons));
    if (result) {
        cout << "TAK";
>>>>>>> 4a807d888a1340dc2cbfa2fb769ffdb8a7b62207
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