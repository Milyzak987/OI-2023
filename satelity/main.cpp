#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    vector<string> satelites(2007);
    vector<vector<int>> graph(2007);
    int n, p, m;
    cin >> n >> p >> m;
    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b);
        graph[b-1].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        satelites[i] = string(2*n + 1, 'A');
        satelites[i][i + 1] = 'C';
    }
    for (int i = n; i < 2 * n; i++) {
        satelites[i] = string(2*n + 1, 'B');
        satelites[i][i+1] = 'C';
        for(int sat : graph[i]){
            satelites[i][sat] = 'C';
        }
    }

    cout << 2*n+1 << "\n";
    for (int i = 0; i < 2*n; i++) {
        cout << satelites[i] << "\n";
    }
}