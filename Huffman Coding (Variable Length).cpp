#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& huffman) {
    if (!root) return;

    if (root->ch != '$')
        huffman[root->ch] = code;

    generateCodes(root->left, code + "0", huffman);
    generateCodes(root->right, code + "1", huffman);
}

int main() {
    string text;
    cout << "Enter the text: ";
    cin >> text;

    map<char, int> freq;
    for (char c : text)
        freq[c]++;

    cout << "Frequencies:\n";
    for (auto it : freq)
        cout << it.first << " : " << it.second << endl;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto it : freq)
        pq.push(new Node(it.first, it.second));

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    map<char, string> huffmanCode;
    generateCodes(pq.top(), "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for (auto it : huffmanCode)
        cout << it.first << " : " << it.second << endl;

    int original = text.length() * 8;
    int compressed = 0;

    for (auto it : freq)
        compressed += it.second * huffmanCode[it.first].length();

    int table_bits = 0;

    for (auto it : freq) {
        table_bits += 8;
        table_bits += huffmanCode[it.first].length();
    }

    cout << "\nOriginal Length : " << original << endl;
    cout << "Compressed Length : " << compressed << endl;
    cout << "Table : " << table_bits << endl;
    cout << "New Length : " << compressed + table_bits << endl;

    return 0;
}
