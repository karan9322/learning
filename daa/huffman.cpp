#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

class Compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void printCode(Node *root, string code)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->ch << " : " << code << endl;
        return;
    }

    printCode(root->left, code + "0");
    printCode(root->right, code + "1");
}

int main()
{
    priority_queue<Node*, vector<Node*>, Compare> pq;

    pq.push(new Node('A', 5));
    pq.push(new Node('B', 9));
    pq.push(new Node('C', 12));
    pq.push(new Node('D', 13));
    pq.push(new Node('E', 16));
    pq.push(new Node('F', 45));

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *parent = new Node('-', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node *root = pq.top();

    cout << "Huffman:" << endl;
    printCode(root, "");

    return 0;
}