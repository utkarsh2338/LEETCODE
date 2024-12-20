
class Solution {
public:   
    void solve(TreeNode* L, TreeNode* R, int level){
        // base case 
        if(L==NULL){
            return;
        }
        if(R==NULL){
            return;
        }
        if(level % 2 == 1){
            // swapping karni hai mujhe
            int temp = L->val;
            L->val = R->val;
            R->val = temp;
        }
        solve(L->left,R->right,level+1);
        solve(L->right,R->left,level+1);
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
    solve (root->left,root->right,1);
    return root;
    }
};