#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;

void merge2(vector<int>& S, int l, int m, int r) {
    cnt++;
    int i = l, j = m + 1, k = 0;
    vector<int> U(r - l + 1);

    while (i <= m && j <= r) {
        U[k++] = S[i] < S[j] ? S[i++] : S[j++];
    }
    while (i <= m)
        U[k++] = S[i++];
    while (j <= r)
        U[k++] = S[j++];

    for (int t = l; t <= r; t++) {
        S[t] = U[t - l];
    }
}

void mergesort2(vector<int>& S, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort2(S, l, m);
        mergesort2(S, m + 1, r);
        merge2(S, l, m, r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    mergesort2(S, 0, n-1);
    cout<<cnt<<"\n";
    for (int i = 0; i < n; i++) cout << S[i]<<" ";
    return 0;
}