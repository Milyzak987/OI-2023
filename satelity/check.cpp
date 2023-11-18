// Created by Adam Gąsienica-Samek, adjusted for Toster by Olaf Targowski
#include<bits/stdc++.h>
using namespace std;
string S[2000];
int T[1000][1000], wynik = 100, m;
pair<int,int> kraw[1000000];
bool check(int a, int b) {
  for(int i = 0; i < m; ++i) {
    if(S[a][i] == S[b][i]) {
      return true;
    }
  }
  return false;
}
int Log2(int x) {
  int l = 0;
  for(int i = 1; i < x; i *= 2) {
    ++l;
  }
  return l;
}
void solve() {
  int n, p, M;
  cin >> n >> p >> M;
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      T[i][j] = 0;
    }
  }
  for(int i = 0; i < p; ++i) {
    int a, b;
    cin >> a >> b;
    kraw[i] = {a, b};
    a -= 1;
    b -= n + 1;
    T[a][b] = 1;
  }
  bool ok = true;
  cin >> m;
  for(int i = 0; i < 2 * n; ++i) {
    cin >> S[i];
    if(int(S[i].size()) != m) {
      ok = false;
    }
    for(int j = 0; j < m; ++j) {
      if(S[i][j] != 'A' && S[i][j] != 'B' && S[i][j] != 'C') {
        ok = false;
      }
    }
    for(int j = 0; j < i; ++j) {
      if(S[i] == S[j]) {
        ok = false;
      }
    }
  }
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      if(check(i, j) == false || check(i + n, j + n) == false || check(i, j + n) != T[i][j]) {
        ok = false;
      }
    }
  }
  if(ok == false || m > n * n + 2 * n) {
    cout << "I 0/100\n";
    cout << n << " " << p << " " << M << '\n';
    for(int i = 0; i < p; ++i) {
      cout << kraw[i].first << " " << kraw[i].second << '\n';
    }
    exit(0);
  }
  if(m > 3 * n) {
    wynik = min(wynik, 7);
  }
  if(m > n + 2 * Log2(n)) {
    wynik = min(wynik, 18);
  }
  if(m > n + 2) {
    wynik = min(wynik, 41);
  }
  if(m > n + 1) {
    wynik = min(wynik, 82);
  }
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  solve();
  if (wynik>=18)
    cout << "C\n";
  else
    cout << "I " << wynik << "/100\n";
}
