#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, p, m;

string decToBin(int decimalNumber) {
    string binary = string(m-n-1, 'B');

    int i = 0;
    while (decimalNumber > 0) {
        binary[i] = ((decimalNumber % 2) == 0 ? 'B' : 'C'); 
        decimalNumber /= 2;
        i++;
    }
    return binary;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    vector<string> satelites(2007);
    vector<vector<int>> graph(2007);
    cin >> n >> p >> m;
    m = n + 2 * ceil(log2(n));

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        graph[a - 1].push_back(b);
        graph[b - 1].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        satelites[i] = string(m, 'A');
        satelites[i][i + 1] = 'C';
    }
    for (int i = n; i < 2 * n; i++) {
        satelites[i] = string(m, 'B');
        string bin = decToBin(i-n);
        satelites[i].replace(n+1, m-n-1, bin);
        for (int sat : graph[i]) {
            satelites[i][sat] = 'C';
        }
    }

    cout << m << "\n";
    for (int i = 0; i < 2 * n; i++) {
        cout << satelites[i] << "\n";
    }
}