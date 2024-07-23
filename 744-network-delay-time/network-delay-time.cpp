class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dist(n+1,1e9);
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][2],times[i][1]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        dist[k]=0;
        int mini=INT_MIN;
        while(!pq.empty()){
            int path=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(int i=0;i<adj[node].size();i++){
                int weight=adj[node][i].first;
                int adjnode=adj[node][i].second;
                if(path+weight<dist[adjnode]){
                    dist[adjnode]=path+weight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            mini=max(mini,dist[i]);
        }
        return mini;
    }
};