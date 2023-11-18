#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int MAXM = 500007;
vector<pair<int, int>> buttons(MAXM);

bool doesRectangleExist(int n) {
    unordered_map<int, unordered_set<int>> rows;
    unordered_map<int, unordered_set<int>> cols;

    for (auto point : buttons) {
        int x = point.first;
        int y = point.second;
        rows[x].insert(y);
        cols[y].insert(x);
    }

    for (auto row : rows) {
        if (row.second.size() >= 2) {
            for (int col1 : row.second) {
                for (int col2 : row.second) {
                    if (col1 != col2 && cols[col1].count(col2) && cols[col2].count(col1)) {
                        return true;
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