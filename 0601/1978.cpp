#include <iostream>
#include <vector>

using namespace std;
vector<int> a(1001, 1);
void che() {
    for (int i = 2; i < 32; i++) {
        if (a[i])
            for (int j = i*2; j < 1001; j += i)
                a[j] = 0;
    }
    a[0] = a[1] = 0;
}

int main() {
    che();
    int N,x,cnt=0;
    cin >> N;
    while (N--) {
        cin >> x;
        if (a[x])
            cnt++;
    }
    cout << cnt;
}