#include<iostream>
using namespace std;
#include "split.h"

class Linkedlist
{
public:
    Node* head;
    Node* tail;
    Linkedlist()
    {
        head = NULL;
        tail = NULL;
    }
    void add_node(int n)
    {
        Node* tmp = new Node(n,NULL);
        tmp->value = n;
        tmp->next = NULL;

        if (head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
};

void print_node(Node* head)
{
  Node* temp = head;
  while(temp!=NULL)
  {
    cout<<temp->value<<" ";
    temp=temp->next;
  }
  cout<<endl;
}

void clean(Node* head)
{
    Node* tmp;

    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        delete tmp;
    }
}


int main()
{
  //test 1
  cout<<"test 1"<<endl;
  Linkedlist L;
  L.add_node(1);
  L.add_node(2);
  L.add_node(3);
  L.add_node(4);
  L.add_node(5);
  L.add_node(16);
  L.add_node(17);
  Node* odd=NULL;
  Node* even=NULL;
  split(L.head,odd,even);
  cout<<"odd: ";
  print_node(odd);
  cout<<"odd answer: 1 3 5 17"<<endl;
  cout<<"even: ";
  print_node(even);
  cout<<"even answer: 2 4 16"<<endl;
  cout<<endl;
  clean(even);
  clean(odd);


    //test 2
  cout << "test2" << endl;
  Linkedlist L1;
  L1.add_node(1);
  L1.add_node(3);
  L1.add_node(5);
  L1.add_node(17);
  L1.add_node(67);
  L1.add_node(87);
  Node* odd1=NULL;
  Node* even1=NULL;
  split(L1.head, odd1, even1);
  cout << "odd: ";
  print_node(odd1);
  cout << "odd answer: 1 3 5 17 67 87" << endl;
  cout << "even: ";
  print_node(even1);
  cout << "even answer: " << endl;
  cout << endl;
  clean(even1);
  clean(odd1);

  //test 3
  cout << "test3" << endl;
  Linkedlist L2;
  L2.add_node(2);
  L2.add_node(4);
  L2.add_node(6);
  L2.add_node(18);
  L2.add_node(68);
  L2.add_node(88);
  Node* odd2=NULL;
  Node* even2=NULL;
  split(L2.head, odd2, even2);
  cout << "odd: ";
  print_node(odd2);
  cout << "odd answer: " << endl;
  cout << "even: ";
  print_node(even2);
  cout << "even answer: 2 4 6 18 68 88" << endl;
  cout << endl;
  clean(even2);
  clean(odd2);

  //test 4
  cout << "test 4" << endl;
  Linkedlist L3;
  L3.add_node(0);
  Node* odd3=NULL;
  Node* even3=NULL;
  split(L3.head, odd3, even3);
  cout << "odd: ";
  print_node(odd3);
  cout << "odd answer: " << endl;
  cout << "even: ";
  print_node(even3);
  cout << "even answer: 0" << endl;
  cout << endl;
  clean(even3);
  clean(odd3);



  




  return 0;
}
