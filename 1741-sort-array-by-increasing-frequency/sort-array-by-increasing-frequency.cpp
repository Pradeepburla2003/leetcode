class Solution {
public:
    bool static comparator(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>>pr;
        for(auto i:mp){
            pr.push_back({i.second,i.first});
        }
        sort(pr.begin(),pr.end(),comparator);
        vector<int>ans(n);
        int k=0;
        for(int i=0;i<pr.size();i++){
            for(int j=0;j<pr[i].first;j++){
                ans[k++]=pr[i].second;
            }
        }
        return ans;
    }
};