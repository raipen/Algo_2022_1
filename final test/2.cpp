#include <iostream>
#include <vector>

using namespace std;
int a[5000001];
void che() {
    for (int i = 2; i < 2237; i++) {
        if (!a[i])
            for (int j = i*2; j < 5000001; j += i)
                a[j]++;
    }
}

int main() {
    che();
    int N,x,cnt=0;
    // cin >> N;
    // while (N--) {
    //     cin >> x;
    //     cout<<a[x];
    // }
    
    //2-1번
    // for(int i=123;i<1235;i++){
    //     if(a[i]==2){
    //         cnt++;
    //         cout<<i<<endl;
    //     }
    // }
    // cout<<cnt<<endl;

    //2-2번
    for(int i=1234;i<123457;i++){
        if(a[i]==2){
            cnt++;
        }
    }
    cout<<cnt<<endl;
}