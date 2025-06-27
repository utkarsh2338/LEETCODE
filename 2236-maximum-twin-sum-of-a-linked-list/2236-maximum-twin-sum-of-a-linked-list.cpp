
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp != NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        int n = arr.size();
        int maxSum = INT_MIN;
        for(int i=0;i<n/2;i++){
            int sum = (arr[i] + arr[n-1-i]);
            maxSum = max(maxSum,sum);
        }
        return maxSum;
    }
};