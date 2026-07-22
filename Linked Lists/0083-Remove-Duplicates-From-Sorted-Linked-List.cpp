/**
    Definition for singly-linked list.*/
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

// 0083. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

//Complexity Analysis
// Time complexity : O(n). The entire list is traversed only once.
// Space complexity : O(1). No extra space is used.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode* cur = head->next;
        ListNode* prev = head;

        while( cur != nullptr ){
            if ( cur->val == prev->val ){
                prev->next = cur->next;
            }
            else{
                prev = prev->next;
            }
            cur = cur->next;
        }
        return head;
    }
};