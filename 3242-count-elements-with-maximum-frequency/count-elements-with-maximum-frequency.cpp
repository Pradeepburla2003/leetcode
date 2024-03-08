class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxi=INT_MIN,ans=0;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
            maxi=max(maxi,mp[nums[i]]);
        }
        for(auto i:mp){
            if(i.second==maxi) ans+=maxi;
        }
        return ans;
    }
};