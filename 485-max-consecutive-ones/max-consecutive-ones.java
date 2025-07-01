class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int ans=0,i=0,n=nums.length;
        while(i<n){
            int j=i+1;
            if(nums[i]==1){
                int count=1;
                while(j<n && nums[i]==1 && nums[i]==nums[j]){
                    j++;
                    count++;
                }
                ans=Math.max(ans,count);
            }
            i=j;
        }
        return ans;
    }
}