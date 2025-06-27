// Stack approach
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        while(temp != NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        int n = st.size();
        ListNode* curr = head;
        int sum = 0,i=0;
        while(i<n/2){
            sum = max(sum,curr->val + st.top());
            curr = curr->next;
            st.pop();
            i++;
        }
        return sum;
    }
};