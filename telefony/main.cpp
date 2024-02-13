#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

const int MAXN = 5e5 + 7;
vector<int> phones[MAXN];
vector<int> ppl(MAXN);
vector<int> val(MAXN);
vector<int> cities[MAXN];
vector<int> cities2[MAXN];
vector<unordered_set<int>> graph(MAXN);
vector<unordered_set<int>> graph2(MAXN);
vector<bool> visited(MAXN, false);

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        bool b1 = true;
        for (int j = 0; j < t; j++) {
            int x;
            cin >> x;
            if (x > i && b1) {
                phones[i].push_back(i);
                b1 = false;
            }
            phones[i].push_back(x);
        }
        if (b1) phones[i].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> k = phones[i];
            cities[i].push_back(i);
            visited[i] = true;
            for (int j = 1; j <= n; j++) {
                if (phones[j] == k && !visited[j]) {
                    cities[i].push_back(j);
                    visited[j] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (cities[i].size() != 0) {
            for (auto x : phones[cities[i][0]]) {
                if (cities[x].size() != 0 && cities[x] != cities[i]) {
                    cout << x << " - " << i << "\n";
                    graph[min(i, x)].insert(max(i, x));
                }
            }
        }
    }

    int z = 1;
    for (int i = 1; i <= n; i++) {
        if (cities[i].size() != 0) {
            cities2[z] = cities[i];
            graph2[z] = graph[i];
            val[i] = i - z;
            z++;
        }
    }

    int m = z - 1;
    if (m == 1 && n > 1) {
        cout << 2 << "\n";
        cout << 1 << " ";
        for (int i = 0; i < n - 1; i++) {
            cout << 2 << " ";
        }
        cout << "\n" << 1 << " " << 2;
        return 0;
    }
    for (int i = 1; i <= m; i++) {
        for (auto x : cities2[i]) {
            ppl[x] = i;
        }
    }

    cout << m << "\n";

    for (int i = 1; i <= n; i++) {
        cout << ppl[i] << " ";
    }
    cout << "\n";

    for (int i = 1; i <= m; i++) {
        for (auto x : graph2[i]) {
            cout << i - val[i] << " " << x - val[x] << "\n";
        }
    }
    
    // for (int i = 1; i <= n; i++) {
    //     if (cities[i].size() != 0) {
    //         cout << i << "  ";
    //         for (auto u : cities[i]) {
    //             cout << u << " ";
    //         }
    //         cout << "\n";
    //     }
    // }
}