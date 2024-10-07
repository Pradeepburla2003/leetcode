class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indeg(numCourses);
        vector<vector<int>>adj(numCourses);
        for(auto node:prerequisites){
            indeg[node[0]]++;
            adj[node[1]].push_back(node[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>res;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto it:adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        return (res.size()==numCourses)?res:vector<int>{};
    }
};