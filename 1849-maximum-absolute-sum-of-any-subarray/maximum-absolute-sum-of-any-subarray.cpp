class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum1=0,sum2=0,maxi=-1e9;
        for(int i=0;i<nums.size();i++){
            sum1+=nums[i];
            sum2+=nums[i];
            maxi=max(maxi,max(abs(sum1),abs(sum2)));
            if(sum1<0) sum1=0;
            if(sum2>0) sum2=0;
        }
        return maxi;
    }
};