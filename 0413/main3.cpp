#include <iostream>
#include <vector>
#define newMatrix(n,s,i) matrix n(s, vector<int>(s,i))
using namespace std;
typedef vector<vector<int> > matrix;
#define INF 0x7fffffff

void printTouch(vector<int> a) {
	for (int i = 2; i < a.size(); i++)
		cout << a[i] << (i == a.size() - 1 ? "\n" : " ");
}

void printMatrix(matrix a) {
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < a[i].size(); j++)
			cout << a[i][j] << (j == a[i].size() - 1 ? "\n" : " ");
}

void printPath(int w, vector<int> touch) {
	if (w != 1) printPath(touch[w], touch);
	cout << w << " ";
}

matrix dijkstra(int n, matrix W, vector<int>& touch) {
	matrix F;
	vector<long long> distance(n + 1);
	for (int i = 2; i <= n; distance[i] = W[1][i], i++);
	printTouch(touch);
	int time = n - 1;
	while (time--) {
		int min_index = 2;
		for (int i = 3; i <= n; i++)
			min_index = distance[min_index]<0||(distance[i]>=0&&distance[min_index] > distance[i]) ? i : min_index;
		vector<int> temp = { touch[min_index],min_index,W[touch[min_index]][min_index] };
		F.push_back(temp);
		for (int i = 2; i <= n; i++)
			if (distance[i] > distance[min_index] + W[min_index][i]) {
				touch[i] = min_index;
				distance[i] = distance[min_index] + W[min_index][i];
			}
		distance[min_index] = -1;
		printTouch(touch);
	}
	return F;
}

int main() {
	int n, m, u, v, w;
	cin >> n >> m;
	newMatrix(W, n + 1, INF);
	for (int i = 1; i <= n; W[i][i] = 0, i++);
	while (m--)
		cin >> u >> v >> W[u][v];
	vector<int> touch(n + 1, 1);
	printMatrix(dijkstra(n, W, touch));
	cin >> m;
	while (m--) {
		cin >> w;
		printPath(touch[w], touch);
		cout << w << endl;
	}
}