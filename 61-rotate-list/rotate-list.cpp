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
    ListNode* rotateRight(ListNode* head, int k) {
        int count=1;
        ListNode* curr = head;
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        while(curr->next!=nullptr){
            count++;
            curr=curr->next;
        }
        int c=1;
        ListNode* prev=head;
        ListNode* prev1=head;
        k=k%count;
        if(k==0){
            return head;
        }
        while(prev!=nullptr){
            if(c==count-(k%count)){
                prev1=prev->next;
                prev->next=nullptr;
                break;
            }
            c++;
            prev=prev->next;
        }
        curr->next=head;
        return prev1;
    }
};