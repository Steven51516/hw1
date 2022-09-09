/* Write your test code for the ULListStr in this file */

#include <iostream>
using namespace std;
#include "ulliststr.h"


int main(int argc, char* argv[])
{
ULListStr data;
//push_back when the list is empty
data.push_back("1");
cout << data.get(0) << " " << data.back() << " " << data.size()<< endl;
cout << "should print 1 1 1" << endl;
//push back when the list is not empty && no need to create a new Item
data.push_back("2");
data.push_back("3");
cout << data.get(1) << " " << data.get(2) << " " << data.size() << endl;
cout << "should print 2 3 3" << endl;
//push back when the list is not empty && need to create a new Item
for(int i = 0; i < 8; i++)
{
  data.push_back("0");
}
cout << data.get(10) << " " << data.back() << " " << data.size() << endl;
cout << "should print 0 0 11" << endl;
//push back when there are multiple items
for(int i = 0; i < 11; i++)
{
  data.push_back("-1");
}
cout << data.get(12) << " " << data.get(21) << " " << data.size() << endl;
cout << "sould print -1 -1 22" << endl;

//pop_back all items
for(int i = 0; i<22; i++)
{
  data.pop_back();
}
cout << data.size() << endl;
cout << "should print 0" << endl;

//push_front when the list is empty
data.push_front("1");
cout << data.get(0) << " " << data.back() << " " << data.size()<< endl;
cout << "should print 1 1 1" << endl;
//push front when the list is not empty && no need to create a new Item
data.push_front("2");
data.push_back("3"); // test together with push_back
cout << data.get(0) << " " << data.back() << " " << data.size() << endl;
cout << "should print 2 3 3" << endl;
//push front when the list is not empty && need to create a new Item
for(int i = 0; i < 9; i++)
{
  data.push_front("0");
}
cout << data.get(0) << " " << data.front() << " " << data.size() << endl;
cout << "should print 0 0 12" << endl;
//push back when there are multiple items
for(int i = 0; i<11; i++ )
{
  data.push_front("-1");
}
cout << data.get(0) << " " << data.get(10) << " " << data.size() << endl;
cout<< "should print -1 -1 23" << endl;

//pop_front all items in combinition of pop_back
for(int i = 0; i < 11; i++)
{
  data.pop_front();
  data.pop_back();
}
data.pop_front();

//pop_back and pop_front an empty list
data.pop_front();
data.pop_front();

cout << data.size() << endl;
cout << "should print 0" << endl;

  return 0;
}


