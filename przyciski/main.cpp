#include <iostream>
#include <vector>

using namespace std;

bool isRectanglePossible(int n, vector<pair<int, int>> buttons) {
    vector<vector<int>> rows, cols;

    for (auto b : buttons) {
        rows[b.first].push_back(b.second);
        cols[b.second].push_back(b.first);
    }

    for (auto dot : buttons) {
        int x = dot.first, y = dot.second;

        for (int y2 : rows[x]) {
            if (y2 != y) {
                for (int x2 : cols[y]) {
                    if (x2 != x) {
                        for (int y3 : rows[x2]) {
                            if (y3 != y2 && y3 != y && cols[y3].size() > 1) {
                                for (int x3 : cols[y3]) {
                                    if (x3 != x2 && x3 != x && rows[x3].size() > 1) {
                                        return true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return false; // No rectangle found
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

    if(isRectanglePossible(n, buttons)) cout << "TAK";
    else cout << "NIE";
    
    return 0;
}
