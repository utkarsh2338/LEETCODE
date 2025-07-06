class FindSumPairs {
private:
    vector<int>n1,n2;
    unordered_map<int,int>mpp;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1;
        n2 = nums2;
        for(int x:n2){
            mpp[x]++;
        }
    }
    
    void add(int index, int val) {
        mpp[n2[index]]--;
        n2[index] += val;
        mpp[n2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for(int x: n1){
            cnt += mpp[tot-x];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */