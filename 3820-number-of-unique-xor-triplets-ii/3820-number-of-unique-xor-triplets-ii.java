class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n=nums.length;
        Arrays.sort(nums);
        long vis[]=new long[(int)1e5];
        HashSet<Long>set=new HashSet<>();
        for(int i=0;i<n;i++)for(int j=i;j<n;j++)set.add((long)nums[i]^nums[j]);
            
        int cnt=0;
        for(long it:set){
            for(int nt:nums){
                if(vis[(int)it^nt]==0)cnt++;
                vis[(int)it^nt]=1;
            }
        }

        return cnt;
    }
}