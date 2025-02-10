class Solution {
    public int help(int[] nums,int i,int[] dp){
        if(i>=nums.length) return 0;
        if(dp[i]!=-1) return dp[i];
        int pick = nums[i]+help(nums,i+2,dp);
        int nonpick = help(nums,i+1,dp);
        return dp[i] = Math.max(pick,nonpick);
    }
    public int rob(int[] nums) {
        int[] dp = new int[101];
        Arrays.fill(dp,-1);
        return help(nums,0,dp);
    }
}