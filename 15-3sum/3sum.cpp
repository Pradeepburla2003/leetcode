class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0){
                    vector<int>temp={nums[i],nums[j],nums[k]};
                    // sort(nums.begin(),nums.end());
                    k--;
                    j++;
                    ans.push_back(temp);
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--; 
                }
                else if(sum>0) k--;
                else j++;
            }
        }
        return ans;
    }
};