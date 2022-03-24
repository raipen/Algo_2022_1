#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix;
int cur = 1;

void printMatrix(int n, matrix a) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << a[i][j] << (j == n - 1 ? "\n" : " ");
}

matrix combine(int n, matrix m2[]) {
	matrix m(n, vector<int>(n, 0));
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n / 2; j++)
			for (int k = 0; k < n / 2; k++)
				m[(i / 2) * (n / 2) + j][(i % 2) * (n / 2) + k] = m2[i][j][k];
	return m;
}

matrix tromino(int n, int r, int c) {
	if (n == 2) {
		matrix m(n, vector<int>(n, cur++));
		m[r][c] = 0;
		return m;
	}else {
		int temp = cur++;
		int type = r < n / 2 ? (c < n / 2 ? 0 : 1) : (c < n / 2 ? 2 : 3);
		matrix arr[4];
		for (int i = 0; i < 4; i++)
			arr[i] = tromino(n / 2, type == i ? r - (i / 2) * (n / 2) : n / 2 - 1 - (i / 2) * (n / 2 -1), type == i ? c - (i % 2) * (n / 2) : n / 2 - 1 - (i % 2) * (n / 2 - 1));
		matrix m = combine(n, arr);
		for (int i = 0; i < 4; i++)
			if (i != type)
				m[(i / 2) * (n / 2) + n / 2 - 1 - (i / 2) * (n / 2 - 1)][(i % 2) * (n / 2) + n / 2 - 1 - (i % 2) * (n / 2 - 1)] = temp;
		return m;
	}
}

int main() {
	int n, r, c;
	cin >> n >> r >> c;
	printMatrix(n, tromino(n, r, c));
	return 0;
}