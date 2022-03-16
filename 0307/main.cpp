#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int find(vector<int>& a, int f, int l, int r) {
    return (l > r)? -1:(a[(l + r) / 2] > f ? find(a, f, 0, (l + r) / 2 - 1): (a[(l + r) / 2] == f ? (l + r) / 2 : find(a, f, (l + r) / 2 + 1, r)));
}

int main(){
    string file_name;
    cout << "Enter File Name"<<endl;
    cin >> file_name;
    ifstream f(file_name);
    int n,m;
    f>>n>>m;
    vector<int> ff(n), arr(m);
    for(int i=0;i<n;i++) f>>ff[i];
    for(int i=0;i<m;i++) f>>arr[i];
    for(int i=0;i<n;i++) cout<<(find(arr,ff[i],0,m)==-1?"Yes":"No")<<endl;
    f.close();
}