#include <iostream>
#include <vector>
#include <string>
#define newMatrix(n,s,s2,i) matrix n(s, vector<int>(s2 , i))
using namespace std;
typedef vector<vector<int> > matrix;

string path(int i, int j, matrix d, string a) {
	if (i * j == 0) return "";
	switch (d[i][j]) {
	case 1:
		return path(i - 1, j - 1, d, a) + a[i];
	case 2:
		return path(i, j - 1, d, a);
	case 3:
		return path(i - 1, j, d, a);
	}
}

int main() {
	string a, b;
	cin >> a >> b;
	a = " " + a;
	b = " " + b;
	newMatrix(c, a.size(),b.size(), 0);
	newMatrix(d, a.size(), b.size(), 0);
	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			c[i][j] = a[i] == b[j] ? c[i - 1][j - 1] + 1 : c[i][j - 1] > c[i - 1][j] ? c[i][j - 1] : c[i - 1][j];
			d[i][j] = a[i] == b[j] ? 1 : c[i][j - 1] > c[i - 1][j] ? 2 : 3;
		}
	}
	cout << c[a.size() - 1][b.size() - 1] << endl;
	cout << path(a.size() - 1, b.size() - 1, d, a) << endl;
	return 0;
}