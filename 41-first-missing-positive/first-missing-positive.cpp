class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int j,k=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                j=i;
                break;
            }
        }
        // cout<<j<<" ";
        for(int i=j;i<nums.size();i++){
            if(nums[i]!=k && i==0) return k;
            if(i>=1 && nums[i]!=nums[i-1] && nums[i]!=k) return k;
            if(i>=1 && nums[i]==nums[i-1]) continue;
            // cout<<k<<" ";
            k+=1;
        }
        return k;
    }
};