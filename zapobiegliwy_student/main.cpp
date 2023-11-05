#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool sort1(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

bool sort2(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int check(vector<pair<int, int>> intv, int n){
    vector<pair<int, int>> good(500002);
    good[0] = make_pair(0, 0);
    int res1 = 0, res2 = 0, last = 0, left = 0, right = intv[0].first, j = 0, minend = 500002;
    for (int i = 0; i <= n; i++) {
        if (intv[i].first >= last) {
            last = intv[i].second;
            res1++;
            j++;
            good[j] = intv[i];
            if (minend <= intv[i].first) {
                res2++;
            }
            minend = 500002;
            left = good[j - 1].second;
        } else if (intv[i].first >= left)
            minend = min(intv[i].second, minend);
    }
    return max(res1 - 2, res2);
}

vector<pair<int, int>> intv(500002, pair<int, int>(500001, 500001));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> intv[i].first >> intv[i].second;
    }
    sort(intv.begin(), intv.begin() + n, sort1);
    int res1 = check(intv, n);
    sort(intv.begin(), intv.begin() + n, sort2);
    int res2 = check(intv, n);

    cout << max(res1, res2);

    return 0;
}