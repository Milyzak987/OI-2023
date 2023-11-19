#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    vector<string> satellites(2007);
    vector<vector<int>> graph(2007);
    int n, p, m;
    cin >> n >> p >> m;
    
    m = n + 2 * ceil(log2(n)); // Obliczanie długości ciągów identyfikacyjnych

    for (int i = 0; i < p; i++) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b);
        graph[b-1].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        satellites[i] = string(m, 'A'); // Inicjalizacja kodów identyfikacyjnych dla satelitów pierwszej firmy
        satellites[i][i + n] = 'C'; // Ustawienie odpowiedniego bitu dla satelitów drugiej firmy

        // Ustalanie połączeń między satelitami różnych firm
        for (int sat : graph[i]) {
            if (sat > n) { // Sprawdzanie czy satelita należy do drugiej firmy
                satellites[i][sat - 1] = 'C'; // Ustawienie litery dla połączonych satelitów różnych firm
            }
        }
    }

    for (int i = n; i < 2 * n; i++) {
        satellites[i] = string(m, 'B'); // Inicjalizacja kodów identyfikacyjnych dla satelitów drugiej firmy
        satellites[i][i - n] = 'C'; // Ustawienie odpowiedniego bitu dla satelitów pierwszej firmy

        // Ustalanie połączeń między satelitami różnych firm
        for (int sat : graph[i]) {
            if (sat <= n) { // Sprawdzanie czy satelita należy do pierwszej firmy
                satellites[i][sat + n - 1] = 'C'; // Ustawienie litery dla połączonych satelitów różnych firm
            }
        }
    }

    cout << m << "\n";
    for (int i = 0; i < 2 * n; i++) {
        cout << satellites[i] << "\n";
    }
}
