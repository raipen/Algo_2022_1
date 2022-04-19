#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int t, cnt = 0;

void printLarge(string a) {
    reverse(a.begin(), a.end());
    cout << a;
}

string addLarge(string a, string b) {
    vector<int> r;
    int k = 0, i = 0, carry = 0;
    while (k < a.length() && k < b.length()) {
        r.push_back(a[k] - '0' + b[k] - '0');
        k++;
    }
    while (k < a.length())
        r.push_back(a[k++] - '0');
    while (k < b.length())
        r.push_back(b[k++] - '0');
    string re = "";
    while (i < k) {
        int d = r[i++] + carry;
        re += d % 10 + '0';
        carry = d / 10;
    }
    if (carry)
        re += carry + '0';
    return re;
}

string addLarge(string a, string b, string c) {
    return addLarge(addLarge(a, b), c);
}

// string subLarge(string a, string b) {
//     vector<int> r;
//     int k = 0, i = 0, carry = 0;
//     while (k < a.length() && k < b.length()) {
//         r.push_back(a[k] - '0' - b[k] + '0');
//         k++;
//     }
//     while (k < a.length())
//         r.push_back(a[k++] - '0');
//     while (k < b.length())
//         r.push_back(-b[k++] + '0');
//     r.push_back(0);
//     string re = "";
//     while (i < k) {
//         if(r[i]<0){
//             r[i+1]--;
//             r[i] += 10;
//         }
//         re += r[i++] +'0';
//     }
//     if (r[k])
//         re += '-';
//     return re;
// }

// string subLarge(string a, string b, string c) {
//     return subLarge(subLarge(a, b), c);
// }

string multLarge(string a, string b) {
    vector<int> r(a.length() + b.length() - 1, 0);
    for (int i = 0; i < b.length(); i++)
        for (int j = 0; j < a.length(); j++)
            r[i + j] += (b[i] - '0') * (a[j] - '0');
    string re = "";
    int i = 0, carry = 0;
    for (; i < r.size(); i++) {
        int d = r[i] + carry;
        re += d % 10 + '0';
        carry = d / 10;
    }
    if (carry)
        re += carry + '0';
    return re;
}

string powLarge(string a, int m) {
    while (m--)
        a = "0" + a;
    return a;
}

string divideLarge(string a, int m) {
    return a.length() <= m ? "0" : a.substr(m);
}

string removeLeadingZeros(string a) {
    int i = a.length() - 1;
    while (i > 0 && a[i] == '0') i--;
    return a.substr(0, i + 1);
}

string remLarge(string a, int m) {
    return removeLeadingZeros(a.substr(0, m));
}

void prod(string a, string b) {
    cnt++;
   /* printLarge(a);
    cout << " ";
    printLarge(b);
    cout << endl;*/
    if (!a.compare("0") || !b.compare("0"))
        return;
    int max = a.length() > b.length() ? a.length() : b.length();
    if (max <= t)
        return;
    prod(divideLarge(a, max / 2), divideLarge(b, max / 2));
    prod(addLarge(divideLarge(a, max / 2), remLarge(a, max / 2)), addLarge(divideLarge(b, max / 2), remLarge(b, max / 2)));
    prod(remLarge(a, max / 2), remLarge(b, max / 2));
    // return max<=t? multLarge(a, b) :
    // removeLeadingZeros(addLarge(
    //     powLarge(prod(divideLarge(a, max / 2), divideLarge(b, max / 2)), (max / 2) * 2),
    //     powLarge(addLarge(prod(divideLarge(a, max / 2), remLarge(b, max / 2)), prod(divideLarge(b, max / 2), remLarge(a, max / 2))), max / 2),
    //     prod(remLarge(a, max / 2), remLarge(b, max / 2))
    // ));
}

int main() {
    string str[2];
    cin >> t >> str[0] >> str[1];
    reverse(str[0].begin(), str[0].end());
    reverse(str[1].begin(), str[1].end());
    prod(str[0], str[1]);
    cout << cnt << endl;
    // printLarge(prod(str[0], str[1]));
    return 0;
}