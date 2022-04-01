#include <iostream>
#include <vector>
#define newMatrix(n,s) vector<vector<int> > n(s, vector<int>(s , 0))
using namespace std;

int main() {
	int N, temp, m = 0;
	cin >> N;
	newMatrix(origin, N + 1);
	newMatrix(cost, N + 1);
	newMatrix(path, N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j <= i; j++)
			cin >> origin[i][j];
	for (int i = N - 1; i >= 0; i--)
		for (int j = 0; j <= i; j++) {
			path[i][j] = cost[i + 1][j] > cost[i + 1][j + 1] ? j : j + 1;
			cost[i][j] = origin[i][j] + cost[i + 1][path[i][j]];
		}
	cout << cost[0][0] << endl;
	for (int i = 0, cur = 0; i < N; cur = path[i][cur], i++)
		cout << origin[i][cur] << " ";
}