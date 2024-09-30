class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                nums[i-1]=101;
                ans++;
            }
        }
        sort(nums.begin(),nums.end());
        int i = 0;
        for(i=0;i<nums.size();i++){
            if(nums[i]==101) break;
        }
        return i;
    }
};