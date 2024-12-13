class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }
        while(!pq.empty()){
            int ind = pq.top().second;
            if(nums[ind]!=0){
                ans += nums[ind];
                if(ind-1>=0) nums[ind-1] = 0;
                if(ind+1<nums.size()) nums[ind+1] = 0;
            }
            pq.pop();
        }
        return ans;
    }
};