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
// class Solution {
// public:
//     bool solve(TreeNode* node, int l, int r){
//         if(node == NULL) return true;
//         if(node->val <=l || node->val >= r) return false;
//         bool leftValid = solve(node->left,l,node->val);
//         bool rightValid = solve(node->right,node->val,r);
//         return leftValid && rightValid;
//     }
//     bool isValidBST(TreeNode* root) {
//         return solve(root,-1e9,1e9);
//     }
// };

#include <climits>

class Solution { 
public:
    bool solve(TreeNode* node, long long l, long long r) {
        if (node == NULL) return true;
        if (node->val <= l || node->val >= r) return false;

        bool leftValid = solve(node->left, l, node->val);
        bool rightValid = solve(node->right, node->val, r);
        
        return leftValid && rightValid;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX); // Using long long to avoid integer overflow
    }
};
