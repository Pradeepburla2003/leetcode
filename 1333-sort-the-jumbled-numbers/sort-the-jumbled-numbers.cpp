class Solution {
public:
    bool static comperator(const pair<int,int>&a,const pair<int,int>&b){
        if (a.first < b.first) return true;
        // if (a.first > b.first) return false;
        return false; 
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int>vis(10,0);
        int n=nums.size();
        vector<pair<int,int>>pr;
        for(int i=0;i<n;i++){
            string temp=to_string(nums[i]);
            string temp2="";
            for(int j=0;j<temp.size();j++){
               temp2+=to_string(mapping[temp[j]-'0']);
            }
            pr.push_back({stoi(temp2),nums[i]});
        }
        sort(pr.begin(),pr.end(),comperator);
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(pr[i].second);
        }
        return ans;
    }
};