class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>nums((grid.size()*grid.size())+1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                nums[grid[i][j]]++;
            }
        }
        int repeat,missing;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==2) repeat=i;
            if(nums[i]==0) missing=i;
        }
        return {repeat,missing};
    }
};