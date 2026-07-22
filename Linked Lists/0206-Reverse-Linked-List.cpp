#include <iostream>
#include "LeetCode-Linked-List-Definition.cpp"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* next = curr->next; // Save the next node
            curr->next = prev;           // Reverse the link
            prev = curr;                 // Move prev forward
            curr = next;                 // Move curr forward
        }
        return prev;
    }
};