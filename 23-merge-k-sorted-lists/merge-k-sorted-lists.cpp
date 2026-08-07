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

class Structpq{
public:
    bool operator()(const pair<int,ListNode*>&a  , const pair<int,ListNode*>&b ){
        return a.first > b.first;
    }
};

void call(vector<ListNode*>& lists ,priority_queue<pair<int,ListNode*> ,vector<pair<int,ListNode*>>,Structpq>&pq){
    for(int i=0; i<lists.size();i++){
        if(lists[i]!=nullptr){
            pq.push({lists[i]->val ,lists[i]});
            lists[i]=lists[i]->next;
        }
    }
 
}

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*> ,vector<pair<int,ListNode*>> , Structpq>pq;
        ListNode * root  =new ListNode(-1);
        ListNode * curr =root;
        call(lists,pq);
        while(!pq.empty()){
            curr->next = pq.top().second;
            curr = curr->next;
            if(pq.top().second->next != nullptr) pq.push({pq.top().second->next->val,pq.top().second->next});
            pq.pop();
            

        }
        return root->next;
    }
};