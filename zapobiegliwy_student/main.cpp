#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 500002;

struct Lecture {
    int start, end, index;
};

bool comp(const Lecture &a, const Lecture &b) {
    if (a.end == b.end) {
        return a.start > b.start;
    }
    return a.end < b.end;
}

vector<int> ans(MAXN);

int norm(vector<Lecture> lectures, int n) {
    int res = -1, last = 0, j = 0;
    for (int i = 0; i < n; i++) {
        if (lectures[i].start >= last) {
            last = lectures[i].end;
            res++;
            ans[j] = lectures[i].index;
            j++;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Lecture> lectures(MAXN);
    for (int i = 0; i < n; i++) {
        cin >> lectures[i].start >> lectures[i].end;
        lectures[i].index = i + 1;
    }
    sort(lectures.begin(), lectures.begin() + n, comp);

    vector<Lecture> good(MAXN);
    vector<Lecture> reserve(MAXN);
    good[0] = lectures[0];
    reserve[0] = lectures[1];

    int last1 = good[0].end, last2 = reserve[0].end, res = 1, j = 0;
    for (int i = 2; i < n; i++) {
        if (lectures[i].start >= last1) {
            if (lectures[i].start >= last2) {
                j++;
                good[j] = lectures[i];
                last1 = good[j - 1].end;
                i++;
                while (lectures[i].start < last1 && i != n) i++;
                if (i == n) break;
                reserve[j] = lectures[i];
                last2 = reserve[j].end;
                last1 = good[j].end;
                res++;
            } else {
                j++;
                reserve[j] = lectures[i];
                last1 = max(reserve[j - 1].end, good[j - 1].end);
                i++;
                while (lectures[i].start < last1 && i != n) i++;
                if (i == n) break;
                good[j] = lectures[i];
                last2 = good[j].end;
                last1 = good[j].end;
                res++;
            }
        }
    }
    int res1 = norm(lectures, n);
    if (res1 > res) {
        cout << res1 << "\n";
        for (int i = 1; i <= res1; i++) {
            cout << ans[i] << " " << ans[0] << "\n";
        }
    } else {
        cout << res << "\n";
        for (int i = 0; i < res; i++) {
            cout << good[i].index << " " << reserve[i].index << "\n";
        }
    }
}