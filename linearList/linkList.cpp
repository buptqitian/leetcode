#include <iostream>
using namespace std;

class List{
public:
    List(){ create_list();};
    ~List(){ clear(); };

    void create_list();
    void insert_head(int val);
    void insert_pos(int val, int pos);

    void erase(int val);
    void update(int val, int pos);
    void reverse();
    void print();
private:
    struct Node{
        int data;
        Node *next;
        Node  (int x): data(x), next(NULL) {}
    };
    Node *head;
    void clear(){
        Node *p = head;
        while(p){
            Node *q = p->next;
            delete p;
            p = q;
        }
    }

    Node *find_val(int val){
        Node *p = head;
        while(p){
            if(p->next->data == val){
                break;
            }
            p = p->next;
        }
        return p;
    }

    Node *find_pos(int pos){
        Node *p = head;
        int count = 0;
        while(p){
            if(count == pos){
                break;
            }
            p = p->next;
            count++;
        }
        return p;
    }
};

void List::create_list()
{
    head = new Node(0);
}

void List::insert_head(int val)
{
    Node *p = new Node(val);
    p->next = head->next;
    head->next = p;
}
void List::insert_pos(int val, int pos)
{
    Node *p = find_pos(pos);
    Node *q = new Node(val);

    q->next = p->next;
    p->next = q;

}
void List::print()
{
    for(Node *p = head->next; p; p = p->next){
        cout << p->data << endl;
    }
}
void List::erase(int val)
{
    Node *p = find_val(val);
    Node *q = p->next;
    p->next = q->next;
    delete q;
}

void List::update(int val, int pos)
{
    Node *p = find_pos(pos);
    p->next->data = val;
}
void List::reverse()
{
    Node *p = head->next;
    Node *q = head->next->next;
    Node *m = head->next->next->next;

    p->next = NULL;
    while(m){
        q->next = p;
        p = q;
        q = m;
        m = m->next;
    }
    q->next = p;
    head->next = q;
}
int main()
{
    List l1;
    l1.insert_head(10);
    l1.insert_head(20);
    l1.insert_head(30);
    l1.print();
}
