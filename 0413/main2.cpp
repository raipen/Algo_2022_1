#include <iostream>
#include <vector>
#include <algorithm>
#define newMatrix(n,s1,s2) matrix n(s1, vector<int>(s2))
using namespace std;
typedef vector<vector<int> > matrix;

void printArr(vector<int> a) {
	for (int i = 0; i < a.size(); i++)
			cout << a[i] << (i == a.size() - 1 ? "\n" : " ");
}

int parents(vector<int>& un, int a) {
	return un[a] == -1 ? a : parents(un, un[a]);
}

bool isGraph(vector<int> un, vector<int> b) {
	return parents(un, b[0]) == parents(un, b[1]);
}

void Kruskal(int n, matrix W) {
	vector<int> un(n+1,-1);
	for (int i = 0,j=1; i < W.size()&&j<n;i++){
		if (!isGraph(un, W[i])) {
			printArr(W[i]);
			un[parents(un,W[i][1])] = parents(un, W[i][0]);
			j++;
		}
	}
}

bool cmp(vector<int>& v1, vector<int>& v2) {
	return v1[2] < v2[2];
}

int main() {
	int n, m;
	cin >> n >> m;
	newMatrix(W, m,3);
	for (int i = 0;i<m;i++)
		cin >> W[i][0] >> W[i][1] >> W[i][2];
	sort(W.begin(), W.end(), cmp);
	Kruskal(n, W);
}