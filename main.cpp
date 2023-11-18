// #include <algorithm>
// #include <iostream>
// #include <vector>
// using namespace std;

// struct lecture {
//     int first, second, index, indexReserve;
// };

// bool sortbysecond(lecture &a, lecture &b) {
//     return (a.second < b.second);
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m = 0;
//     cin >> n;

//     vector<lecture> intv(n);

//     for (int i = 0; i < n; i++) {
//         cin >> intv[i].first >> intv[i].second;
//         intv[i].index = i + 1;
//     }
//     sort(intv.begin(), intv.begin() + n, sortbysecond);

//     int res1 = 1, res2 = 0, last = 0, maxsecond = intv[1].second;
//     for (int i = 0; i < n; i++) {
//         if (intv[i].first >= last) {
//             res2++;
//             if (maxsecond <= intv[i].first) {
//                 last = intv[i].second;
//                 maxsecond = (i + 1 < n) ? intv[i + 1].second : n;
//                 res1++;
//             }
//         }
//     }
//     cout << max(res1, res2 - 1);

//     return 0;
// }

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool sortbysec(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

vector<pair<int, int>> intv(500002);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if(n==1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cin >> intv[i].first >> intv[i].second;
    }
    sort(intv.begin(), intv.begin() + n, sortbysec);

    int res = 0, last1 = 0, last2 = 0, maxsecond = 0, res1 = 0;
    for (int i = 0; i < n; i++) {
        if (intv[i].first >= last1) {
            last1 = intv[i].second;
            res++;
        }
        if (maxsecond <= intv[i].first && intv[i].first >= last2 && intv[i] != intv[i+1]) {
            last2 = intv[i].second;
            maxsecond = (i + 1 < n) ? intv[i + 1].second : n;
            res1++;
        }
    }
    cout << max(res - 1, res1);

    return 0;
}