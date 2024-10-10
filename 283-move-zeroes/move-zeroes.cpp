class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        int j = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeros+=1;
            else nums[j++] = nums[i];
        }
        for(int i=nums.size()-zeros;i<nums.size();i++) nums[i] = 0;

    }
};