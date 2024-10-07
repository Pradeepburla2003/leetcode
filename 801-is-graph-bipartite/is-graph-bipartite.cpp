class Solution {
public:
    bool bfs(int i,vector<vector<int>>& graph,vector<int>&vis){
        queue<int>q;
        q.push(i);
        vis[i] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto child:graph[node]){
                if(vis[child]==-1){
                    if(vis[node]==0) vis[child] = 1;
                    else vis[child] = 0;
                    q.push(child);
                }
                else if(vis[child] == vis[node]) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                if(!bfs(i,graph,vis)) return false;
            }
        }
        return true;
    }
};
