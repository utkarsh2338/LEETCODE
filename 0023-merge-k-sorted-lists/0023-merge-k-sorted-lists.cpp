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
    ListNode* merge2Lists(ListNode* head1, ListNode*head2){
        if(head1 == NULL && head2 == NULL) return NULL;
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        if(head1-> val <= head2->val){
            head1->next = merge2Lists(head1->next,head2);
            return head1;
        }
        else{
            head2->next = merge2Lists(head1,head2->next);
            return head2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;// important line for avoiding runtime error
        ListNode* merged = lists[0];
        for(int i=1;i<n;i++){
            merged = merge2Lists(merged,lists[i]);
        }
        return merged;
    }
};