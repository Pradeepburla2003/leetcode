class Solution {
    public boolean canJump(int[] nums) {
        int temp=0;
        for(int i=0;i<nums.length;i++){
            temp=Math.max(temp,nums[i]+i);
            // System.out.println(temp);
            if(temp>=nums.length-1) return true;
            if(temp==i && nums[i]==0) return false;
        }
        return true;
    }
}