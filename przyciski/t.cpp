#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> rows, cols;

    for (int i = 1; i <= m; ++i) {
        int r, c;
        cin >> r >> c;
        rows[r].push_back(i);
        cols[c].push_back(i);
    }

    for (const auto& row : rows) {
        if (row.second.size() >= 4) {
            for (const auto& col : cols) {
                if (col.second.size() >= 4) {
                    unordered_map<int, int> dotCount;

                    for (int dot : row.second) {
                        dotCount[dot]++;
                    }

                    for (int dot : col.second) {
                        if (dotCount[dot] > 0) {
                            dotCount[dot]--;
                            if (dotCount[dot] >= 3) {
                                cout << "YES\n";
                                cout << row.second[0] << " " << row.second[1] << " " << row.second[2] << " " << dot << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}
