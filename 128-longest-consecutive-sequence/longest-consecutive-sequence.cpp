class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        map<int,int>mp;
        set<int>s;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int ans=1,flag=0,temp,c=1;
        for(auto i:mp){
            if(flag==0){
                flag = 1;
            }
            else{
                if(i.first == temp+1){
                    c+=1;
                }
                else{
                    ans = max(ans,c);
                    c=1;
                }
            }
            temp = i.first;
        }
        ans = max(ans,c);
        return ans;
    }
};