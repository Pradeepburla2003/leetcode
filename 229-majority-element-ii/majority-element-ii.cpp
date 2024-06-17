class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1=INT_MIN,ele2=INT_MIN,count1=0,count2=0;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(count1==0 && nums[i]!=ele2){
                ele1=nums[i];
                count1++;
            }
            else if(count2==0 && nums[i]!=ele1){
                ele2=nums[i];
                count2++;
            }
            else if(nums[i]==ele1){
                count1++;
            }
            else if(nums[i]==ele2){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        count1=0,count2=0;
        // cout<<ele1<<" "<<ele2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele1) count1++;
            else if(nums[i]==ele2) count2++;
        }
        if(count1>(nums.size()/3)) ans.push_back(ele1);
        if(count2>(nums.size()/3)) ans.push_back(ele2);
        return ans;
    }
};