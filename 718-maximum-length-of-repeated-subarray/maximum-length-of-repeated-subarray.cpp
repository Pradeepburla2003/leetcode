class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        vector<int>cur(n1+1,0),prev(n2+1,0);
        int ans=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(nums1[i-1]==nums2[j-1]){
                    cur[j]=1+prev[j-1];
                    ans=max(ans,cur[j]);
                }
                else cur[j]=0;
            }
            prev=cur;
        }
        return ans;
    }
};