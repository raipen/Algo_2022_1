#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;
    cout<< (n%2? (n-1)*3/2:n*3/2-2)<<endl;
}