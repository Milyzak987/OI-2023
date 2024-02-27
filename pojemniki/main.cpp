#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cont {
    int m;
    int num1;
    long long vol1;
    int num2;
    long long vol2;
};

const int MAXN = 1e6 + 7;
vector<long long> volume(MAXN);
priority_queue<pair<long long, int>, vector<pair<long long, int>>,
               greater<pair<long long, int>>>
    substance;
priority_queue<pair<long long, int>> substance_big;
vector<cont> answer(MAXN);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long k;
    cin >> n >> k;
    fill(volume.begin(), volume.begin() + n + 1, k);

    long long volsum = 0;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        volsum += x;
        if (x <= k) {
            substance.push({x, i});
        } else {
            substance_big.push({x, i});
        }
    }

    long long maxvol = (long long)n * k;
    if (volsum > maxvol) {
        cout << "NIE";
        return 0;
    }

    int z = 1;
    while (!substance.empty()) {
        volume[z] -= substance.top().first;
        answer[z].m++;
        answer[z].num1 = substance.top().second;
        answer[z].vol1 = substance.top().first;
        substance.pop();
        z++;
    }

    int j = 1;
    while (!substance_big.empty()) {
        if (j > n) {
            j = 1;
        }
        if (substance_big.top().first > volume[j] && volume[j] != 0) {
            answer[j].m++;
            if (answer[j].m == 2) {
                answer[j].num2 = substance_big.top().second;
                answer[j].vol2 = volume[j];
            } else {
                answer[j].num1 = substance_big.top().second;
                answer[j].vol1 = volume[j];
            }
            pair<long long, int> dif = {substance_big.top().first - volume[j],
                                        substance_big.top().second};
            substance_big.pop();
            substance_big.push(dif);
            volume[j] = 0;
        } else if (volume[j] != 0) {
            answer[j].m++;
            if (answer[j].m == 2) {
                answer[j].num2 = substance_big.top().second;
                answer[j].vol2 = substance_big.top().first;
            } else {
                answer[j].num1 = substance_big.top().second;
                answer[j].vol1 = substance_big.top().first;
            }
            substance_big.pop();
        }
        j++;
    }

    cout << "TAK\n";
    // for (int i = 1; i <= n; i++) {
    //     cout << answer[i].m;
    //     if (answer[i].m == 1) {
    //         cout << " " << answer[i].num1 << " " << answer[i].vol1 << "\n";
    //     }
    //     if (answer[i].m == 2) {
    //         cout << " " << answer[i].num1 << " " << answer[i].vol1 << " "
    //              << answer[i].num2 << " " << answer[i].vol2 << "\n";
    //     }
    // }
}