#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef struct node* NODE;
typedef struct node {
    char symbol;
    int frequency;
    NODE l, r;
};

struct COMPARE {
    bool operator()(NODE p, NODE q) {
        return p->frequency > q->frequency;
    }
};

typedef priority_queue<NODE, vector<NODE>, COMPARE> PRIORITYQUEUE;

NODE create(char S, int F) {
    NODE t = (NODE)malloc(sizeof(struct node));
    t->symbol = S;
    t->frequency = F;
    t->l = t->r = NULL;

    return t;
}

void huffman(int N, PRIORITYQUEUE& PQ) {
    for (int i = 1; i < N; i++) {
        NODE p = PQ.top();
        PQ.pop();
        NODE q = PQ.top();
        PQ.pop();
        NODE r = create('+', p->frequency + q->frequency);
        r->l = p;
        r->r = q;
        PQ.push(r);
    }
}

void encode(NODE root, vector<int>& code, map<char, vector<int>>& encoder) {
    if (root->symbol != '+') {
        vector<int> R(code.size());
        copy(code.begin(), code.end(), R.begin());
        encoder.insert(make_pair(root->symbol, R));
    }
    else if (root != NULL) {
        code.push_back(0);
        encode(root->l, code, encoder);
        code.pop_back();
        code.push_back(1);
        encode(root->r, code, encoder);
        code.pop_back();
    }
}

void preorder(NODE root) {
    if (root) {
        cout << root->symbol << ":" << root->frequency << " ";
        preorder(root->l);
        preorder(root->r);
    }
}

void inorder(NODE root) {
    if (root) {
        inorder(root->l);
        cout << root->symbol << ":" << root->frequency << " ";
        inorder(root->r);
    }
}

string decode(NODE root, string code) {
    string result = "";
    NODE cur = root;
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == '0') {
            cur = cur->l;
        }
        else {
            cur = cur->r;
        }

        if (cur->symbol != '+') {
            result += cur->symbol;
            cur = root;
        }
    }
    return result;
}


int main() {
    int N, T1, T2;
    NODE H = NULL;
    cin >> N;
    PRIORITYQUEUE PQ;

    vector<char> charV(N);
    vector<int> intV(N);

    for (int i = 0; i < N; i++) cin >> charV[i];
    for (int i = 0; i < N; i++) cin >> intV[i];

    for (int i = 0; i < N; i++) {
        H = create(charV[i], intV[i]);
        PQ.push(H);
    }

    huffman(N, PQ);

    preorder(PQ.top());
    cout << endl;
    inorder(PQ.top());
    cout << endl;

    vector<int> code;
    map<char, vector<int>> encoder;
    encode(PQ.top(), code, encoder);

    cin >> T1;
    string S1;
    for (int i = 0; i < T1; i++) {
        cin >> S1;
        for (int k = 0; k < S1.length(); k++) {
            vector<int> temp = encoder.find(S1[k])->second;
            for (int j = 0; j < temp.size(); j++)
                cout << temp[j];
        }
        cout << endl;
    }

    for (int i = 0; i < T2; i++) {
        cin >> S1;
        cout << decode(PQ.top(), S1) << endl;
    }
}