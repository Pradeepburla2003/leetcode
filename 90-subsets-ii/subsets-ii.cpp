class Solution {
public:
    void fun(vector<int>& nums,vector<int>&p,set<vector<int>>& s,int i,int n){
        if(i==n){
            s.insert(p);
            return;
        }
        p.push_back(nums[i]);
        fun(nums,p,s,i+1,n);
        p.pop_back();
        fun(nums,p,s,i+1,n);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        vector<int>p;
        sort(nums.begin(),nums.end());
        fun(nums,p,s,0,nums.size());
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};