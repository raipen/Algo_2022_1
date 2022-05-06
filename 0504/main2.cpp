#include <iostream>
#include <vector>
#include <algorithm>
#define newMatrix(n,s1,s2,i) matrix n(s1, vector<int>(s2 , i))
using namespace std;
typedef vector<vector<int> > matrix;

int W;
vector<int> w;
vector<bool> include;
matrix result;

void printMatrix(matrix a) {
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < a[i].size(); j++)
            cout << a[i][j] << (j == a[i].size() - 1 ? "\n" : " ");
}

bool promising(int i, int weight, int total) {
    return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W);
}

void sum_of_subsets(int i, int weight, int total) {
    if (promising(i, weight, total)) {
        if (weight == W) {
            vector<int> temp;
            for (int k = 1; k <= i; k++)
                if (include[k])
                    temp.push_back(w[k]);
            result.push_back(temp);
        }
        else {
            include[i + 1] = true;
            sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1]);
            include[i + 1] = false;
            sum_of_subsets(i + 1, weight, total - w[i + 1]);
        }
    }
}

int main() {
    int n, t, sum = 0;
    cin >> n >> W;
    include.assign(n+1,false);
    w.push_back(0);
    while (n-- && cin >> t) {
        w.push_back(t);
        sum += t;
    }
    sum_of_subsets(0, 0, sum);
    cout << result.size()<<endl;
    printMatrix(result);
}