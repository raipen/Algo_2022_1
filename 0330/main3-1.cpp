#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> matrix;

int main() {
	int N, temp, m = 0;
	cin >> N;
	matrix D(N + 1, vector<int>(N + 1, 0));
	matrix path(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> temp;
			path[i][j] = D[i-1][j] > D[i-1][j - 1] ? j : j - 1;
			D[i][j] = D[i-1][path[i][j]] + temp;
		}
	}
	for (int i = 1; i <= N; i++)
		m = D[N][m] > D[N][i] ? m : i;
	cout << D[N][m]<<endl;
	vector<int> P(N+1,0);
	P[N] = m;
	for (int i = N - 1; i > 0; i--)
		P[i] = path[i + 1][P[i + 1]];

	for (int i = 1; i <=N; i++)
		cout << D[i][P[i]]- D[i-1][P[i-1]] << (i==N?"\n":" ");
}