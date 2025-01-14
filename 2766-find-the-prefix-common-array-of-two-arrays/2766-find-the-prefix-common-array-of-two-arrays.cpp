class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        //0(n)
        int count = 0;
        int n = A.size();
        vector<int>ans;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[A[i]]++;
            if(mpp[A[i]] == 2) count += 1;
            mpp[B[i]]++;
            if(mpp[B[i]] == 2) count += 1;
            ans.push_back(count);
        }
        return ans;
    }
};