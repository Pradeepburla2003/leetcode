class Solution {
public:
    void perm(vector<int>& nums,int n,vector<int>&v,vector<int>&temp, vector<vector<int>>&ans){
        if(temp.size()==n){
            ans.push_back(temp);
            return ;
        }
        for(int i=0;i<n;i++){
            if(v[i]==0){
                v[i]=1;
                temp.push_back(nums[i]);
                perm(nums,n,v,temp,ans);
                v[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp,v(n,0);
        vector<vector<int>>ans;
        perm(nums,n,v,temp,ans);
        return ans;
    }
};  