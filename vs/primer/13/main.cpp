#include <iostream>
#include <string>
using namespace std;
struct X
{
    X() {cout << "X()" << endl;}
    X(const X&) {cout << "X(const X&)" << endl;}
    X operator= (X &x)
    {

    }   
    ~X(){} 
};


class TreeNode
{
public:
    TreeNode() = default;
    TreeNode(string val) : value(val), count(1), left(nullptr), right(nullptr) {}
    TreeNode(TreeNode &node)
    {
        value = node.value;
        count = node.count;
        left = node.left;
        right = node.right;
    }

    TreeNode &operator=(TreeNode &node)
    {
        value = node.value;
        count = node.count;
        left = node.left;
        right = node.right;
        if (left)
            left->CopyTree();
        if (right)
            right->CopyTree();
    }

    void CopyTree()
    {
        if (left)
            left->CopyTree();
        if (right)
            right->CopyTree();
        ++count;
    }
private:
    string value;
    int count;
    TreeNode *left;
    TreeNode *right;
};


class BinStrTree
{
public:
    BinStrTree(BinStrTree &bst)
    {
        root = bst.root;
        root->CopyTree();
    }
private:
    TreeNode *root;
};