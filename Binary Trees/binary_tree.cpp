#include <iostream>

using namespace std;

class TreeNode; // forward declaration

class Tree{
public:
    TreeNode* root = nullptr;

    Tree(TreeNode* r) : root(r) {} 
};

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) { }

    void show(TreeNode* cur){
        if (cur) cout << cur->data << " " ;
    }
    void preOrder(TreeNode* cur){
        if (cur!= nullptr){
            show(cur);
            preOrder(cur->left);
            preOrder(cur->right);
        }
    }

    void inOrder(TreeNode* cur){
        if (cur!= nullptr){
            inOrder(cur->left);
            show(cur);
            inOrder(cur->right);
        }
    }

    void postOrder(TreeNode* cur){
        if (cur!= nullptr){
            postOrder(cur->left);
            postOrder(cur->right);
            show(cur);
        }
    }
};

int main(){
    TreeNode* root = new TreeNode(10);
    Tree* myTree = new Tree(root);

    TreeNode* second =  new TreeNode(5);
    TreeNode* third = new TreeNode(20);
    TreeNode* four = new TreeNode(3);
    TreeNode* five = new TreeNode(7);


    root->left = second;
    root->right = third;
    second->left = four;
    second->right = five;

    root->preOrder(root);
    root->inOrder(root);
    root->postOrder(root);

    return 0;
}
