#include <iostream>
using namespace std;


struct Node{
    int value;
    Node *next;
    Node (int x): value(x), next(NULL){}
};


class Solution{
public:
    Node *addTwoNumbers(Node *l1, Node *l2){
        Node *dummy = new Node(0);
        Node *temp = dummy;
        Node *p1 = l1;
        Node *p2 = l2;
        int carry = 0;
        for(;p1 != NULL || p2 != NULL;
            p1 = p1 == NULL ? NULL : p1->next, p2 = p2 == NULL ? NULL : p2->next, temp = temp->next ){
                int a = p1 == NULL ? 0 : p1->value;
                int b = p2 == NULL ? 0 : p2->value;
                int value = (a + b + carry) % 10;
                carry = (a + b + carry)/10 ;
                temp ->next = new Node(value);
            }
            if(carry > 0){
                temp->next = new Node(carry);
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

    Node *createList(int* nums, int length){
        Node *head = new Node(nums[0]);
        Node *p = head;
        for(int i = 1; i < length; i++){
            Node *temp = new Node(nums[i]);
            p->next = temp;
            p = p->next;
        }
        return head;
    }
};


int main()
{
    int a[] = {2, 4, 3};
    int b[] = {5, 6, 4};
    Solution s;
    Node *l1 = s.createList(a, 3);
    Node *l2 = s.createList(b ,3);

    s.print(l1);
    s.print(l2);
    Node *head = s.addTwoNumbers(l1, l2);
    s.print(head);
    return 0;
}
