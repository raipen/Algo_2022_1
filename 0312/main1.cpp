#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int size,min,max,temp;
    cin>>size>>min;
    max=min;
    for(int i=0;i<size-1;i++){
        cin>>temp;
        min = min<temp? min:temp;
        max = max<temp? temp:max;
    }
    cout<<min<<"\n"<<max<<"\n";
    return 0;
}