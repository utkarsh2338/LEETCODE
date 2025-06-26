/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // corner case
        if(head == NULL || head->next == NULL) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        // hamesha jo banda tezi se bhag raha usi ka while condition likhna chahiye
        while(fast && fast->next){
            
            
            slow = slow ->next;
            fast = fast->next->next;

            if(slow == fast){
                break;
            }
        }
        if(fast == NULL) return NULL;
        if(slow != fast) return NULL;
        ListNode* temp = head;
        while(temp != slow){
            temp = temp->next;
            slow = slow->next;
        }
        return temp;
    }
};