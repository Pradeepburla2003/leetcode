class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0,j = 0;
        while(j<nums.size()){
            if(val != nums[j]){
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        return i;
    }
};