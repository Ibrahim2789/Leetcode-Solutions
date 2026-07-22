/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// 0203. Remove Linked List Elements
// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
//Complexity Analysis

// Time complexity : O(n). The entire list is traversed only once.
// Space complexity : O(1). No extra space is used.

#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* cur = head; 

        while(cur != nullptr){
            if ( cur->val == val ){
                prev->next = cur->next;
            }
            else{
                prev = cur;
            }
            cur = cur->next;
        }
        return dummy.next;

    }
};