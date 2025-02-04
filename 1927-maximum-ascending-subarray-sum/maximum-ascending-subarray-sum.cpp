class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int maxi = INT_MIN;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=nums[i-1]){
                maxi = max(ans,maxi);
                ans = 0;
            }
            ans+=nums[i];
        }
        maxi=max(maxi,ans);
        return maxi;
    }
};