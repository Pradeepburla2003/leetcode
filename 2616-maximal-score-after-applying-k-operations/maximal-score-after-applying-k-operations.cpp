class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans = 0;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
        while(k > 0 && !pq.empty()){
            int val = pq.top();
            ans+=val;
            pq.pop();
            if(val%3==0) pq.push(val/3);
            else pq.push((val/3)+1);
            k--;
        }
        return ans;
    }
};