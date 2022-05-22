#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#define newMatrix(n,s1,s2,i) matrix n(s1, vector<int>(s2 , i))
#define INF 0x3fffffff
using namespace std;
typedef vector<vector<int> > matrix;
struct ITEM {
    int level;
    vector<int> path;
    int bound;
    ITEM() {}
    ITEM(int level, vector<int> path, int bound) : level(level), path(path), bound(bound) {}
};
struct ITEMcmp {
    bool operator()(ITEM a, ITEM b) {
        return a.bound > b.bound;
    }
};

int n;
matrix W;

int length(vector<int> path) {
    int result = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        if (W[path[i]][path[i + 1]]==INF) return INF;
        result += W[path[i]][path[i + 1]];
    }
    return result;
}

bool hasOutgoing(int v, vector<int>& path) {
    for (int i = 0; i < path.size() - 1; i++)
        if (v == path[i]) return true;
    return false;
}

bool hasIncoming(int v, vector<int>& path) {
    for (int i = 1; i < path.size(); i++)
        if (v == path[i]) return true;
    return false;
}

int bound(int i, vector<int>& path) {
    int lower = length(path);
    for (int i = 1; i <= n; i++) {
        if (hasOutgoing(i, path)) continue;
        int min = INF;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (hasIncoming(j, path)) continue;
            if (j == 1 && i == path[path.size() - 1]) continue;
            if (min > W[i][j]) min = W[i][j];
        }
        lower = (min==INF||lower==INF)?INF:lower+min;
    }
    return lower;
}

ITEM newITEM(int i, vector<int> p, int np) {
    vector<int> path(p.size());
    copy(p.begin(), p.end(), path.begin());
    path.push_back(np);
    return ITEM(i, path, bound(i, path));
}

void printITEM(ITEM item) {
    cout << item.level << " ";
    if (item.bound == INF)
        cout << "INF ";
    else
        cout<< item.bound << " ";
    for (int i = 0; i < item.path.size(); i++)
        cout << item.path[i] << (i == item.path.size() - 1 ? "\n" : " ");
}

int remaining(vector<int> path) {
    int s = 0;
    for (int i : path)
        s += i;
    return n * (n + 1) / 2 - s;
}

bool isIn(int v, vector<int> path)
{
    for (int i = 0; i < path.size(); i++)
        if (v == path[i]) return true;
    return false;
}

vector<int> opttour;

int travel() {
    priority_queue<ITEM, vector<ITEM>, ITEMcmp> Q;

    int minTravel = INF;
    Q.push(newITEM(0, vector<int>(0, 0), 1));
    printITEM(Q.top());
    ITEM cur,temp;
    while (!Q.empty()) {
        cur = Q.top(); Q.pop();
        if (cur.bound< minTravel) {
            for (int i = 2; i <= n; i++) {
                if (isIn(i, cur.path)) continue;
                temp = newITEM(cur.level + 1, cur.path, i);
                if (temp.level == n - 2) {
                    temp.path.push_back(remaining(temp.path));
                    temp.path.push_back(1);
                    if (length(temp.path) < minTravel) {
                        minTravel = length(temp.path);
                        opttour.resize(temp.path.size());
                        copy(temp.path.begin(), temp.path.end(), opttour.begin());
                    }
                }
                else {
                    if (temp.bound < minTravel)
                        Q.push(temp);
                }
                printITEM(temp);
            }
        }
    }
    return minTravel;
}

int main(void) {
    int m, row, col;
    cin >> n >> m;
    W.assign(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        W[i][i] = 0;
    while (m--) {
        cin >> row >> col;
        cin >> W[row][col];
    }
    //입력 끝

    cout << travel() << endl;
    for (int i = 0; i < opttour.size(); i++)
        cout << opttour[i] << (i == opttour.size() - 1 ? "\n" : " ");
    return 0;
}