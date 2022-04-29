#include <iostream>
#include <vector>
#include <algorithm>
#define newMatrix(n,s1,s2,i) matrix n(s1, vector<int>(s2 , i))
using namespace std;
typedef vector<vector<int> > matrix;
typedef struct {
	int sum;
	matrix pair;
}result;

bool cmp(vector<int>& v1, vector<int>& v2) {
	return v1[1]*v2[0] > v2[1]*v1[0];
}

void printResult(result a) {
	cout << a.sum << endl;
	for (int i = 0; i < a.pair.size(); i++)
		cout << a.pair[i][0] << " " << a.pair[i][1] << endl;
}

result knapsack(matrix item, int w) {
	result res;
	res.sum = 0;
	for (int i = 0, weightSum = 0; weightSum < w && i < item.size(); i++) {
		vector<int> temp(2);
		temp[0] = (w - weightSum) < item[i][0] ? w - weightSum : item[i][0];
		temp[1] = item[i][1] * temp[0] / item[i][0];
		res.pair.push_back(temp);
		res.sum += temp[1];
		weightSum += temp[0];
	}
	return res;
}

int main(void) {
	int n,w;
	cin >> n;
	newMatrix(item, n, 2, 0);
	int n2 = n;
	while (n-- && cin >> item[n][0]);
	while (n2-- && cin >> item[n2][1]);
	sort(item.begin(), item.end(), cmp);

	cin >> n;
	while (n--&&cin>>w)
		printResult(knapsack(item, w));

	return 0;
}