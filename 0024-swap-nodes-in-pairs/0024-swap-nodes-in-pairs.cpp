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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;
        vector<int>arr;
        ListNode* temp = head;
        int n = 1;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
            n+=1;
        }
        for(int i=0;i<arr.size()-1;i+=2){
            swap(arr[i],arr[i+1]);
        }
        ListNode* h = new ListNode(arr[0]);
        
        ListNode* curr = h;
        for(int i=1;i<arr.size();i++){
            curr->next = new ListNode(arr[i]);
            curr = curr->next;
        }
        return h;
    }
};