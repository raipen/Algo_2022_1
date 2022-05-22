#include <iostream>
#include <vector>
#include <cmath>
#define newMatrix(n,s1,s2,i) matrix n(s1, vector<int>(s2 , i))
#define INF 0x3fffffff
using namespace std;
typedef vector<vector<int> > matrix;

bool isIn(int i, int A) {
    return (A & (1 << (i - 2)));
}

int diff(int A, int j) {
    return A & ~(1 << (j - 2));
}

int count(int n) {
    int cnt = 0;
    for (; n != 0; n = n >> 1)
        if (n & 1) cnt++;
    return cnt;
}

int minimum(int n, int i, int& minJ, int A, matrix& W, matrix& D) {
    int minV = INF, value;
    for (int j = 2; j <= n; j++) {
        if (!isIn(j, A)) continue;
        value = W[i][j] + D[j][diff(A, j)];
        if (minV > value) {
            minV = value;
            minJ = j;
        }
    }
    return minV;
}

void travel(int n, matrix& W, matrix& D, matrix& P) {

    for (int i = 2; i <= n; i++)
        D[i][0] = W[i][1];
    for (int k = 1; k <= n - 2; k++)
        for (int A = 0; A < pow(2, n - 1); A++) {
            if (count(A) != k) continue;
            for (int i = 2; i <= n; i++) {
                if (isIn(i, A)) continue;
                D[i][A] = minimum(n, i, P[i][A], A, W, D);
            }
        }
    int A = pow(2, n - 1) - 1; // A = V - {v1}
    D[1][A] = minimum(n, 1, P[1][A], A, W, D);
}

void printPath(int v, int A, matrix& P) {
    int k = P[v][A];
    if (A == 0)
        cout << "1";
    else {
        cout << k << " ";
        printPath(k, diff(A, k), P);
    }
}

int main() {
    int n, m, row, col;
    cin >> n >> m;
    newMatrix(graph, n + 1, n + 1, INF);
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;
    while (m--) {
        cin >> row >> col;
        cin >> graph[row][col];
    }
    //입력 끝

    newMatrix(D, n + 1, pow(2, n - 1), 0);
    newMatrix(P, n + 1, pow(2, n - 1), 0);
    travel(n, graph, D, P);
    cout << D[1][pow(2,n-1)-1] << endl<<1<<" ";
    printPath(1, pow(2, n - 1) - 1, P);
    cout << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < pow(2, n - 1); j++)
            if (D[i][j] != INF && D[i][j])
                cout << i << " " << j << " " << D[i][j] << endl;
}