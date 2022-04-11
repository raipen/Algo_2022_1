#include <iostream>
#include <vector>
#define newMatrix(n,s,i) matrix n(s, vector<int>(s , i))
using namespace std;
typedef vector<vector<int> > matrix;
#define INF 0x7fffffff

void printNearst(vector<int> a) {
	for (int i = 2; i < a.size(); i++)
		cout << a[i] << (i == a.size() - 1 ? "\n" : " ");
}

void printMatrix(matrix a) {
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[0].size(); j++)
			cout << a[i][j] << (j == a[0].size() - 1 ? "\n" : " ");
}

matrix prim(int n, matrix W) {
	matrix F;
	vector<int> nearst(n + 1,1), distance(n + 1);

	for (int i = 2; i <= n; distance[i] = W[1][i], i++);
	printNearst(nearst);
	for (int i = 2; i <= n; i++) {
		int min_index = 2;
		for (int j = 3; j <= n; j++) 
			min_index = (distance[min_index] == -1 ? INF : distance[min_index]) > (distance[j] == -1 ? INF : distance[j]) ? j : min_index;
		vector<int> temp = { min_index,nearst[min_index],distance[min_index] };
		F.push_back(temp);
		distance[min_index] = -1;
		for (int j = 2; j <= n; j++)
			if (W[j][min_index] < distance[j]) {
				nearst[j] = min_index;
				distance[j] = W[j][min_index];
			}
		printNearst(nearst);
	}
	return F;
}

int main() {
	int n, m,u,v,w;
	cin >> n >> m;
	newMatrix(W, n + 1, INF);
	for (int i = 1; i <= n; W[i][i] = 0, i++);
	while (m--) {
		cin >> u >> v>>w;
		W[u][v]=W[v][u]=w;
	}
	printMatrix(prim(n, W));
}