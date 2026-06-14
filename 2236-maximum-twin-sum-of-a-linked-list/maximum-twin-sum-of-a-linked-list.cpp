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
    int pairSum(ListNode* head) {
        ListNode * low =head;
        ListNode * high =head;
        int i=0;
        while(high!=nullptr && high->next !=nullptr  ){
            low =low->next;
            high =high->next->next;
            i++;
        }
        ListNode * low1 =head;
        int ans=0;
        vector<int>t(i,0);
        int j=0;
        while(low!=nullptr){
            t[j]+=(low1->val);
            t[i-j-1] +=(low->val);
            j++;
            low1=low1->next;
            low=low->next;
        }
        for(int j=0;j<t.size();j++){
            ans =max(ans,t[j]);
        }
        return ans;
    }
};