#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

void ULListStr::push_back(const std::string& val)
{
  if(size_==0)
  {
    size_++;
    Item* item = new Item();
    head_ = item;
    tail_ = item;
    item -> val[0] = val;
    item -> last++;
  }
	//case when no need to create a new Item
  else if(tail_->last!=10)
  {
    size_++;
    tail_->val[tail_->last]=val;
    tail_->last++;
  }
	//need to create a new Item
  else
  {
    size_++;
    Item* item = new Item();
    item -> val[0] = val;
    item -> last++;
    item -> prev = tail_;
    tail_ -> next = item;
    tail_ = item;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if(size_==0)
  {
    size_++;
    Item* item = new Item();
    head_ = item;
    tail_ = item;
    item -> val[9] = val;
    item -> last = 10;
    item -> first = 9;
  }
	//case when no need to create a new Item
  else if(head_->first!=0)
  {
    size_++;
    head_ -> val[head_->first-1]= val;
    head_ -> first --;
  }
	//need to create a new Item
  else
  {
    size_++;
    Item* item = new Item();
    item -> val[9] = val;
    item -> last = 10;
    item -> first = 9;
    item -> next = head_;
    head_ -> prev = item;
    head_ = item;
  }
}

void ULListStr::pop_back()
{
  if(size_ == 0)
  {
    return;
  }
  size_--;
  tail_->last--;
	// delete an item if it is empty
  if(tail_->last-tail_->first == 0)
  {
    if(head_==tail_)
    {
      delete head_;
      head_=NULL;
      tail_=NULL;
    }
    else
    {
      tail_->prev->next=NULL;
      Item* temp = tail_;
      tail_ = tail_ -> prev;
      delete temp;
    }
  }
}

void ULListStr::pop_front()
{
  if(size_ == 0)
  {
    return;
  }
  size_--;
  head_->first++;
	//delete an item when it is empty
  if(head_->last-head_->first==0)
  {
    if(head_==tail_)
    {
      delete head_;
      head_=NULL;
      tail_=NULL;
    }
    else
    {
      head_->next->prev=NULL;
      Item* temp = head_;
      head_=head_->next;
      delete temp;
    }
  }


}

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const
{
  return head_->val[head_->first];
}


std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if(loc >= size_ || loc < 0) return NULL;
  Item* temp = head_;
  while(loc+1>(temp->last-temp->first))
  {
    loc=loc-(temp->last-temp->first);
    temp=temp->next;
  }
  return temp->val+temp->first+loc;

}




