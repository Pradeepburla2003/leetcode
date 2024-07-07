class Solution {
public:
    int fun(vector<int>&nums,int i,int n,vector<int>&dp){
        if(i>n-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick=nums[i]+fun(nums,i+2,n,dp);
        int nonpick=fun(nums,i+1,n,dp);
        cout<<pick<<" "<<nonpick<<endl;
        return dp[i]=max(pick,nonpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int>dp(n,-1),dp2(n,-1);
        return max(fun(nums,0,n-1,dp),fun(nums,1,n,dp2));
    }
};