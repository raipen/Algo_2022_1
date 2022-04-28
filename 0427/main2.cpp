#include <iostream>
#include <vector>
#include <algorithm>
#define newMatrix(n,s) vector<vector<int> > n(s, vector<int>(s , 0))
using namespace std;
typedef struct tr {
    char data;
    int freq;
    struct tr* left;
    struct tr* right;
}Tree;
typedef vector<Tree*> Heap;

Tree* newTreeNode(char a, int b) {
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    temp->data = a;
    temp->freq = b;
    temp->left = temp->right = NULL;
    return temp;
}

Tree* newTreeNode(Tree* a,Tree* b) {
    Tree* temp = (Tree*)malloc(sizeof(Tree));
    temp->data = '+';
    temp->freq = a->freq+b->freq;
    temp->left = a;
    temp->right = b;
    return temp;
}

void addHeap(Heap& heap, Tree* node) {
    heap.push_back(node);
    for (int i = heap.size()-1; i > 1; i /= 2)
        if (heap[i]->freq < heap[i / 2]->freq)
            swap(heap[i], heap[i / 2]);
}

Tree* removeHeap(Heap& heap) {
    if (heap.size() == 1) return NULL;
    Tree* temp = heap[1];
    heap[1] = heap[heap.size() - 1];
    heap.pop_back();
    for (int i = 1; i*2 < heap.size();) {
        int min = i * 2 + 1==heap.size() ? i * 2 : heap[i * 2]->freq < heap[i * 2 + 1]->freq ? i * 2 : i * 2 + 1;
        if(heap[i]->freq > heap[min]->freq)
            swap(heap[i], heap[min]);
        i = min;
    }
    return temp;
}

Tree* makeHuffmanTree(Heap heap) {
    while (heap.size() != 2) {
        Tree* temp1 = removeHeap(heap);
        Tree* temp2 = removeHeap(heap);
        addHeap(heap, newTreeNode(temp1, temp2));
    }
    return heap[1];
}

void preorder(Tree* ptr) {
    if (ptr) {
        cout << ptr->data << ":" << ptr->freq << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

typedef struct {
    char c;
    string s;
}HuffChar;
vector<HuffChar> map;

void inorder(Tree* ptr,string a) {
    if (ptr) {
        if (ptr->data != '+') {
            HuffChar temp = { ptr->data,a};
            map.push_back(temp);
        }
        inorder(ptr->left,a+ "0");
        cout << ptr->data << ":" << ptr->freq << " ";
        inorder(ptr->right,a+"1");
    }
}

string findMap(char a) {
    for (int i = 0; i < map.size(); i++)
        if (map[i].c == a)
            return map[i].s;
    return "";
}

string encode(Tree* h, string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        result += findMap(s[i]);
    }
    return result;
}

string decode(Tree* h, string s) {
    string result = "";
    Tree* cur = h;
    for (int i = 0; i < s.length(); i++) {
        cur = s[i] == '0' ? cur->left : cur->right;
        if (cur->data != '+') {
            result += cur->data;
            cur = h;
        }
    }
    return result;
}

int main() {
    // 허프만 트리 구성 정보 입력 받기
    int n;
    cin >> n;
    vector<char> charTemp(n);
    vector<int> intTemp(n);
    for (int i = 0; i < n; cin >> charTemp[i++]);
    for (int i = 0; i < n; cin >> intTemp[i++]);

    //힙 구성
    Heap heap;
    heap.push_back(NULL);//1번째부터 시작하게 하기 위해서 NULL값을 0번째 칸에 넣어둠
    for (int i = 0; i < n; addHeap(heap,newTreeNode(charTemp[i],intTemp[i])),i++);

    //허프만 트리 구성 후 출력
    Tree* huffman = makeHuffmanTree(heap);
    preorder(huffman);
    cout << endl;
    inorder(huffman,"");
    cout << endl;

    //인코딩
    cin >> n;
    string str;
    while (n-- && cin >> str)
        cout<<encode(huffman, str)<< endl;

    //디코딩
    cin >> n;
    while (n-- && cin >> str)
        cout << decode(huffman, str) << endl;
}