class Solution {
public:
    int help(vector<int>& nums,int i,vector<int>& dp){
        if(i == nums.size() - 1) return 0;
        if(i >= nums.size()) return 1e8;
        if(dp[i] != -1) return dp[i];
        int count = 1e8;
        for(int j=1; j<=nums[i]; j++){
            count = min(count,1 + help(nums,i+j,dp));
        }
        return  dp[i] = count;
    }
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return help(nums,0,dp);
    }
};