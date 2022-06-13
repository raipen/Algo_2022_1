#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x, y, s, b,cnt=0;
	cin >> n;
	if (n % 2) {
		cin >> s;
		b = s;
	}
	else {
		cin >> s >> b;
        cnt++;
		if (s > b) {
			x = s;
			s = b;
			b = x;
		}
		n--;
	}
	n /= 2;
	while (n--) {
		cin >> x >> y;
		if (x < y) {
			s = s < x ? s : x;
			b = b > y ? b : y;
		}
		else {
			s = s < y ? s : y;
			b = b > x ? b : x;
		}
        cnt += 3;
	}
	cout << (s * b);
    //연산횟수
    //cout << cnt;
}