#include "List.h"

template <typename T>
const T& List<T>::operator[](unsigned index) {
    if (head_ == nullptr) {
        throw std::out_of_range("Index out of bounds");
    }

    ListNode* thru = head_;

    while (index > 0) {
        if (thru->next == nullptr) {
            throw std::out_of_range("Index out of bounds");
        }

        thru = thru->next;
        index--;
    }

    return thru->data;
}

template <typename T>
void List<T>::insertAtFront(const T & data){
    ListNode* node = new ListNode(data);

    if (head_ == nullptr) {
        head_ = node;
        return;
    }

    node->next = head_; // Set the new node's next pointer point the current head of the List simply means where the head was pointing to.

    head_ = node; // Set the head_ to point to the new node and hence a new node is added to the first of the list.
}

template <typename T>
void List<T>::insertAtBack(const T & data){
    ListNode* node = new ListNode(data);

    if (head_ == nullptr) {
        head_ = node;
        return;
    }
    ListNode* cur = head_;

    while (cur->next != nullptr){
        cur = cur->next;
        
    }
    cur->next = node;
}

template <typename T>
void List<T>::removeAtFront(){
    if(head_==nullptr){
        throw std::out_of_range("Cannot remove from an empty list");
    }

    ListNode* previous = head_;
    head_ = head_->next;
    delete previous;
}

template <typename T>
void List<T>::removeAtBack(){
    ListNode* cur = head_;
    ListNode* previous = nullptr;

    if(head_==nullptr){
        throw std::out_of_range("Cannot remove from an empty list");
    }

    if(head_->next==nullptr){
        delete head_;
        head_ = nullptr;
        return;
    }

    while(cur->next != nullptr){
        previous = cur;
        cur = cur->next;
    }

    delete cur;
    previous->next = nullptr;

}
template <typename T>
void List<T>::printList(){
    ListNode* cur = head_;
    if(head_==nullptr){
        cout<<"The list is empty."<<endl;
        return;
    }
    while(cur != nullptr){

        cout<<cur->data<<endl;
        cur = cur->next;

    }
}

template <typename T>
ListNode* List<T>::search(const T & data){

    if(head_==nullptr){
        cout<<"The list is empty."<<endl;
        return nullptr;
    }

    ListNode* cur = head_;

    while(cur != nullptr){
        
        if (cur->data == data){
            return cur;
        }
        cur = cur->next;

    }
    return nullptr;
}