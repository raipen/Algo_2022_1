#include <iostream>
#include <vector>
using namespace std;

int result(vector<int> a,vector<int> b,int s){
    int sum = 0;
    for(int i=0;i<s;i++)
        sum+=a[i]*b[i];
    return sum;
}

int main(void){
    int n,k,m;
    cin>>n>>k>>m;
    vector<vector<int>> a(n,vector<int>(k)),b(m,vector<int>(k));
    for(int i=0;i<n;i++)
        for(int j=0;j<k;j++)
            cin>>a[i][j];
    for(int i=0;i<k;i++)
        for(int j=0;j<m;j++)
            cin>>b[j][i];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cout<<result(a[i],b[j],k)<<(j==m-1?"\n":" ");
    return 0;
}