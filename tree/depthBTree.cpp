#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int x) : data(x), left(NULL), right(NULL) {};
};

class Solution{
public:
    int find(int *nums, int n, int target){
        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                return i;
            }
        }
    }

    Node *constructTree(int *preorder, int *inorder, int n){
        if(n <= 0) return NULL;
        Node *root = new Node(preorder[0]);
        int i = find(inorder, n, preorder[0]);
        root->left = constructTree(preorder + 1, inorder, i);
        root->right = constructTree(preorder + i + 1, inorder + i + 1, n - i - 1);
        return root;
    }

    void postorder(Node *root){
        if(root){
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }

    int depthBTree(Node *root){
        if(!root) return 0;
        return 1 + max(depthBTree(root->left), depthBTree(root->right));
    }
};

int main()
{
    int pre[] = {1, 2, 4, 7, 8, 5, 3, 6};
    int in[] = {7, 4, 8, 2, 5, 1, 3, 6};
    Solution s;
    Node *root = s.constructTree(pre, in, 8);
    s.postorder(root);
    cout << endl;

    cout << s.depthBTree(root) << endl;

}
