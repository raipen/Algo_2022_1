#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, max;
    cin >> n >> max;
    if (n <= 1) {
        cout << n;
        return 0;
    }
    int n0 = 0, n1 = 1;
    for (int i = 0; i < n/2; i++) {
        n0 = (n0 + n1)%max;
        n1 = (n0 + n1)%max;
    }
    cout << (n%2?n1:n0);

    return 0;
}