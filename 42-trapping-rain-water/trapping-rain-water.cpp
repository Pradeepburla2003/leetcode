class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,n=height.size(),j=n-1;
        vector<int>left(n),right(n);
        int maxl=INT_MIN,maxr=INT_MIN;
        while(i<n){
            maxl=max(maxl,height[i]);
            maxr=max(maxr,height[j]);
            left[i++]=maxl;
            right[j--]=maxr;
        }
        int ans=0;
        for(i=0;i<n;i++){
            ans+=min(left[i],right[i])-height[i];
        }
        return ans;
    }
};