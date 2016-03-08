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

Node *mergeList(Node *a1, Node *a2){
    Node *dummy = new Node(-1);
    Node *p = a1, *q = a2, *k = dummy;
    while(p && q){
        if(p->data < q->data){
            k->next = p;
            p = p->next;
        }else{
            k->next = q;
            q = q->next;
        }
        k = k->next;
    }

    if(!p && q){
        while(q){
            k->next = q;
            q = q->next;
            k = k->next;
        }
    }else{
        while(p){
            k->next = p;
            p = p->next;
            k = k->next;
        }
    }
    return dummy->next;
}

int main()
{
    vector<int> a1 = {1, 3, 6, 7, 10};
    vector<int> a2 = {0, 4, 7, 8, 9, 10, 11};
    print(mergeList(tailConstruct(a1), tailConstruct(a2)));
}
