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

bool cmp(vector<int>& v1, vector<int>& v2) {
   return v1[1] * v2[0] > v2[1] * v1[0];
}

map<pair<int, int>, int> P;

void printResult() {
   for (auto& item : P) {
      cout << item.first.first<<" "<<item.first.second<<" "<<item.second<<endl;
   }
}

int knapsack(matrix& item, int n,int w) {
   if (P.count({n, w})) return P[{n, w}];
   if (!(n && w)) return 0;

   int temp = knapsack(item, n - 1, w);
   if (item[n-1][0] <= w && temp < item[n-1][1] + knapsack(item, n - 1, w - item[n-1][0]))
      temp = item[n-1][1] + knapsack(item, n - 1, w - item[n-1][0]);
   P.insert({ {n,w},temp});
   return temp;
}

int main(void) {
   int n, w;
   cin >> n;
   newMatrix(item, n+1, 2, 0);
   for (int i = 0; i < n; cin >> item[i][0], i++);
   for (int i = 0; i < n; cin >> item[i][1], i++);
   sort(item.begin(), item.end(), cmp);

   int T;
   cin >> T;
   while (T-- && cin >> w) {
      P.clear();
      cout << knapsack(item, n, w)<<endl;
      printResult();
   }

   return 0;
}