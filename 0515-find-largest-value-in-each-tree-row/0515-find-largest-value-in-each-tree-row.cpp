/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    /*
    Approach: BFS karenge apne binary tree me aur max check kar lenge simple
    approach
    */
    vector<int> largestValues(TreeNode* root) {
        // first check if the root is null then we will return a null vector
        if (root == NULL) {
            return vector<int>{};
        }
        // declaring a vector for the ans
        vector<int> ans;
        // declaring a queue for bfs
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currLength = q.size();
            int currMax = INT_MIN;
            for (int i = 0; i < currLength; i++) {
                TreeNode* node = q.front();
                q.pop();
                // now i have a value to compare and get the maximum value
                currMax = max(currMax, node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(currMax);
        }
        return ans;
    }
};