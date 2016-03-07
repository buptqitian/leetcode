#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int x):data(x), left(NULL), right(NULL) {}
};


class Solution{
public:
    Node *buildTree(int *preorder, int *inorder, int n){
        if(n <= 0){
            return NULL;
        }
        int rootValue = preorder[0];
        int i = getIndex(preorder, inorder, n);
        Node *root = new Node(rootValue);
        root->left = buildTree(preorder + 1, inorder, i);
        root->right = buildTree(preorder + i + 1, inorder + i + 1, n - i - 1);
        return root;
    }

    int getIndex(int *preorder, int *inorder, int n){
        int i = 0;
        int temp = preorder[0];
        for(; i < n; i++){
            if(inorder[i] == temp){
                return i;
            }
        }
        return -1;
    }
    void postorder(Node *root){
        if(root){
            postorder(root->left);
            postorder(root->right);
            cout << root->data;
        }
    }
};

int main()
{
    int pre[] = {1, 2, 4, 5, 3, 6};
    int in[] = {4, 2, 5, 1, 3, 6};
    Solution s;
    Node *root = s.buildTree(pre, in, 6);
    s.postorder(root);
    cout << endl;
}
