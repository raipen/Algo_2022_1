#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, max,r[2] = {0,1};
    cin >> n >> max;
    for (int i = 2; i <= n; i++) 
        r[i%2]=(r[0]+r[1])%max;
    cout <<r[n%2];
    return 0;
}