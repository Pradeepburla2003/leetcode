class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),col=matrix[0].size();
        int low=0,high=(row*col)-1,mid=(low+high)/2;
        while(low<=high){
            mid=(low+high)/2;
            if(target==matrix[mid/col][(mid%col)]) return true;
            if(target<matrix[(mid/col)][(mid%col)]){
                high=mid-1;
            }
            else low=mid+1;
        }
        return false;
    }
};