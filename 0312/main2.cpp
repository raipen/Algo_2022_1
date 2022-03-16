#include <iostream>
#include <vector>
using namespace std;

int r(vector<int> a,vector<int> b,int n,int m,int k,int s){
    int sum = 0;
    for(int i=0;i<k;i++){
        sum+=a[n*k+i]*b[m+i*s];
    }
    return sum;
}

int main(void){
    int i,n,k,m;
    cin>>n>>k>>m;
    vector<int> a(n*k),b(k*m);
    for(i=0;i<n*k;i++) cin>>a[i];
    for(i=0;i<k*m;i++) cin>>b[i];
    for(i=0;i<n*m;i++) cout<<r(a,b,i/m,i%m,k,m)<<(i%m==m-1?"\n":" ");
    return 0;
}