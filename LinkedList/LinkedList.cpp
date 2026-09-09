
#include "C:\Users\hp\OneDrive\Desktop\Master\HeaderFiles\LinkedList.h"  //..master directory

#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  ListNode<int>* head = nullptr;
  ListNode<int>* head01 = nullptr;
  // store address of first node of ll or point to the first node

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    insertAtHead(head, x);
    insertAtTail(head01, x);
  }
  printLL(head);
  printLL(head01);
  cout << searchInLL(head, 1) << endl;
  cout << searchInLLRecursively(head, 1) << endl;
  printLL(head01);
  cout << midPoint02(head01)->val << endl;
}