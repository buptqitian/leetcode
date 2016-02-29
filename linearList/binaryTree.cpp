#include <iostream>
using namespace std;



struct Node{
    int data;
    Node *left, *right;
    Node (int x): data(x), left(NULL), right(NULL) {};
};


class Btree{
public:
    Node *root;
    Btree(){
        root = NULL;
    }

    void insert(int);
    void pre_order(Node *);
    void in_order(Node *);
    void post_order(Node *);

};


void Btree::pre_order(Node *root){
    if(root != NULL){
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
}

void Btree::in_order(Node *root){
    if(root != NULL){
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
    }
}

void Btree::post_order(Node *root){
    if(root != NULL){
        post_order(root->left);
        post_order(root->right);
        cout << root->data << " ";
    }
}


void Btree::insert(int x){
    Node *p = new Node(x);
    if(root == NULL){
        root = p;
    }else{
        Node *temp = root;
        Node *back;
        while(temp){
            back = temp;
            if(x < temp->data){
                temp = temp->left;
            }else{
                temp = temp->right;
            }
        }
        if(x < back->data){
            back->left = p;
        }else{
            back->right = p;
        }
    }
}



int main()
{
    Btree t;
    int a [] = {10, 2, 11, 13, 19, 8};
    for(int i = 0; i < 6; i++){
        t.insert(a[i]);
    }

    t.in_order(t.root);

    return 0;
}
