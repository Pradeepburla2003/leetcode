class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int c=0,i;
        vector<int>ans;
        for(i=0;i<arr.size();i++)
        {
            ans.push_back(arr[i]);
        }
        sort(arr.begin(),arr.end());
        int c1=0,c2=0;
        for(i=0;i<arr.size();i++)
        {
            c1+=arr[i];
            c2+=ans[i];
            if(c1==c2)
            {
                c+=1;
            }
        }
        return c;
    }
};