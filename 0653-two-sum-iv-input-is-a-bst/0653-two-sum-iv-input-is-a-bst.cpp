/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* node, vector<int>& inOrder){
        if(node == NULL) return;
        solve(node->left,inOrder);
        inOrder.push_back(node->val);
        solve(node->right,inOrder);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inOrder;
        solve(root,inOrder);
        int n = inOrder.size();
        int i =0, j= n-1;
        while(i<j){
            int sum = inOrder[i] + inOrder[j];
            if(sum == k){
                return true;
            }
            if(sum <= k) i++;
            else j--;
        }
        return false;
    }
};