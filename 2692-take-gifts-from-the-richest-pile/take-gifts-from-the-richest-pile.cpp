class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto i:gifts) pq.push(i);
        int n = gifts.size()-1;
        while(k>0){
            int temp = int(sqrt(pq.top()));
            pq.pop();
            k--;
            pq.push(temp);
        }
        long long ans = 0;
        while(pq.size() > 0){
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};