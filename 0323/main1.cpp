#include <iostream>
#include <vector>
using namespace std;
int t, cnt = 0;
typedef vector<vector<int>> matrix;

matrix strassen(int n, matrix a, matrix b);

void printMatrix(int n,matrix a) {
	cout << cnt << endl;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << a[i][j] << (j==n-1?"\n":" ");
}

matrix mmult(int n, matrix a, matrix b) {
	matrix m(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				m[i][j] += a[i][k] * b[k][j];
	return m;
}

matrix mas(int n, matrix a, matrix b,int t) {//t가 1이면 덧셈, 0이면 뺄셈
	matrix m(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			m[i][j] = t ? a[i][j] + b[i][j] : a[i][j] - b[i][j];
	return m;
}

vector<matrix> partition(int n, matrix a) {
	vector<matrix> m(4, matrix(n / 2, vector<int>(n / 2, 0)));
	int start[4][2] = { {0,0}, {0,n / 2}, {n / 2, 0},{n / 2,n / 2} };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n / 2; j++) 
			for (int k = 0; k < n / 2; k++) 
				m[i][j][k] = a[start[i][0] + j][start[i][1] + k];
	return m;
}

vector<matrix> matrixM7(int n, matrix a, matrix b) {
	vector<matrix> m(7);
	vector<matrix> ap = partition(n, a);
	vector<matrix> bp = partition(n, b);
	m[0] = strassen(n / 2, mas(n / 2, ap[0], ap[3], 1), mas(n / 2, bp[0], bp[3],1));
	m[1] = strassen(n / 2, mas(n / 2, ap[2], ap[3], 1), bp[0]);
	m[2] = strassen(n / 2, ap[0], mas(n / 2, bp[1], bp[3],0));
	m[3] = strassen(n / 2, ap[3], mas(n / 2, bp[2], bp[0],0));
	m[4] = strassen(n / 2, mas(n / 2, ap[0], ap[1], 1), bp[3]);
	m[5] = strassen(n / 2, mas(n / 2, ap[2], ap[0], 0), mas(n / 2, bp[0], bp[1],1));
	m[6] = strassen(n / 2, mas(n / 2, ap[1], ap[3], 0), mas(n / 2, bp[2], bp[3],1));
	return m;
}

matrix combine(int n, matrix a, matrix b, matrix c, matrix d) {
	matrix m(n, vector<int>(n, 0));
	matrix m2[4] = { a,b,c,d };
	int start[4][2] = { {0,0}, {0,n / 2}, {n / 2, 0},{n / 2,n / 2} };
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < n / 2; j++) 
			for (int k = 0; k < n / 2; k++) 
				m[start[i][0] + j][start[i][1] + k] = m2[i][j][k];
	return m;
}

matrix strassen(int n,matrix a, matrix b) {
	cnt++;
	if (n <= t)
		return mmult(n, a, b);
	else {
		vector<matrix> M = matrixM7(n,a,b);
		return combine(n, mas(n / 2, mas(n / 2, mas(n / 2, M[0], M[3], 1), M[6], 1), M[4], 0), mas(n / 2, M[2], M[4], 1), mas(n / 2, M[1], M[3], 1), mas(n / 2, mas(n / 2, mas(n / 2, M[0], M[2], 1), M[5], 1), M[1], 0));
	}
}

int powOf2(int n) {
	int i = 1;
	while (i < n) i = i<<1;
	return i;
}

int main() {
	int n;
	cin >> n >> t;
	int n2 = powOf2(n);
	vector<matrix> m(2,matrix(n2, vector<int>(n2,0)));
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				cin >> m[i][j][k];
	printMatrix(n, strassen(n2, m[0], m[1]));
	return 0;
}
