#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define newMatrix(n,s1,s2,i) matrix n(s1, vector<int>(s2 , i))
using namespace std;
typedef vector<vector<int> > matrix;
typedef struct {
	int sum;
	matrix pair;
}result;

int n, W;
matrix item;

bool cmp(vector<int>& v1, vector<int>& v2) {
	return v1[1] * v2[0] > v2[1] * v1[0];
}

void printVector(vector<int> a) {
	for (int i = 0; i < a.size(); i++) {
		if(a[i])
			cout << item[i][0] << " " << item[i][1]<<endl;
	}
}

vector<int> vindex;
int maxProfit=0;

int bound(int i, int w, int p) {
	if (w > W) return 0;
	float result = p;
	int total = w, j = i + 1;
	while (j <= n && total + item[j][0] <= W) {
		total += item[j][0];
		result += item[j][1];
		j++;
	}
	if (j <= n)
		result += (W - total) * ((float)item[j][1] / item[j][0]);
	return result;
}

bool promising(int i, int w, int p) {
	return bound(i,w,p) > maxProfit;
}

vector<int> bestest;

void knapsack(int i, int w, int p) {
	if (w <= W && p > maxProfit) {
		maxProfit = p;
		bestest.clear();
		for (int asdf = 0; asdf < vindex.size(); asdf++) {
			bestest.push_back(vindex[asdf]);
		}
	}
	cout << i << " " << w << " " << p << " " << bound(i, w, p)<< " " << maxProfit << endl;

	if (promising(i, w,p)) {
		vindex[i + 1] = 1;
		knapsack(i + 1, w+ item[i+1][0], p+ item[i+1][1]);
		vindex[i + 1] = 0;
		knapsack(i + 1, w, p);
	}
}

int main(void) {
	cin >> n >> W;
	item.assign(n + 1, vector<int>(2, 0));
	vindex.assign(n + 1, 0);
	for (int i = 1; i <= n; cin >> item[i][0], i++);
	for (int i = 1; i <= n; cin >> item[i][1], i++);
	sort(item.begin(), item.end(), cmp);

	knapsack(0, 0, 0);
	cout << maxProfit<<endl;
	printVector(bestest);
	return 0;
}