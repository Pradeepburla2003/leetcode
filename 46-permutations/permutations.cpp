class Solution {
public:
    void help(vector<int>& nums,vector<int>& temp,vector<vector<int>>&ans,vector<int>&vis,int i){
        // cout<<temp.size()<<endl;
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int j=0;j<nums.size();j++){
            if(vis[j]==0){
                temp.push_back(nums[j]);
                vis[j]=1;
                help(nums,temp,ans,vis,j);
                vis[j]=0;
                temp.pop_back();
            }
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        for(int i=0;i<nums.size();i++){
            temp.push_back(nums[i]);
            vector<int>vis(nums.size(),0);
            vis[i]=1;
            help(nums,temp,ans,vis,i);
            temp.pop_back();
        }
        return ans;
    }
};