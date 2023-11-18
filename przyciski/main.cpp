#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXM = 500007;
vector<pair<int, int>> buttons(MAXM);

bool doesRectangleExist(int n) {
    vector<vector<int>> rows(n + 1); // Vector to store columns for each row
    vector<vector<int>> cols(n + 1); // Vector to store rows for each column

    for (int i = 0; i < buttons.size(); ++i) {
        int x = buttons[i].first;
        int y = buttons[i].second;
        rows[x].push_back(y); // Store y-coordinate in x-th row
        cols[y].push_back(x); // Store x-coordinate in y-th column
    }

    for (int i = 1; i <= n; ++i) {
        if (rows[i].size() >= 2) {
            for (int j = 0; j < rows[i].size(); ++j) {
                for (int k = j + 1; k < rows[i].size(); ++k) {
                    int col1 = rows[i][j];
                    int col2 = rows[i][k];
                    if (cols[col1].size() >= 2 && cols[col2].size() >= 2) {
                        for (int r1 : cols[col1]) {
                            for (int r2 : cols[col2]) {
                                if (r1 != r2 && find(rows[r1].begin(), rows[r1].end(), col2) != rows[r1].end() && find(rows[r2].begin(), rows[r2].end(), col1) != rows[r2].end()) {
                                    return true;
                                }
                            }
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

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        buttons[i].first = a;
        buttons[i].second = b;
    }
    bool result = doesRectangleExist(n);

    if (result) {
        cout << "TAK";
    } else {
        cout << "NIE";
    }

    return 0;
}
