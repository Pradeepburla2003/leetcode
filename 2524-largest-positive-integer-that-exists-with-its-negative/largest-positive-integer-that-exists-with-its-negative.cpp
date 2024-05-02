class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=-1;
        mp[nums[0]]++;
        for(int i=1;i<nums.size();i++){
            if(mp.find(-nums[i])!=mp.end()){
                ans=max(abs(nums[i]),ans);
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};