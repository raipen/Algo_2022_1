#include <iostream>
#include <vector>
using namespace std;
int a[5000001];

void che() {
    for (int i = 2; i < 2237; i++) {
        if (!a[i])
            for (int j = i*2; j < 5000001; j += i)
                if(!a[j])
                    a[j] = i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    che();
    int N,x;
    cin >> N;
    while(N--) {
        cin >> x;
        for (; a[x]; x /= a[x])
            cout << a[x]<<" ";
        cout<<x << "\n";
    }
}