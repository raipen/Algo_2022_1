#include <iostream>
#include <vector>
using namespace std;

void binsearch(int n, int& index, int& search_count, vector<int> S)
{
    int low, high, mid;
    low = 0; high = n;
    index = -1;
    search_count = 0;
    while(low<=high && index == -1)
    {
        mid = (low+high)/2;
        if(mid == S[mid]){
            index = mid;
        }
        else if(mid < S[mid]){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
         search_count++;
    }
}

int main()
{
    int n, index, search_count;
    cin >> n;
    vector<int> S(n);

    for(int i=0; i<n; i++)
    {
        cin >> S[i];
    }
    binsearch(n, index, search_count, S);
    cout << index << endl;
    cout << search_count << endl;
}