#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node (int x):value(x), next(NULL) {};
};


class Solution{
public:
    Node * partition(Node *head, int x){
        Node *left = new Node(-1);
        Node *right = new Node(-1);
        Node *left_cur = left;
        Node *right_cur = right;
        Node *p = head;
        while(p){
            if(p->value < x){
                left_cur->next = p;
                left_cur = left_cur->next;
            }else{
                right_cur->next = p;
                right_cur = right_cur->next;
            }
            p = p->next;
        }
        left_cur->next = right->next;
        right_cur->next = NULL;
        return left->next;
    }

    void print(Node *head){
        Node *p = head;
        while(p){
            cout << p->value << endl;
            p = p->next;
        }
    }

    Node * createList(int *nums, int length){
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
    int a[] = {1, 4, 3, 2, 5, 2};
    Solution s;
    Node *head = s.createList(a, 6);
    s.print(head);
    cout << "------------" << endl;
    Node * temp_head = s.partition(head, 3);
    s.print(temp_head);

}
