#include <iostream>
#include <vector>
#define INF 999
using namespace std;
typedef vector<vector<int>> matrix;
matrix D,P;
void printMatrix(matrix a) {
	for (int i = 0; i < a.size(); i++) 
		for (int j = 0; j < a.size(); j++)
			cout << a[i][j] << (j == a.size() - 1 ? "\n" : " ");
}

void Path(int start, int end,vector<int>&p) {
    int k =P[start - 1][end - 1];
	if (k) {
        Path(start,k,p);
        p.push_back(k);
        Path(k,end,p);
    }
}

void Floyd() {
	for (int k = 0; k < D.size(); k++) {
		for (int i = 0; i < D.size(); i++) {
			for (int j = 0; j < D.size(); j++) {
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k+1;
				}
			}
		}
	}
}

int main() {
	int N, M,r=1,c=1;
	cin >> N >> M;
	D.assign(N, vector<int>(N, INF));
	P.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++) D[i][i] = 0;
	while (M--)
		cin >> r >> c >> D[r - 1][c - 1];
	Floyd();
	printMatrix(D);
	printMatrix(P);
	cin >> M;
	while (M--) {
		cin >> r >> c;
        vector<int> path;
        Path(r, c,path);
        if(D[r-1][c-1]==INF){
            cout<<"NONE"<<endl;
            continue;
        }
		cout<< r<<" ";
        for(int i=0;i<path.size();i++) cout<<path[i]<<" ";
        cout<<c<<endl;
	}
}