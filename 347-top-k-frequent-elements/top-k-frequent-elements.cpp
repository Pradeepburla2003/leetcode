class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>pr;
        vector<int>ans;
        for(auto i:mp){
            pr.push_back({i.second,i.first});
        }
        sort(pr.begin(),pr.end());
        int i=pr.size()-1;
        while(k>0){
            ans.push_back(pr[i].second);
            k--;
            i--;
        }
        return ans;
    }
};