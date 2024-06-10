class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp,end=matrix.size();
        for(int i=0;i<matrix.size();i++){
            for(int j=i;j<end;j++){
                temp=matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};