class Solution {
public:
    vector<int>ans;
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>temp(nums.begin(),nums.end());
       sort(temp.begin(),temp.end());
       int i=0,j=nums.size()-1;
       while(i<j){
        if(temp[i]+temp[j]==target) break;
        else if(temp[i]+temp[j]<target) i++;
        else j--;
       }
       int n=nums.size()-1;
       for(int k=0;k<=n;k++){
        if(nums[k]==temp[i]){
            i=k;
            break;
        }
       }
       for(int k=n;k>=0;k--){
        if(nums[k]==temp[j]){
            j=k;
            break;
        }
       }
       if(i>j) swap(i,j);
       ans.push_back(i);
       ans.push_back(j);
       return ans;
    }
};