#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
    Node (int x): data(x), left(NULL), right(NULL) {};
};


class Solution{
public:
    Node *convert(int *nums, int n){
        if(n <= 0) return NULL;
        int mid = (n - 1)/2;
        Node *root = new Node(nums[mid]);
        root->left = convert(nums, mid);
        root->right = convert(nums + mid + 1, n - mid - 1);
        return root;
    }

    void inorder(Node *root){
        if(root){
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }
};

int main()
{
    int nums[] = {1, 2, 2, 8, 10, 19};
    Solution s;
    Node *result = s.convert(nums, 6);
    s.inorder(result);
    cout << endl;

}
