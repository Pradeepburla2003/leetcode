class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int pos,ind,count=0,n=nums.size();
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(i+2<n and nums[i]<=nums[i+2]) pos=i+1;
                else pos=i;
                count++;
            }
            if(count>1) return 0;
        }
        cout<<pos<<endl;
        if(count==0 or pos==0 or pos==nums.size()-2) return 1;
        if(nums[pos+1]-nums[pos-1]>=0) return 1;
        return 0;
    }
};