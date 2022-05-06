//교수님 방식
#include <iostream>
#include <vector>
using namespace std;

int cnt, N;
string MAX = "", col;

bool promising(int i) {
    int k = 1;
    bool F = true;
    while (k < i && F) {
        if ((col[i] == col[k]) || (abs(col[i] - col[k]) == i - k)) F = false;
        k++;
    }
    return F;
}

string int2char(int a) {
    string result = "";
    for (; a; a /= 10)
        result = (char)(a % 10 + '0') + result;
    return result;
}

void queens(int i) {
    int j;
    if (promising(i)) {
        if (i == N) {
            cnt++;
            string temp = "";
            for (int k = 1; k <= i; k++) {
                temp += int2char(col[k]);
            }
            MAX = MAX > temp ? MAX : temp;
        }
        else {
            for (j = 1; j < N + 1; j++) {
                col[i + 1] = j;
                queens(i + 1);
            }
        }
    }
}

int main() {
    cin >> N;
    col.resize(N + 1);
    MAX.resize(N + 1);

    queens(0);
    cout << cnt << endl << MAX;
}