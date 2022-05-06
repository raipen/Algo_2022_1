#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int> > matrix;

int cnt;
vector<int> vcolor;
matrix graph;

bool promising(int i,int n) {    
    if (i > n) return false;
    for (int j = 1; j < i; j++)
        if (graph[i][j] && vcolor[i] == vcolor[j])
            return false;
    return true;
}

void m_coloring(int i,int m,int n) {
    if (promising(i,n)) {
        if (i==n) {
            cnt++;
        }
        else {
            for (int color = 1; color <= m; color++) {
                vcolor[i + 1] = color;
                m_coloring(i + 1,m,n);
            }
        }
    }
}

int main() {
    int n, k,row,col;
    cin >> n >> k;
    vcolor.resize(n + 1);
    graph.assign(n + 1, vector<int>(n + 1, 0));
    while (k--) {
        cin >> row >> col;
        graph[row][col] = graph[col][row] = 1;
    }
    int m=1;
    while (1) {
        cnt = 0;
        m_coloring(0, m++, n);
        if (cnt != 0)
            break;
    }
    cout << m-1 << endl << cnt << endl;
}