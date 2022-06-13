#include <iostream>
#include <vector>
using namespace std;
int a[1000001];
void che() {
    for (int i = 2; i < 1001; i++) {
        if (!a[i])
            for (int j = i*2; j < 1000001; j += i)
                a[j] = 1;
    }
    a[0] = a[1] = 1;
}

int main() {
    che();
    int s,f;
    cin >> s>>f;
    for (; s <= f; s++) {
        if (!a[s])
            cout << s<<'\n';
    }
}