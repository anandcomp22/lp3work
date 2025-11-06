#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int val;
    Node *left;
    Node *right;
    Node(char c, int x) {
        ch = c;
        val = x;
        left = right = nullptr;
    }
};

struct compare {
    bool operator()(Node* a, Node* b) {
        return a->val > b->val;
    }
};

void PrintHuffmanCode(Node* root, string code) {
    if(!root) {
        return;
    }

    if(!root->left && !root->right) {
        if(code == "") code = "0";
        cout<<root->ch<<" : "<<code<<endl;
    }

    PrintHuffmanCode(root->left, code + "0");
    PrintHuffmanCode(root->right, code + "1");
}

void HuffmanEncoding(string text) {
    unordered_map<char, int> freq;
    for(char c : text) {
        freq[c]++;
    }

    priority_queue<Node*, vector<Node*>, compare> pq;

    for(auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while(pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('$', left->val + right->val);
        sum->left = left;
        sum->right = right;

        pq.push(sum);
    }

    Node* root = pq.top();
    cout<<"Huffman Code : "<<endl;
    PrintHuffmanCode(root, "");
    
}

int main() {
    string text;
    cout<<"Enter String : ";
    getline(cin,text);

    HuffmanEncoding(text);
    return 0;
}