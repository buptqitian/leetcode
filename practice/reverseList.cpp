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

Node *tailConstruct(int *nums, int length){
    Node *dummy = new Node(-1);
    Node *p = dummy;
    for(int i = 0; i < length; i++){
        Node *temp = new Node(nums[i]);
        p->next = temp;
        p = p->next;
    }
    return dummy->next;
}

Node *headConstruct(int *nums, int length){
    Node *dummy = new Node(-1);
    for(int i = 0; i < length; i++){
        Node *temp = new Node(nums[i]);
        temp->next = dummy->next;
        dummy->next = temp;
    }
    return dummy->next;
}



int main()
{
    int nums[] = {1, 2, 3, 4, 5};
    print(headConstruct(nums, 5));
    print(tailConstruct(nums, 5));
}
