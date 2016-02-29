#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node (int x):value(x), next(NULL){}
};

class Solution{
public:
    Node *reverseBetween(Node *head, int m, int n){
        Node *dummy = new Node(0);
        dummy->next = head;

        Node *pre = dummy;
        for(int i = 0; i < m - 1; i++){
            pre = pre->next;
        }
        Node *cur = pre->next->next;
        Node *temp = pre->next;
        for(int i = 0; i < n - m; i++){
            temp->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = temp->next;
        }
        return dummy->next;
    }

    void print(Node *head){
        Node *p = head;
        while(p){
            cout << p->value << endl;
            p = p->next;
        }
    }
};


int main()
{
    Node *head = new Node(1);
    Node *p = head;
    for(int i = 2; i <= 5; i++){
        Node *temp = new Node(i);
        p->next = temp;
        p = p->next;
    }

    Solution s;
    s.print(head);
    Node *result = s.reverseBetween(head, 2, 5);
    s.print(result);

}
