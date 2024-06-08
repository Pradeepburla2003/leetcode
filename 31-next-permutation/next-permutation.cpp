class Solution {
public:
    set<vector<int>>s;
    void permutation(vector<int>&nums,vector<int>&visited,vector<int>&temp){
        for(int j=0;j<nums.size();j++){
            if(visited[j]==0){
                visited[j]=1;
                temp.push_back(nums[j]);
                permutation(nums,visited,temp);
                if(temp.size()==nums.size()) s.insert(temp);
                temp.pop_back();
                visited[j]=0;
            }
        }
    }
    void nextPermutation(vector<int>& nums) {
        // // if(nums.size()==1) return;
        // // for(int i=0;i<nums.size();i++){
        // //     vector<int>visted(nums.size(),0);
        // //     vector<int>temp;
        // //     temp.push_back(nums[i]);
        // //     visted[i]=1;
        // //     permutation(nums,visted,temp);
        // // }
        // // vector<vector<int>>myvec(s.begin(),s.end());
        // // auto i=s.find(nums);
        // // int pos=distance(s.begin(),i);
        // // pos+=1;
        // // pos=pos%(myvec.size());
        // // for(int j=0;j<nums.size();j++){
        // //     nums[j]=myvec[pos][j];
        // // 
        // //2 int a[nums.size()];
        // // int n=nums.size();
        // // for(int i=0;i<nums.size();i++){
        // //     a[i]=nums[i];
        // // }
        // // next_permutation(a,a+n);
        // // for(int i=0;i<n;i++){
        // //     nums[i]=a[i];
        // // }
        // next_permutation(nums.begin(),nums.end());
        int ind=-1;
        for(int i=nums.size()-2;i>-1;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        // return;
        if(ind==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=nums.size()-1;i>=ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
    }
};