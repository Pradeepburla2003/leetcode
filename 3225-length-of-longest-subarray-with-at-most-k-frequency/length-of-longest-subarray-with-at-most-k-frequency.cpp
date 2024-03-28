class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int,int>mp;
        int maxi=1,j=0,i=0,n=nums.size();
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                maxi=max(maxi,j-i);
                for(int l=i;l<j;l++){
                    if(nums[l]==nums[j]){
                        mp[nums[l]]--;
                        i=l+1;
                        break;
                    }
                    else{
                        mp[nums[l]]--;
                    }
                }
            }
            j+=1;
        }
        maxi=max(maxi,j-i);
        return maxi;
    }
};