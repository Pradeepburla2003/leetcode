class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<k-1;i++){
            nums.push_back(nums[i]);
        }
        int ans=0,i=0,count=1;
        for(int j=0;j<nums.size()-1;j++){
            if(nums[j]==nums[j+1]){
                i=j+1;
                count=1;
            }
            else{
                count++;
            }
            if(count==k){
                ans++;
                i++;
                count--;
            }
        }
        return ans;
    }
};