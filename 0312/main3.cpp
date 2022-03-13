#include <iostream>
#include <vector>
using namespace std;

int bs(vector<int> a,int l,int r,int& n){
    if(l <= r) n++;
    int m = (l + r) / 2;
    return (l > r)? -1:(a[m] == m ? m : (a[m] > m ? bs(a, l, m-1, n) : bs(a, m + 1, r, n)));
}

int main(void){
    int size,cnt=0;
    cin>>size;
    vector<int> a(size);
    for(int i=0;i<size;i++)
        cin>>a[i];
    cout<<bs(a,0,size-1,cnt)<<"\n"<<cnt<<"\n";
    return 0;
}