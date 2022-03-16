#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt = 0;

int partition(vector<int>& S, int l, int r) {
    cnt++;
    int p = S[l];

    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (S[i] < p) {
            j++;
            swap(S[i], S[j]);
        }
    }
    swap(S[l], S[j]);
    return j;
}

void quicksort(vector<int>& S, int l, int r) {
    if (l < r) {
        int p = partition(S,l, r);
        quicksort(S, l, p - 1);
        quicksort(S, p +1,r);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];

    int p = partition(S, 0, n-1);
    for (int i = 0; i < n; i++) cout << S[i] << (i==n-1?"\n":" ");
    quicksort(S, 0, p - 1);
    quicksort(S, p + 1, n-1);
    cout<<cnt<<"\n";
    for (int i = 0; i < n; i++) cout << S[i]<<" ";
    return 0;
}