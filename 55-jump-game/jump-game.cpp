class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        if(nums[0] == 0) return false;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(i > maxi) return false;
            maxi = max(i + nums[i],maxi);
        }
        return true;
    }
};