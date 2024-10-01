class Solution {
public:
    void help(int i,int n,int k,vector<int>&temp,set<vector<int>>&st){
        if(temp.size() == k){
            st.insert(temp);
            return;
        }
        for(int j=i;j<=n;j++){
            temp.push_back(i);
            help(j+1,n,k,temp,st);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        set<vector<int>>st;
        vector<int>temp;
        for(int i=1;i<=n-k+1;i++){
            help(i,n,k,temp,st);
        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};