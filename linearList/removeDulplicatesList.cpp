#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node (int x): value(x), next(NULL) {};
};

class Solution{
public:
    Node *removeDulplicate(Node *head){
        if(head == NULL) return NULL;
        for(Node *prev = head, *cur = head->next; cur; cur = cur->next){
            if(prev->value == cur->value){
                prev->next = cur->next;
                delete cur;
            }else{
                prev = cur;
            }
        }
        return head;
    }


    void print(Node *head){
        Node *p = head;
        while(p){
            cout << p->value << endl;
            p = p->next;
        }
    }

    Node * createList(int *nums, int size){
        Node *head = new Node(nums[0]);
        Node *p = head;
        for(int i = 1; i < size; i++){
            Node *temp = new Node(nums[i]);
            p->next = temp;
            p = p->next;
        }
        return head;
    }
};

int main()
{
    int a[] = {1, 1, 2};
    Solution s;
    Node *head = s.createList(a, 3);
    s.print(head);
    cout << "-----" << endl;
    Node *temp_head = s.removeDulplicate(head);
    s.print(temp_head);
}
