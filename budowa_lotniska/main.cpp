#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> airport(1503, vector<bool>(1503, false));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x;
            cin >> x;
            airport[i][j] = (x == '.');
        }
    }

    int maxxFirst = 0, maxxSecond = 0, maxyFirst = 0, maxySecond = 0, ix, iy, xstart, ystart;

    for (int i = 1; i <= n; i++) {
        int curx = 0, cury = 0;
        for (int j = 1; j <= n; j++) {
            if (airport[i][j]) {
                curx++;
            } else {
                if (curx >= maxxFirst) {
                    maxxSecond = maxxFirst;
                    ix = i;
                    maxxFirst = curx;
                    xstart = j - maxxFirst;
                } else if (curx >= maxxSecond) {
                    maxxSecond = max(maxxSecond, curx);
                }
                curx = 0;
            }

            if (airport[j][i]) {
                cury++;
            } else {
                if (cury >= maxyFirst) {
                    maxySecond = maxyFirst;
                    iy = i;
                    maxyFirst = cury;
                    ystart = j - maxyFirst;
                } else if (cury >= maxySecond) {
                    maxySecond = max(maxySecond, cury);
                }
                cury = 0;
            }
        }

        if (curx >= maxxFirst) {
            maxxSecond = maxxFirst;
            ix = i;
            maxxFirst = curx;
            xstart = n - maxxFirst + 1;
        } else if (curx >= maxxSecond) {
            maxxSecond = max(maxxSecond, curx);
        }

        if (cury >= maxyFirst) {
            maxySecond = maxyFirst;
            iy = i;
            maxyFirst = cury;
            ystart = n - maxyFirst + 1;
        } else if (cury >= maxySecond) {
            maxySecond = max(maxySecond, cury);
        }
    }

    maxxSecond = max(maxxFirst / 2, maxxSecond);
    maxySecond = max(maxyFirst / 2, maxySecond);

    if (m == 1) {
        cout << max(maxxFirst, maxyFirst);
    } else if (maxxSecond >= maxyFirst) {
        cout << maxxSecond;
    } else if (maxySecond >= maxxFirst) {
        cout << maxySecond;
    } else {
        int mx = maxxFirst;
        int my = maxyFirst;

        for (int i = xstart; i < xstart + mx; i++) {
            int j = ix, curlength = 0;
            while (airport[j][i]) {
                j--;
            }
            j++;
            while (airport[j][i]) {
                curlength++;
                j++;
            }
            if (curlength > max(maxxSecond, maxySecond)) {
                maxxSecond = max(maxxSecond, i - xstart);
                maxxSecond = min(max(maxxSecond, xstart + mx - i - 1), my);
                if (curlength >= maxxFirst) {
                    maxxFirst = maxxSecond;
                }
            }
        }

        for (int i = ystart; i < ystart + my; i++) {
            int j = iy, curlength = 0;
            while (airport[i][j]) {
                j--;
            }
            j++;
            while (airport[i][j]) {
                curlength++;
                j++;
            }
            if (curlength > max(maxxSecond, maxySecond)) {
                maxySecond = max(maxySecond, i - ystart);
                maxySecond = min(max(maxySecond, ystart + my - i - 1), mx);
                if (curlength >= maxyFirst) {
                    maxyFirst = maxySecond;
                }
            }
        }

        cout << max(max(maxySecond, maxxSecond), min(maxxFirst, maxyFirst));
    }
    return 0;
}
