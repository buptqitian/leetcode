#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x): data(x), next(NULL) {};
};


void print(Node *root){
    Node *p = root;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Node *reverse(Node *root){
    Node *dummy = new Node(-1);
    dummy->next = root;
    Node *pre = root;
    Node *p = pre->next;
    while(p){
        pre->next = p->next;
        p->next = dummy->next;
        dummy->next = p;
        p = pre->next;
    }
    return dummy->next;
}

int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    Node *root = new Node(nums[0]);
    Node *p = root;
    for(int i = 1; i < 5; i++){
        Node *temp = new Node(nums[i]);
        p->next = temp;
        p = p->next;
    }
    print(root);
    Node *result = reverse(root);
    print(result);
}
