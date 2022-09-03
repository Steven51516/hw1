/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void helper(Node*& in, Node*& odds, Node*& evens, Node*& o_tail, Node*& e_tail);

void split(Node*& in, Node*& odds, Node*& evens)
{
  Node* o_tail= NULL;
  Node* e_tail=NULL;
  helper(in, odds, evens, o_tail, e_tail);
  in=NULL;
}



/* If you needed a helper function, write it here */
void helper(Node*& in, Node*& odds, Node*& evens, Node*& o_tail, Node*& e_tail)
{
    if (in == NULL) return;
    Node* temp = in->next;
    if (in->value % 2 != 0)
    {
        if (odds == NULL)
        {
            in->next = NULL;
            odds = in;
            o_tail = in;
        }
        else
        {
            o_tail->next = in;
            o_tail = in;
            in->next = NULL;
        }
    }
    else
    {
        if (evens == NULL)
        {
            in->next = NULL;
            evens = in;
            e_tail = in;
        }
        else
        {
            e_tail->next = in;
            e_tail = in;
            in->next = NULL;
        }
    }
    helper(temp, odds, evens, o_tail, e_tail);
}
// WRITE YOUR CODE HERE