class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //brute forcce
        vector<int>ans;
        int n = A.size();
        
        for(int i=0;i<n;i++){
            int count =0;
            for(int A_i =0;A_i<=i;A_i++){
                for(int B_i =0;B_i<=i;B_i++){
                    if(B[B_i] == A[A_i]){
                        count++;
                        break;
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};