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