#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int collatz(int i) {
    int cnt = 0;
    while(1){
        cnt++;
        if(i==1) return cnt;
        if(i%2) i = i*3 +1;
        else i = i/2;
    }
}

int main() {
    int min,max;
    cin >> min>> max;
    int min_value , max_value,value,min_index,max_index;
    min_value = max_value = value =  collatz(min);
    min_index = max_index = min;
    for (int i = min; i < max; i++,value = collatz(i)) {
        //cout << i<<" "<< value << endl;
        if (min_value >= value) {
            min_index = i;
            min_value = value;
        }
        if (max_value <= value) {
            max_index = i;
            max_value = value;
        }
    }
    cout << min_value << " " << max_value << endl;
    cout << min_index<<" " << max_index <<endl;
}