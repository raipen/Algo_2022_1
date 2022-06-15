#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;
int n, m;
vector<pair<int, int>> vindex;

bool promising(int i){
	if (vindex[i].first < 0 || vindex[i].second < 0||vindex[i].first>=n||vindex[i].second>=m)
		return false;
	for (int j = 0; j < i; j++)
		if (vindex[j].first == vindex[i].first && vindex[j].second == vindex[i].second)
			return false;
	return true;
}

struct {
	int row;
	int col;
} coor[] = { {-2, -1},{-2, 1},{-1, -2},{-1, 2},{1 ,-2},{1 ,2},{2 ,-1},{2 ,1} };

bool cir(int i) {
	for (int j = 0; j < 8; j++)
		if (vindex[i].first - vindex[0].first == coor[j].row && vindex[i].second - vindex[0].second == coor[j].col)
			return true;
	return false;
}

bool pas(int i) {
	return true;
}

void hamiltonian(int i,bool fun(int i)) {
	if (promising(i)) {
		if (i == n * m-1) {
			if (fun(i))
				cnt++;
		}
		else {
			for (int j = 0; j < 8; j++) {
				vindex[i + 1].first = vindex[i].first + coor[j].row;
				vindex[i + 1].second = vindex[i].second + coor[j].col;
				hamiltonian(i + 1,fun);
			}
		}
	}
}


int main(void) {
	cin >> n >> m;
	vindex.assign(n*m, pair<int, int>(0,0));
	hamiltonian(0,cir);
	cout << cnt <<endl;

	int T,row,col;
	cin >> T;
	while(T--) {
		cin >> vindex[0].first >> vindex[0].second;
		cnt = 0;
		hamiltonian(0,pas);
		cout << cnt << endl;
	}

	return 0;
}