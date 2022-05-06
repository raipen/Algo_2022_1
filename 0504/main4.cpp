#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > matrix;

int cnt;
vector<int> vindex;
matrix graph;

bool promising(int i,int n) {
    if ((i == n - 1 && !graph[vindex[n - 1]][vindex[0]])
        || (i>0&&!graph[vindex[i - 1]][vindex[i]])) return false;
    for (int j = 1; j < i; j++)
        if (vindex[i] == vindex[j])
            return false;
    return true;
}

void hamiltonian(int i,int n) {
    if (promising(i,n)) {
        if (i==n-1) {
            cnt++;
        }
        else {
            for (int j = 2; j <= n; j++) {
                vindex[i + 1] = j;
                hamiltonian(i + 1,n);
            }
        }
    }
}

int main() {
    int n, k,row,col;
    cin >> n >> k;
    vindex.resize(n + 1);
    graph.assign(n + 1, vector<int>(n + 1, 0));
    while (k--) {
        cin >> row >> col;
        graph[row][col] = graph[col][row] = 1;
    }
    vindex[0] = 1;
    hamiltonian(0, n);
    cout << cnt << endl;
}