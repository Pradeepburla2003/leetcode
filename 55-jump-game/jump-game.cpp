class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int c=0,n=nums.size();
        for(int i=0;i<nums.size();i++){
            c=0;
            if(nums[i]==0){
                for(int j=i-1;j>=0;j--){
                    if(nums[j]>(i-j) or i==n-1){
                        c=1;
                        break;
                    }
                }
                if(c==0) return 0;
            }
        }
        return 1;
    }
};