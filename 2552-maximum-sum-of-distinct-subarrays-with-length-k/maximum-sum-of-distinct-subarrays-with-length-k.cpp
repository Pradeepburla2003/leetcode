class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,j=0,n=nums.size(),sum=0;
        unordered_map<int,int>mp;
        int flag=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            sum+=nums[i];
            if(i-j==k-1){
                // cout<<sum<<" "<<mp.size()<<endl;
                if(mp.size()==k){
                    ans=max(ans,sum);
                }
                mp[nums[j]]--;
                sum-=nums[j];
                if(mp[nums[j]]==0){
                    mp.erase(nums[j]);
                }
                j++;
            }
        }
        return ans;
    }
};