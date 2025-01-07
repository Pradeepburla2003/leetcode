class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>negative,positive;
        for(int i=0;i<nums.size();i++){
            int res = nums[i]*nums[i];
            if(nums[i]<0) negative.push_back(res);
            else positive.push_back(res);
        }
        int i=negative.size()-1,j=0,k=0;
        while(i>=0 && j<positive.size()){
            if(negative[i]<=positive[j]){
                nums[k++]=negative[i--];
            }
            else{
                nums[k++]=positive[j++];
            }
        }
        while(i>=0) nums[k++]=negative[i--];
        while(j<positive.size()) nums[k++]=positive[j++];
        return nums;
    }
};