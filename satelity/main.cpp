#include <iostream>
#include <vector>
using namespace std;

vector<int> satelites(1003);

int main (){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, p, m;
    cin >> n >> p;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        satelites[i] = a;
    }
}