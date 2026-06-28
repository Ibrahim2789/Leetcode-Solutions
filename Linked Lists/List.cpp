#include "List.h"

template <typename T>
const T & List<T>::operator[](unsigned index){
    ListNode *thru = head_;

    while ( index > 0 && thru->next != nullptr ){
        thru = thru->next; //Take the address stored in next and store it in thru
        index--;
    }

    return thru->data;//Give me the data inside the node that thru points to.
}

template <typename T>
void List<T>::insertAtFront(const T & data){
    ListNode *node = new ListNode(data);

    node->next = head_; // Set the new node's next pointer point the current head of the List simply means where the head was pointing to.

    head_ = node; // Set the head_ to point to the new node and hence a new node is added to the first of the list.
}