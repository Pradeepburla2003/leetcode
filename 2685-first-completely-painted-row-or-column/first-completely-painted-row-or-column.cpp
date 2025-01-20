class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        map<int,pair<int,int>>mp;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                mp[mat[i][j]]={i,j};
            }
        }
        // vector<vector<int>>vis(mat.size()+1,vector<int>(mat[0].size()+1));
        vector<int>rows(mat.size()),cols(mat[0].size());
        int row=mat.size(),col=mat[0].size();
        for(int i=0;i<arr.size();i++){
            auto it=mp[arr[i]];
            rows[it.first]++;
            cols[it.second]++;
            cout<<rows[it.first]<<" "<<cols[it.second]<<endl;
            if(rows[it.first]==col) return i;
            if(cols[it.second]==row) return i;
        }
        return 1;
    }
};