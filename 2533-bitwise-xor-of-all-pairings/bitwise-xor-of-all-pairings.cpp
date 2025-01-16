class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int size1=nums1.size(),size2=nums2.size();
        int ans=0;
        if(size1%2){
            for(auto i:nums2) ans^=i;
        }
        if(size2%2){
            for(auto i:nums1) ans^=i;
        }
        return ans;
    }
};