class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeros+=1;
        }
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]!=0){
                nums[i++]=nums[j];
            }
            j++;
        }
        for(i=nums.size()-zeros;i<nums.size();i++) nums[i]=0;

    }
};