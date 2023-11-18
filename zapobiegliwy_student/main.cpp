#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct lecture {
    int start, end, index, indexReserve;
};

bool sortbyend(const lecture& a, const lecture& b) {
    return a.end < b.end;
}

bool comperator(const lecture& a, const lecture& b) {
    if (a.start == b.start) {
        return a.end > b.end;
    }
    return a.start < b.start;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m = 0;
    cin >> n;

    vector<lecture> intv(n); // Use a vector of lectures instead of arrays
    vector<lecture> safeIntv;
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++) {
        cin >> intv[i].start >> intv[i].end;
        intv[i].index = i + 1;
    }

    sort(intv.begin(), intv.end(), comperator);

    for (int i = 0; i < n - 1; i++) { // Fix the loop condition
        if (intv[i + 1].end <= intv[i].end) {
            intv[i].indexReserve = intv[i + 1].index;
            safeIntv.push_back(intv[i]);
            m++;
        }
    }

    sort(safeIntv.begin(), safeIntv.end(), sortbyend);

    int res = 0, last = 0;
    for (int i = 0; i < m; i++) {
        if (safeIntv[i].start >= last) {
            last = safeIntv[i].end;
            res++;
            ans.push_back(make_pair(safeIntv[i].index, safeIntv[i].indexReserve));
        }
    }

    cout << res << "\n";
    for (int i = 0; i < res; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}
