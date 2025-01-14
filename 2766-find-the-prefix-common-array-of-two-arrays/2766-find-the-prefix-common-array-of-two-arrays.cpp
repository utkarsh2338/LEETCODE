class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int>ans;
        unordered_set<int>st1,st2; // made two sets to count the elements
        for(int i=0;i<n;i++){
            st1.insert(A[i]);// inserting the elements along with checking for the presence in the other set and increasing the count as well 
            st2.insert(B[i]);
            int count = 0;
            for(int ele: st1){
                if(st2.count(ele)){
                    count++;// increased the count of having an idea of presence of the element
                }
            }
            ans.push_back(count);// pushed into the vector array
        }
        return ans;
    }
};