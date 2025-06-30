class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0,j=0;
        if(nums.length==1) return 1;
        while(j+1<nums.length){
            if(nums[j]!=nums[j+1]){
                nums[i]=nums[j];
                i++;
            }
            j++;
        }
        nums[i]=nums[j];
        return i+1;
    }
}