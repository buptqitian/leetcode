#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int x): data(x), left(NULL), right(NULL){}
};



class Solution{
public:
    int find(int *nums, int length, int target){
        for(int i = 0; i < length; i++){
            if(nums[i] == target){
                return i;
            }
        }
    }

    Node *buildTree(int *preorder, int *inorder, int n){
        if(n <= 0) return NULL;
        Node *root = new Node(preorder[0]);
        int i = find(inorder, n, preorder[0]);
        root->left = buildTree(preorder + 1, inorder, i);
        root->right = buildTree(preorder + i + 1, inorder + i + 1, n - i - 1);
        return root;
    }

    void postorder(Node *root){
        if(root == NULL) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << endl;
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
