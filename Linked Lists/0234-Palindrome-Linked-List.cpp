/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* Time Complexity: O(n), Space Complexity: O(1) */
class Solution {
public:
    bool isPalindrome(ListNode* head) {

    if (head == nullptr || head->next == nullptr)
        return true;

    // Find middle
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    ListNode* prev = nullptr;
    ListNode* cur = slow;

    while (cur != nullptr) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }

    // Compare
    ListNode* left = head;
    ListNode* right = prev;

    while (right != nullptr) {
        if (left->val != right->val)
            return false;

        left = left->next;
        right = right->next;
    }

    return true;
    }
};