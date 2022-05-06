#include <iostream>
#include <vector>
#include <algorithm>
#define newMatrix(n,s1,s2,i) matrix n(s1, vector<int>(s2 , i))
using namespace std;
typedef vector<vector<int> > matrix;

typedef struct tr {
    int col;
    int row;
    struct tr* child;
    struct tr* sibling;
    struct tr* parent;
}Tree;

int cnt = 0;

Tree* newTreeNode() {
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    temp->child = temp->sibling = temp->parent = NULL;
    return temp;
}

Tree* newTreeNode(int row, int col) {
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    temp->row = row;
    temp->col = col;
    temp->child = temp->sibling = temp->parent = NULL;
    return temp;
}

void addChild(Tree* parent, Tree* child) {
    child->sibling = parent->child;
    parent->child = child;
    child->parent = parent;
}

void removeChild(Tree* parent) {
    parent->child = parent->child ? parent->child->sibling : NULL;
}

bool checkQueen(Tree* parent, int row, int col) {
    for (int i = row; i > 1; i--, parent = parent->parent)
        if (parent->col == col || (parent->row) - row == (parent->col) - col || (parent->row) - row == col - (parent->col))
            return false;
    return true;
}

void addQueen(Tree* parent, int n, int row, int col) {
    if (checkQueen(parent, row, col)) {
        addChild(parent, newTreeNode(row, col));
        if (row == n) {
            cnt++;
            return;
        }
        for (int i = 1; i <= n; i++)
            addQueen(parent->child, n, row + 1, i);
        if (!(parent->child->child))
            removeChild(parent);
    }
}

Tree* nQueens(int n, int row) {
    Tree* root = newTreeNode();
    for (int i = 1; i <= n; i++)
        addQueen(root, n, row + 1, i);
    return root;
}

string int2char(int a) {
    string result = "";
    for (; a; a /= 10)
        result = (char)(a % 10 + '0') + result;
    return result;
}

Tree* maxSibling(Tree* ptr) {
    Tree* max = ptr;
    for (ptr = ptr->sibling; ptr; ptr = ptr->sibling)
        max = int2char(max->col) > int2char(ptr->col)?max:ptr;
    return max;
}

string findMax(Tree* ptr,  int n) {
    string result = "";
    for (int i = 1; i <= n; i++,ptr = ptr->child) {
        ptr = maxSibling(ptr);
        result += int2char(ptr->col);
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    Tree* chess = nQueens(n, 0);
    cout << cnt << endl;
    cout << findMax(chess->child,n)<< endl;
}