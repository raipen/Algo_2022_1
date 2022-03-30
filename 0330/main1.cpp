#include <iostream>
#include <vector>
using namespace std;
int n, k, m;

int pascalDP(int n, int k) {
    vector<int> DP(k+1,0);
    DP[1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = k<i?k:i; j >0; j--)
            DP[j] = (DP[j] + DP[j - 1])%m;
    return DP[k];
}

int main() {
    cin >> n >> k >> m;
    cout << pascalDP(n+1, k>n/2?n-k+1:k+1);
    return 0;
}
