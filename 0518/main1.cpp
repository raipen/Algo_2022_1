#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define newMatrix(n,s1,s2,i) matrix n(s1, vector<int>(s2 , i))
using namespace std;
typedef vector<vector<int> > matrix;
struct ITEM {
    int level;
    int weight;
    int profit;
    int bound;
    ITEM() {}
    ITEM(int a, int b) : weight(a), profit(b) {}
    ITEM(int i, int a, int b, int c) : level(i), weight(a), profit(b), bound(c) {}
};
struct ITEMcmp {
    bool operator()(ITEM a, ITEM b) {
        return a.bound < b.bound;
    }
};

int n, W;
vector<ITEM> item;

bool cmp(ITEM& v1, ITEM& v2) {
    return v1.profit * v2.weight > v2.profit * v1.weight;
}

int bound(int i, int w, int p) {
    if (w >= W) return 0;
    float result = p;
    int total = w, j = i + 1;
    while (j <= n && total + item[j].weight <= W) {
        total += item[j].weight;
        result += item[j].profit;
        j++;
    }
    if (j <= n)
        result += (W - total) * ((float)item[j].profit / item[j].weight);
    return result;
}

ITEM newITEM(int i, int a, int b) {
    return ITEM(i, a, b, bound(i, a, b));
}

void printITEM(ITEM item) {
    cout << item.level << " " << item.weight << " " << item.profit << " " << item.bound << endl;
}

int knapsack() {
    priority_queue<ITEM, vector<ITEM>, ITEMcmp> Q;

    int maxProfit = 0;
    Q.push(newITEM(0, 0, 0));
    printITEM(Q.top());
    ITEM cur, temp;
    while (!Q.empty()) {
        cur = Q.top();
        Q.pop();
        if (cur.bound <= maxProfit)
            continue;
        temp = newITEM(cur.level + 1, cur.weight + item[cur.level + 1].weight, cur.profit + item[cur.level + 1].profit);
        printITEM(temp);
        if (temp.weight <= W && temp.profit > maxProfit)
            maxProfit = temp.profit;
        if (temp.bound > maxProfit)
            Q.push(temp);
        temp = newITEM(cur.level + 1, cur.weight, cur.profit);
        printITEM(temp);
        if (temp.bound > maxProfit)
            Q.push(temp);
    }
    return maxProfit;
}

int main(void) {
    cin >> n >> W;
    item.assign(n + 1, ITEM(0, 0));
    for (int i = 1; i <= n; cin >> item[i].weight, i++);
    for (int i = 1; i <= n; cin >> item[i].profit, i++);
    sort(item.begin()+1, item.end(), cmp);
    cout << knapsack() << endl;
    return 0;
}