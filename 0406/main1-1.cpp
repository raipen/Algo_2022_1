#include <iostream>
#include <vector>
#include <string>
#define newMatrix(n,s,i) matrix n(s, vector<int>(s , i))
using namespace std;
typedef vector<vector<int> > matrix;

void printTriangle(matrix a) {
	for (int i = 1; i < a.size(); i++)
		for (int j = i; j < a.size(); j++)
			cout << a[i][j] << (j == a.size() - 1 ? "\n" : " ");
}

void order(int i, int j, matrix P, string& s) {
	if (i == j)
		s += "(A" + to_string(i)+")";
	else {
		int k = P[i][j];
		s += "(";
		order(i, k, P, s);
		order(k + 1, j, P, s);
		s += ")";
	}
}


int main() {
	int size;
	cin >> size;
	vector<int> d(size+1);
	newMatrix(M, size + 1,1000000);
	newMatrix(P, size + 1,0);
	for (int i =0; i <= size; i++)
		cin >> d[i];
	for (int i = 1; i <= size; M[i][i] = 0, i++);
	for (int i = 1; i <= size; i++) {
		for (int j = 1; j <= size-i; j++) {	
			for (int k = 0; k < i; k++) {
				if (M[j][i + j] > M[j][j + k] + M[j + k + 1][i + j] + d[j - 1] * d[j + k] * d[i + j]) {
					P[j][i + j] = j + k;
					M[j][i + j] = M[j][j + k] + M[j + k + 1][i + j] + d[j - 1] * d[j + k] * d[i + j];
				}
			}
		}
	}

	printTriangle(M);
	printTriangle(P);
	cout << M[size][size] << endl;
	string s;
	order(1, size,P,s);
	cout << s<<endl;
	return 0;
}