class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int,int>mp;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=1;
        for(auto i:mp){
            int c=1,k1=i.first,k2=i.first;
            if(s.find(k1)!=s.end()) continue;
            s.insert(i.first);
            while(mp.find(k1+1)!=mp.end()){
                c++;
                k1++;
                s.insert(k1);
            }
            while(mp.find(k2-1)!=mp.end()){
                c++;
                k2--;
                s.insert(k2);
            }
            ans=max(ans,c);
        }
        return ans;
    }
};