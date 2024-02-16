class Solution {
    
    int[] dp = new int[10001];
    
    public int help(int[] nums , int i){
        
        if(i == nums.length-1) return 0;
        if(i >= nums.length) return Integer.MAX_VALUE-1;
        if(dp[i] != -1) return dp[i];
        
        int ans = Integer.MAX_VALUE-1;
        for(int j=1 ; j<=nums[i] ; j++)
            ans = Math.min(ans , 1+help(nums , (i+j)));
        
        return dp[i] = ans;
    }
        
    public int jump(int[] nums) {
        
        Arrays.fill(dp , -1);
        return help(nums , 0);
    }
}