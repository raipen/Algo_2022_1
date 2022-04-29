#include <iostream>
#include <vector>
#include <algorithm>
#define newMatrix(n,s1,s2,i) matrix n(s1, vector<int>(s2 , i))
using namespace std;
typedef vector<vector<int> > matrix;

int sum = 0;

void printSchedule(matrix a) {
    for (int i = 0; i < a.size(); i++)
            cout << a[i][1] << (i == a.size() - 1 ? "\n" : " ");
}

bool is_feasible(matrix a) {
    for (int i = 0; i < a.size(); i++)
        if (i + 1 > a[i][0])
            return false;
    return true;
}

matrix maxProfit(matrix& a) {
    matrix result;
    result.push_back(a[0]);
    sum += a[0][1];
    matrix temp;
    for (int i = 1; i < a.size(); i++) {
        temp.resize(result.size());
        copy(result.begin(), result.end(), temp.begin());
        int j = 0;
        while (j < temp.size() && temp[j][0] <= a[i][0])
            j++;
        temp.insert(temp.begin() + j, a[i]);
        if (is_feasible(temp)) {
            sum += a[i][1];
            result.resize(temp.size());
            copy(temp.begin(), temp.end(), result.begin());
        }
    }
    return result;
}

bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[1] > v2[1];
}

int main() {
    int n,n2;
    cin >> n;
    n2 = n;
    newMatrix(deadline, n, 2, 0);
    while (n-- && cin >> deadline[n][0]);
    while (n2-- && cin >> deadline[n2][1]);
    sort(deadline.begin(), deadline.end(), cmp);
    matrix maxSchedule = maxProfit(deadline);
    cout << sum<<endl;
    printSchedule(maxSchedule);
    return 0;
}
