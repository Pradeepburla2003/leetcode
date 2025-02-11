class Solution {
public:
    int countpairs(vector<int>&nums,int i,int mid,int j){
        int count=0,right=mid+1;
        for(int start=i;start<=mid;start++){
           while (right <= j && nums[start] > 2LL * nums[right]) {
                right++;
            }
            count+=right-(mid+1);
        }
        return count;
    }
    void merge(vector<int>&nums,int i,int mid,int j){
        int start=i,midle=mid+1,count=0;
        vector<int>ans;
        while(start<=mid and midle<=j){
            if(nums[start]<=nums[midle]){
                ans.push_back(nums[start]);
                start++;
            }
            else{
                ans.push_back(nums[midle]);
                midle++;
            }
        }
        while(start<=mid){
            ans.push_back(nums[start++]);
        }
        while(midle<=j){
            ans.push_back(nums[midle++]);
        }
        for(int k=0;k<ans.size();k++){
            nums[i++]=ans[k];
        }
    }
    int mergesort(vector<int>&nums,int i,int j){
        int count=0;
        if(i<j){
            int mid=(i+j)/2;
            count+=mergesort(nums,i,mid);
            count+=mergesort(nums,mid+1,j);
            count+=countpairs(nums,i,mid,j);
            merge(nums,i,mid,j);
        }
        return count;
    }
    int reversePairs(vector<int>& nums) {
        return mergesort(nums,0,nums.size()-1);
    }
};