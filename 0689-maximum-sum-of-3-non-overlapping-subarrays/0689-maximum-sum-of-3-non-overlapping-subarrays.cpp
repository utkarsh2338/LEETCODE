class Solution {
public:
    int t[20001][4];
    // writing another helper function which will help me to get the maximum sum
    int helper(vector<int>& subArray , int k,int idx,int count){
        // base case
        if(count == 0){// iska matlb sare subarray mil gaye mujhe aur mujhe aur koi subarray ka sum add nahi karna 
            return 0;
        }
        if(idx>=subArray.size()){// isme maine sara subarray exhaust kar diya aur mujhe ek bhi sum nahi mila toh mai ek invalid number return karunga
            return INT_MIN;
        }
        if(t[idx][count] != -1){
            return t[idx][count];
        }
        int take = subArray[idx] + helper(subArray,k,idx+k,count-1);
        int not_take = helper(subArray,k,idx+1,count);
        return t[idx][count] = max(take,not_take);
    }
    // this solve function will give me the index with which i can decide should i generate the array with this index or not  
    void solve(vector<int>& subArray,vector<int>& result, int k, int count, int idx){
        // base case
        if(count == 0 ){
            return;
        }
        if(idx>= subArray.size()){
            return;
        }
        int take = subArray[idx] + helper(subArray,k,idx+k,count-1);
        int not_take =  helper(subArray,k,idx+1,count);
        if(take >= not_take){
            result.push_back(idx);
            solve(subArray,result,k,count-1,idx+k);
        }
        else{
            solve(subArray,result,k,count,idx+1);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(t,-1,sizeof(t));
        vector<int>subArray;
        int i=0;
        int j=0;
        int windowSum = 0;

        while(j<nums.size()){
            windowSum += nums[j];

            if(j-i+1 == k){
                subArray.push_back(windowSum);
                windowSum -= nums[i];
                i++;
            }
            j++;
        }

        vector<int>result;
        solve(subArray,result,k,3,0);
        return result;
    }
};