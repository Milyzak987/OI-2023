#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> buttons(m);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        buttons[i].first = a;
        buttons[i].second = b;
    }
    
    bool result = (even(n, buttons) || odd1(n, buttons) || odd(n, buttons));
    if (result) {
        cout << "TAK";
    } else {
        cout << "NIE";
    }

    return 0;
}
