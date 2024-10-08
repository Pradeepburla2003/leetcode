class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<int>dis(n,0);
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][2],edges[i][1]});
            adj[edges[i][1]].push_back({edges[i][2],edges[i][0]});
        }
        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            pq.push({0,i});
             vector<int>vis(n,1e9);
            vis[i]=0;
            while(!pq.empty()){
                int weight=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(int j=0;j<adj[node].size();j++){
                    int adjnode=adj[node][j].second;
                    int adjweight=adj[node][j].first;
                    if(weight+adjweight<vis[adjnode] and weight+adjweight<=distanceThreshold){
                        pq.push({weight+adjweight,adjnode});
                        vis[adjnode]=weight+adjweight;
                    }
                }
            }
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (vis[j] <= distanceThreshold) count++;
            }
            dis[i] = count - 1;
        }
        int ans=0,mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(dis[i]<=mini){
                mini=dis[i];
                ans=i;
            }
        }
        return ans;
    }
};