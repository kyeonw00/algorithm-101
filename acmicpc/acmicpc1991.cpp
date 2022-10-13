#include <iostream>
#include <vector>
#define TREEMAX 26

using namespace std;

struct Node { char LeftChild; char RightChild; };

vector<Node> Tree(TREEMAX);

void preOrderSearch(char node)
{
    if (node == '.')
    {
        return;
    }

    cout << node;
    preOrderSearch(Tree[node].LeftChild);
    preOrderSearch(Tree[node].RightChild);
}

void inOrderSearch(char node)
{
    if (node == '.')
    {
        return;
    }

    inOrderSearch(Tree[node].LeftChild);
    cout << node;
    inOrderSearch(Tree[node].RightChild);
}

void postOrderSearch(char node)
{
    if (node == '.')
    {
        return;
    }

    postOrderSearch(Tree[node].LeftChild);
    postOrderSearch(Tree[node].RightChild);
    cout << node;
}

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    char root, leftChild, rightChild;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> root >> leftChild >> rightChild;
        Tree[root].LeftChild = leftChild;
        Tree[root].RightChild = rightChild;
    }

    preOrderSearch('A');
    cout << endl;
    inOrderSearch('A');
    cout << endl;
    postOrderSearch('A');

    return 0;
}