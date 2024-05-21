class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int k=nums.size(),n=pow(2,nums.size());
        vector<vector<int>>ans;
        vector<int>temp;
        ans.push_back(temp);
        for(int i=1;i<n;i++){
            vector<int>sub;
            for(int j=0;j<32;j++){
                if((i>>j)&1){
                    sub.push_back(nums[(j+1)%k]);
                }
            }
            ans.push_back(sub);
        }
        return ans;
    }
};