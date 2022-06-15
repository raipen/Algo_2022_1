#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int collatz(int i) {
    int cnt = 0;
    while(1){
        cnt++;
        if(cnt==10000000) return cnt;
        if(i==1) return cnt;
        if(i%2) i = i*3 -1;
        else i = i/2;
    }
}

int main() {
    int cnt=0;
    for(int i=1;i<=1000;i++){
        if(collatz(i)==10000000)
            cnt++;
    }
    cout<<cnt<<'\n';
}