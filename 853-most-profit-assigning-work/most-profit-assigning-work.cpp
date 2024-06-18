class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>pr;
        int n=difficulty.size();
        for(int i=0;i<n;i++){
            pr.push_back({profit[i],difficulty[i]});
        }
        sort(pr.begin(),pr.end());
        sort(worker.begin(),worker.end());
        int ans=0;
        for(int i=worker.size()-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(pr[j].second<=worker[i]){
                    ans+=pr[j].first;
                    break;
                }
            }
        }
        return ans;
    }
};