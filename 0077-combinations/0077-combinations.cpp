class Solution {
public:
    vector<vector<int>> result;
    void solve(int start,int n,int k,vector<int>&temp){
        if(k==0){
            result.push_back(temp);
            return;
        }
        if(start>n){
            return;
        }
        // temp.push_back(start);
        // solve(start+1,n,k-1,temp);
        // temp.pop_back();
        // // nahi lene ke baaad bhi mujhe explore karna padega ye ek case bas dhyan rakhna tha
        // solve(start+1,n,k,temp);// k decrement tabhi hoga jab maine element liya ho
        for(int i=start;i<=n;i++){
            temp.push_back(i);
            solve(i+1,n,k-1,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        solve(1,n,k,temp);
        return result;
    }
};