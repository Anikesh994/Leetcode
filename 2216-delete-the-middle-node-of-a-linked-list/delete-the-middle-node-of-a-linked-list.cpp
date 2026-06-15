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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode * lowp =head;
        ListNode * low =head;
        ListNode * high =head;
        if(high ==nullptr) return head;
        if(high->next ==nullptr) return nullptr;
        
        while(high !=nullptr && high->next!=nullptr){
            lowp=low;
            low=low->next;
            high=high->next->next;
        }
        lowp->next =low->next;
       
        return head;
        
    }
};