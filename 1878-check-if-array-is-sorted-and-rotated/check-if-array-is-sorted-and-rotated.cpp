class Solution {
public:
    bool check(vector<int>& nums) {
        int i,flag=0,j;
        for(i=1;i<nums.size();i++){
            if(nums[i]<nums[i-1]){
                flag=1;
                break;
            }
        }
        for(j=i+1;j<nums.size();j++){
            if(nums[j]<nums[j-1]) return false;
        }
        // cout<<"HI";
        return (!flag or (nums[0]>=nums[j-1]));
    }
};