class Solution {
public:
    int mini=INT_MAX,c=0;
    int findPrice(int src,int dst,map<int,vector<vector<int>>>&mp,int k,vector<vector<int>>&dp){
        // cout<<src<<" "<<dst<<" "<<k<<endl;
        if(k>=-1 && src==dst){
            c=1;
           return 0;
        }
        if(k==-1 && src!=dst) return 1e9;
        if(dp[src][k]!=-1) return dp[src][k];
        
        int dist=1e9;
        for(int i=0;i<mp[src].size();i++){
            dist=min(dist,mp[src][i][1]+findPrice(mp[src][i][0],dst,mp,k-1,dp));
        }
        // mini=min(mini,dist);
        return dp[src][k]=dist;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        map<int,vector<vector<int>>>mp;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        for(int i=0;i<flights.size();i++){
            vector<int>temp;
            temp.push_back(flights[i][1]);
            temp.push_back(flights[i][2]);
            mp[flights[i][0]].push_back(temp);
        }
        // for(auto i:mp){
        //     for(int j=0;j<i.second.size();j++){
        //         cout<<i.second[j][0]<<" "<<i.second[j][1]<<"----";
        //     }
        //     cout<<endl;
        // }
        // cout<<mp[src][0][0]<<" ";
        int res=findPrice(src,dst,mp,k,dp);
        // if(mini==INT_MAX) return -1;
        if(c==0) return -1;
        return res;
    }
};