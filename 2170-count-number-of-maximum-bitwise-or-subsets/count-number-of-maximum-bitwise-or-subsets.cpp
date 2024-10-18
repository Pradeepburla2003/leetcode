class Solution {
public:
    void help(vector<int>&nums,vector<int>&bits,int x,int ind,int &maxi){
        if(ind == nums.size()){
            maxi = max(maxi,x);
            bits.push_back(x);
            return ;
        }
        help(nums,bits,x|nums[ind],ind+1,maxi);
        help(nums,bits,x,ind+1,maxi);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int>bits;
        int maxi = INT_MIN,count = 0;
        help(nums,bits,0,0,maxi);
        for(auto i:bits){
            if(maxi == i) count++;
        }
        return count;
    }
};