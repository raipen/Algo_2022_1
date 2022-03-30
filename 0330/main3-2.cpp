//경로가 필요 없다면 공간복잡도 O(n)으로 해결 ㄱㄴ
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, temp, m = 0;
    cin >> N;
    vector<int> D(N + 1, 0);
    for (int i = 1; i <= N; i++)
        for (int j = i; j > 0; j--) {
            cin >> temp;
            D[j] = D[j] + temp > D[j - 1] + temp ? D[j] + temp : D[j - 1] + temp;
        }
    for (int i = 1; i <= N; i++)
        m = m >= D[i] ? m : D[i];
    cout << m;
}