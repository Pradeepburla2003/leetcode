class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        vector<long long>pre(nums.size()),suf(nums.size());
        long long preSum=0,sufSum=0,n=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            preSum+=nums[i];
            sufSum+=nums[n-i];
            pre[i]=preSum;
            suf[n-i]=sufSum;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(pre[i]>=suf[i+1]) ans++;
        }
        return ans;
    }
};