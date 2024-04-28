class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=nums[0]+nums[nums.size()-1];
        int n=nums.size()-2;
        for(int i=1;i<nums.size()/2;i++){
            maxi=max(maxi,nums[i]+nums[n]);
            n--;
            // cout<<maxi<<"
        }
        return maxi;
    }
};