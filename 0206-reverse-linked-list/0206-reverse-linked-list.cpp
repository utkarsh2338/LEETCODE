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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        // creating two pointers 
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        // now what we have to do is to point each node to its previous
        while(curr != NULL){
            forward = curr->next;// assigned the forward pointer to the next
            curr->next = prev;// assigned the next pointer of next to previous 
            // now we need to move the curr and prev pointer to 1step ahea
            prev = curr;
            curr = forward;// curr ko forward kar do

        }
        return prev;
    }
};