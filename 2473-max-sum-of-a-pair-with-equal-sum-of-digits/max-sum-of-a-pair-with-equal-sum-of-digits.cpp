class Solution {
public:
    int maximumSum(vector<int>& nums) {
        map<int,vector<int>>mp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int temp = nums[i];
            while(nums[i]>0){
                int rem = nums[i]%10;
                sum+=rem;
                nums[i]=nums[i]/10;
            }
            mp[sum].push_back(temp);
        }
        int ans = -1;
        for(auto i:mp){
            auto temp = i.second;
            int size = temp.size();
            if(temp.size()>=2){
                ans = max(ans,temp[size-1]+temp[size-2]);
            }
        }
        return ans;
    }
};