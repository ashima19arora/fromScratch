#include <iostream>
using namespace std;

#include "ListNode.h"  //same folder
// Section 01- insertion,deletion
//  we are going to use list node in this IAH function , so this function also
//  must be templatized
template <typename T>
// pass head by REFERENCE
void insertAtHead(ListNode<T>*& head, int data) {
  ListNode<int>* newNode = new ListNode<int>(data);
  // newNode stores address of newly inserted node
  //*newNode is actually the new Node(val + address)
  (*newNode).next = head;
  head = newNode;
}

template <typename T>
void insertAtTail(ListNode<T>*& head, T data) {
  ListNode<T>* newNode = new ListNode<T>(data);
  // check if list is empty - then this is first node
  if (head == nullptr) {
    head = newNode;
    return;
  }
  // else traverse till tail
  ListNode<T>* temp = head;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = newNode;
  return;
}

template <typename T>
void insertAtAnyPos(ListNode<T>*& head, T data, int pos) {
  ListNode<T>* newNode = new ListNode<T>(data);
  // check if pos<=1=insert at head ka case
  if (pos <= 1) {
    newNode->next = head;
    head = newNode;
    return;
  }
  // else traverse till POS
  ListNode<T>* temp = head;
  for (int i = 1; i < pos - 1 and temp->next != nullptr; i++) {
    temp = temp->next;
  }
  newNode->next = temp->next;
  temp->next = newNode;
}

template <typename T>
void deleteAtHead(ListNode<T>*& head) {  // pass by reference-here u want to
                                         // reflect the changes
  if (head == nullptr) {
    return;
  }
  ListNode<T>* temp = head;
  head = head->next;
  delete temp;  // deallocate the memory temp is pointing towards
}

template <typename T>
void deleteAtTail(ListNode<T>*& head) {  // pass by reference-here u want to
                                         // reflect the changes
  if (head == nullptr) {                 // LL is of 0 length
    return;
  }

  ListNode<T>* temp = head;
  if (head->next == nullptr) {  // LL is of 1 length
    delete head;
    head = nullptr;
    return;
  }

  while (temp->next->next != nullptr) {  // temp->next is a pointer
    temp = temp->next;
  }
  // we are at the second last node;
  delete temp->next;
  temp->next = nullptr;
}

template <typename T>
void deleteAtanyPos(ListNode<T>*& head,
                    int pos) {  // pass by reference-here u want to
                                // reflect the changes
  if (head == nullptr) {
    return;
  }

  ListNode<T>* temp = head;
  if (pos <= 1) {
    // you are deleting the first node
    head = temp->next;
    delete temp;
    return;
  }

  for (int i = 1; i < pos - 1 & temp->next != nullptr; i++) {
    temp = temp->next;
  }
  // if you are here, we are either at pos-1 or the pos doesnt exist(you are
  // last node)
  // check is it is scenario 2
  if (temp->next == nullptr) {
    // you are at the last node , the given pos doesn't exist
    return;
  }
  // you are at pos-1
  ListNode<T>* toDelete = temp->next;
  temp->next = toDelete->next;
  delete toDelete;
}

template <typename T>
void deleteAtByVal(ListNode<T>*& head,
                   T data) {  // delete the first occurence of this value in LL
  if (head == nullptr) {
    return;
  }

  ListNode<T>* temp = head;
  // the value is present at the head
  if (head->val == data) {
    // you are deleting the first node
    head = temp->next;
    delete temp;
    return;
  }

  // traverse till pos-1
  while (temp->next != nullptr) {
    if (temp->next->val == data) {
      // you are the node whose next node's val matched with data
      ListNode<T>* toDelete = temp->next;
      temp->next = toDelete->next;
      delete toDelete;
      return;
    }
    temp = temp->next;
  }
  // you are at the last node
  // the value u r looking for is not there in the current LL
  return;
}

// Section 02- print , searching , length
template <typename T>
void printLL(ListNode<T>*& head) {
  ListNode<int>* temp = head;
  while (temp != nullptr) {
    cout << temp->val << "-->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}
// searching iteratively
template <typename T>
bool searchInLL(ListNode<T>*& head, T key) {
  ListNode<int>* temp = head;
  while (temp != nullptr) {
    if (temp->val == key) {
      return true;
    }
    temp = temp->next;
  }
  return false;
}

// searching recursively
template <typename T>
bool searchInLLRecursively(ListNode<T>* start, T key) {
  if (start == nullptr) {
    return false;
  }
  // current state f(i,key)
  if (start->val == key) {
    return true;
  }
  return searchInLLRecursively(start->next, key);
}

// length
template <typename T>
int lengthLL(ListNode<T>*& head) {
  ListNode<T>* temp = head;
  int count = 0;

  while (temp != nullptr) {
    count++;
    temp = temp->next;
  }
  return count;
}

// section 03-midpoint

// brute force approach
// traverse twice in the linked list
// this returns second midpoint in even and midpoint in odd length ll
template <typename T>
ListNode<T>* midPoint01(ListNode<T>*& head) {
  if (head == nullptr) {
    return head;
  }

  // find the length
  int count = lengthLL(head);
  int midpoint = (count / 2) + 1;

  // traverse
  ListNode<T>* temp = head;
  //(first node is 1);
  // u have to traverse midpoint -1 times
  for (int i = 1; i < midpoint; i++) {
    temp = temp->next;
  }
  return temp;
}

// two pointer approach / tortoise and haze
// traverse once in ll thru fast and slow pointer
// move fast by two nodes , slow by 1 till fast cant move any longer
// this returns second midpoint in even and midpoint in odd length ll

template <typename T>
ListNode<T>* midPoint02(ListNode<T>*& head) {
  if (head == nullptr) {
    return head;
  }
  ListNode<T>* fast = head;
  ListNode<T>* slow = head;
  while (fast != nullptr and fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

// to get 1st middle point in even linked list
// start fast one node ahead of slow
template <typename T>
ListNode<T>* midPoint03(ListNode<T>*& head) {
  if (head == nullptr) {
    return head;
  }
  ListNode<T>* fast = head->next;
  ListNode<T>* slow = head;
  while (fast != nullptr and fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
  }
  return slow;
}

// section 04: reversal of linked list

// way 1 reversing the whole ll thru nodes , itertively
ListNode<T>* reverseList(ListNode<T>* head) {
  if (head == nullptr or head->next == nullptr) {
    return head;
  }
  ListNode<T>* current = head;
  ListNode<T>* prev = nullptr;
  ListNode<T>* agla;
  while (current != nullptr) {
    agla = current->next;
    current->next = prev;
    prev = current;
    current = agla;
  }
  return prev;
}

// way 2 reversing the whole ll thru nodes , recursively
ListNode<T>* reverseList(ListNode<T>* head) {
  if (head == nullptr or head->next == nullptr) {
    return head;
  }
  ListNode<T>* reverseHead = reverseList(head->next);
  head->next->next = head;
  head->next = nullptr;
  return reverseHead;
}

// reversing part of linked list, nodes , iteratively

template <typename T>
ListNode<T>* reverseBetweenIteratively(ListNode<T>* head, int left, int right) {
  // trivial cases
  if (head == nullptr or left == right) {
    return head;
  }
  // move prev to one node behind left
  ListNode<T>* dummy = new ListNode(0);
  dummy->next = head;
  ListNode<T>* prev = dummy;
  for (int i = 1; i < left; i++) {
    prev = prev->next;
  }

  // move current to left node
  ListNode<T>* current = prev->next;

  // implement 3 pointer approach
  ListNode<T>* sectionStart = current;
  ListNode<T>* sectionPrev = nullptr;
  ListNode<T>* sectionAgla = nullptr;

  // reverse the nodes left-right+1 times
  for (int i = 1; i <= right - left + 1; i++) {
    sectionAgla = sectionStart->next;
    sectionStart->next = sectionPrev;
    sectionPrev = sectionStart;
    sectionStart = sectionAgla;
  }

  // connect the desired nodes
  current->next = sectionStart;
  prev->next = sectionPrev;
  return dummy->next;
}

// reversing part of linked list, values , recursively

void F(ListNode<T>* end, ListNode<T>*& start, bool& stop, int left, int right) {
  // we will check if we are at desired position first before we swap
  if (right == 1) {
    return;
  }
  // that means we are not at desired position
  // increment start and end as per
  end = end->next;
  if (left > 1) {
    start = start->next;
  }

  // now check again if we are at right position
  F(end, start, stop, left - 1, right - 1);
  // u r right postion now , now swap if required
  if (start == end or end->next == start) {
    stop = true;
  }
  if (!stop) {
    swap(start->val, end->val);
    start = start->next;
  }
  return;
}
ListNode<T>* reverseBetween(ListNode<T>* head, int left, int right) {
  // trivial cases
  if (head == nullptr or left == right) {
    return head;
  }
  ListNode<T>* start = head;
  ListNode<T>* end = head;
  bool stop = false;
  F(end, start, stop, left, right);
  return head;
}
