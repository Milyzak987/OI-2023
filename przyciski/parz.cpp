#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(n, '#'));

    for (int i = 0; i < m; ++i) {
        int row, col;
        cin >> row >> col;
        board[row - 1][col - 1] = 'X';
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}