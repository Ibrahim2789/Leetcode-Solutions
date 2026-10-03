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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        if ( head == nullptr ){
            cout<<"The List is empty";
            return nullptr;
        }

        ListNode* cur = head;
        int count = 1;
    
        while(cur != nullptr){
            cur = cur->next;
            count++;
        }

        int mid = (count/2) +1;

        int i = 1;
        cur = head;
        while (cur!= nullptr && i<mid){
            cur = cur->next;
            i++;
        }
        return cur;
    }
};