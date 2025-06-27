class Solution {
public:
    ListNode* merge2Lists(ListNode* head1, ListNode* head2) {
        if (head1 == NULL)
            return head2;
        if (head2 == NULL)
            return head1;
        if (head1->val <= head2->val) {
            head1->next = merge2Lists(
                head1->next, head2); // head1 ke next ke baad jo linked list hai
                                     // usko lena hai aur apna head2 toh hai hi.
            return head1;
        } else {
            head2->next = merge2Lists(
                head1, head2->next); // head2 ke next ke baad me jo linked list
                                     // hai usko lena hai aur fir head1 toh hai
                                     // hi starting se mere pas.
            return head2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0)
            return NULL; // important line for avoiding runtime error
        ListNode* merged = lists[0];
        for (int i = 1; i < n; i++) {
            merged = merge2Lists(merged, lists[i]);
        }
        return merged;
    }
};