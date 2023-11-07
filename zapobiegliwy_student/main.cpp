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

int norm(vector<pair<int, int>> intv, int n) {
    int res = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (intv[i].first >= last) {
            last = intv[i].second;
            res++;
        }
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> lectures(500002);
    for (int i = 0; i < n; i++) {
        cin >> lectures[i].first >> lectures[i].second;
    }
    if (n == 1) {
        cout << 0;
        return 0;
    }
    sort(lectures.begin(), lectures.begin() + n, sort1);

    vector<pair<int, int>> good(500002);
    vector<pair<int, int>> reserve(500002);
    good[0] = lectures[0];
    reserve[0] = lectures[1];

    int last1 = good[0].second, last2 = reserve[0].second, res = 1, j = 0;
    for (int i = 2; i < n; i++) {
        if (lectures[i].first >= last1) {
            if (lectures[i].first >= last2) {
                j++;
                good[j] = lectures[i];
                last1 = good[j - 1].second;
                i++;
                while (lectures[i].first < last1 && i != n) i++;
                if (i == n) break;
                reserve[j] = lectures[i];
                last2 = reserve[j].second;
                last1 = good[j].second;
                res++;
            } else {
                j++;
                reserve[j] = lectures[i];
                last1 = max(reserve[j - 1].second, good[j - 1].second);
                i++;
                while (lectures[i].first < last1 && i != n) i++;
                if (i == n) break;
                good[j] = lectures[i];
                last2 = good[j].second;
                last1 = good[j].second;
                res++;
            }
        }
    }
    int res1 = norm(lectures, n);
    cout << max(res, res1 - 1);
}