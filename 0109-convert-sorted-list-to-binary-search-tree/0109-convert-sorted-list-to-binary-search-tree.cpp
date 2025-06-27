class Solution {
public:
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL ) return NULL;
        if(head->next == NULL){
            return new TreeNode(head->val);
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slowPrev = NULL;
        while(fast && fast->next){
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        slowPrev -> next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};