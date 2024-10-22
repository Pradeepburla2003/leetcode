class Solution {
public:
    struct comp{
        bool operator()(pair<int,string>a,pair<int,string>b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(int i=0;i<words.size();i++) mp[words[i]]++;
        priority_queue<pair<int,string>,vector<pair<int,string>>,comp>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        vector<string>ans;
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};