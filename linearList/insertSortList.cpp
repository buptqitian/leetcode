#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node (int x):data(x), next(NULL) {};
};

void print(Node *root){
    Node *p = root;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

Node *tailConstruct(vector<int> nums){
    Node *dummy = new Node(-1);
    Node *p = dummy;
    for(int i = 0; i < nums.size(); i++){
        Node *temp = new Node(nums[i]);
        p->next = temp;
        p = p->next;
    }
    return dummy->next;
}


Node *insertionSortList(Node *head) {
    if(head == NULL) return NULL;
    Node *p, *q, *current;
    //q = NULL;
    Node *head2 = head->next;
    head->next = NULL;
    while(head2){
        current = head2;
        head2 = head2->next;
        current->next = NULL;
        p = head;

        while(p && (p->data <= current->data)){
            q = p;
            p = p->next;

        }
        if(p == head){
            current = head;
            current->next = p;
        }else{
            current->next = p;
            q->next = current;
        }

    }
    return head;
}
int main()
{
    vector<int> a1 = {1, 3, 4};
    print(tailConstruct(a1));
    print(insertionSortList(tailConstruct(a1)));
}
