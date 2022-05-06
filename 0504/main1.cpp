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

Tree* newTreeNode() {
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    temp->child = temp->sibling = temp->parent = NULL;
    return temp;
}

Tree* newTreeNode(int row,int col) {
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
    for (int i = row; i > 1; i--,parent = parent->parent)
        if (parent->col == col||(parent->row) - row == (parent->col) - col|| (parent->row) - row == col - (parent->col))
            return false;
    return true;
}

void addQueen(Tree* parent,int n, int row, int col) {
    if(checkQueen(parent,row,col)){
        addChild(parent,newTreeNode(row,col));
        if(row==n)
            return;
        for (int i = 1; i <= n; i++)
            addQueen(parent->child,n,row+1, i);
        if (!(parent->child->child))
            removeChild(parent);
    }
}

Tree* nQueens(int n,int row) {
    Tree* root = newTreeNode();
    for (int i = 1; i <= n; i++)
        addQueen(root,n,row+1, i);
    return root;
}

vector<string> result;

string int2char(int a) {
    string result = "";
    for (; a; a /= 10)
        result = (char)(a % 10 + '0') + result;
    return result;
}

void order(Tree* ptr, string str,int n) {
    if (ptr) {
        if (ptr->row == n)
            result.push_back(str+ int2char(ptr->col));
        order(ptr->child, str + int2char(ptr->col),n);
        order(ptr->sibling, str,n);
    }
}

bool cmp(string& a, string& b) {
    return a > b;
}

int main() {
   int n;
   cin >> n;
   Tree* chess = nQueens(n,0);
    order(chess->child, "", n);
    cout << result.size() << endl;
    sort(result.begin(), result.end(),cmp);
    cout << result[0] << endl;
}