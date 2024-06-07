class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>vec(matrix[0].size(),0);
        vector<vector<int>>visited(matrix.size(),vec);
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(visited[i][j]==0){
                    if(matrix[i][j]==0){
                        for(int k=0;k<matrix[0].size();k++){
                            if(matrix[i][k]!=0){
                                matrix[i][k]=0;
                                visited[i][k]=1;
                            }
                        }
                        for(int k=0;k<matrix.size();k++){
                            if(matrix[k][j]!=0){
                                matrix[k][j]=0;
                                visited[k][j]=1;
                            }
                        }
                    }
                }
            }
        }
    }
};