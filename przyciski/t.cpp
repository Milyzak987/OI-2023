#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool isRectanglePossible(int n, const vector<pair<int, int>>& dots) {
    vector<set<int>> rows(n + 1), cols(n + 1);

    // Store dots' coordinates based on rows and columns
    for (const auto& dot : dots) {
        int x = dot.first, y = dot.second;
        rows[x].insert(y);
        cols[y].insert(x);
    }

    // Iterate through all pairs of dots to check for a possible rectangle
    for (const auto& dot : dots) {
        int x = dot.first, y = dot.second;

        for (int y2 : rows[x]) {
            if (y2 != y) {
                for (int x2 : cols[y]) {
                    if (x2 != x && cols[y2].count(x2) > 0) {
                        return true; // Rectangle found
                    }
                }
            }
        }
    }

    return false; // No rectangle found
}

int main() {
    int n;
    cout << "Enter the size of the board (n x n): ";
    cin >> n;

    int numDots;
    cout << "Enter the number of dots: ";
    cin >> numDots;

    vector<pair<int, int>> dots;
    cout << "Enter the column and row of each dot:" << endl;
    for (int i = 0; i < numDots; ++i) {
        int x, y;
        cin >> x >> y;
        dots.emplace_back(x, y);
    }

    bool possible = isRectanglePossible(n, dots);
    if (possible) {
        cout << "It's possible to create a rectangle using the given dots." << endl;
    } else {
        cout << "It's not possible to create a rectangle using the given dots." << endl;
    }

    return 0;
}
