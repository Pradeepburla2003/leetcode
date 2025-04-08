class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        map<int,int>mp;
        int i=0;
        for(i=nums.size()-1;i>=0;i--){
            mp[nums[i]]++;
            if(mp[nums[i]]>1) break;
        }
        int len = i + 1;
        return (len + 2) / 3;
    }
};