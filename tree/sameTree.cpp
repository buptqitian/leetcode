#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int x):data(x), left(NULL), right(NULL){}
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

    bool isSame(Node *t1, Node *t2){
        if(!t1 && !t2) return true;
        if(!t2 || !t2) return false;
        return t1->data == t2->data && isSame(t1->left, t2->left) &&
        isSame(t1->right, t2->right);
    }
};

int main()
{
    int pre[] = {1, 2, 4, 5, 3, 6};
    int in[] = {4, 2, 5, 1, 3, 6};
    Solution s;
    Node *t1 = s.buildTree(pre, in, 6);
    Node *t2 = s.buildTree(pre, in, 6);
    cout << s.isSame(t1, t2) << endl;
}
