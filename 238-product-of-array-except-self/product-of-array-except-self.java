class Solution {
    public int[] productExceptSelf(int[] nums) {
        int zeros=0,mul1=1,mul2=1;
        int[] ans = new int[nums.length];
        for(int i=0;i<nums.length;i++){
            if(nums[i]==0){
                zeros++;
                if(zeros==2) break;
                mul2=mul1;
                mul1=1;
            }
            else{
                mul1=mul1*nums[i];
            }
        }
        if(zeros==2) return ans;
        else if(zeros==1){
            for(int i=0;i<nums.length;i++){
                if(nums[i]==0){
                    ans[i]=mul1*mul2;
                    break;
                }
            }
            return ans;
        }
        for(int i=0;i<nums.length;i++){
            ans[i]=mul1/nums[i];
        }
        return ans;
    }
}