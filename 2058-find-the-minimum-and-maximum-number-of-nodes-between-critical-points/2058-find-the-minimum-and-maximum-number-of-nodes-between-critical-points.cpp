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
    
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp!= nullptr) {
            arr.push_back(temp->val);
            temp = temp->next;
            
        }
        if(arr.size()<=2) return {-1,-1};
        vector<int> criticalPoints;
        for(int i=1;i<arr.size()-1;i++){
            if((arr[i] > arr[i-1] && arr[i] > arr[i+1]) ||
           (arr[i] < arr[i-1] && arr[i] < arr[i+1])) {

            criticalPoints.push_back(i);
        }
        }
        if(criticalPoints.size()<2) return {-1,-1};
        int minDis = INT_MAX;
        for(int i=1;i<criticalPoints.size();i++){
            minDis = min(minDis,criticalPoints[i]-criticalPoints[i-1]);
        }
        int maxDis = criticalPoints.back()-criticalPoints.front();
        return {minDis,maxDis};
    }
};