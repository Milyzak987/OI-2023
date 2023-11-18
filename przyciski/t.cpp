#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MAXM = 500007;
vector<pair<int, int>> buttons(MAXM);

bool isRectangle(vector<pair<int, int>>& points) {
    unordered_map<int, unordered_set<int>> rows;
    for (auto& point : points) {
        for (auto& x : rows[point.second]) {
            if (x != point.first && rows[x].count(point.first)) {
                return true;
            }
        }
        rows[point.second].insert(point.first);
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

    bool result = isRectangle(buttons);

    if (result) {
        cout << "TAK";
    } else {
        cout << "NIE";
    }

    return 0;
}
