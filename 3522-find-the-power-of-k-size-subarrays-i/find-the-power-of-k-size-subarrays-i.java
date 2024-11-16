class Solution {
    public int[] resultsArray(int[] nums, int k) {
        if(nums.length==1 || k==1) return nums;
        int[] ans = new int[nums.length - k + 1];
        int flag = 0,j=0;
        for(int i=1;i<nums.length;i++){
            if(nums[i] == nums[i-1]+1) flag++;
            else flag=0;
            if(i>=k-1){
                if(flag == k-1){
                    flag -= 1;
                    ans[j++] = nums[i];
                }
                else ans[j++] = -1;
            }
        }
        return ans;
    }
}