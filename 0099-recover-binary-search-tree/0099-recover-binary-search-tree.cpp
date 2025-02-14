class Solution {
public:
    void solve(TreeNode* node, vector<TreeNode*>& inOrder){
        if(node == NULL) return;
        solve(node->left,inOrder);
        inOrder.push_back(node);
        solve(node->right, inOrder); 
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> inOrder;
        solve(root, inOrder);
        int n = inOrder.size();
        int i = 0;
        int j = n-1;
        while(i+1 < n){
            if(inOrder[i] -> val > inOrder[i+1] -> val){
                break;
            }
            i++;
        }
        while(0 <= j-1){
            if(inOrder[j-1] -> val > inOrder[j] -> val){
                break;
            }
            j--;
        }
        swap(inOrder[i]->val,inOrder[j]->val);
        return;
    }
};