class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int top=0,bottom=0,left=0,right=0;
        for(int i=0;i<row;i++){
            int flag=0;
            for(int j=0;j<col;j++){
                if(grid[i][j]){
                    flag=1;
                    break;
                }
            }
            if(flag){
                top=i;
                break;
            }
        }
         for(int i=row-1;i>=0;i--){
            int flag=0;
            for(int j=0;j<col;j++){
                if(grid[i][j]){
                    flag=1;
                    break;
                }
            }
            if(flag){
                bottom=i;
                break;
            }
        }
         for(int i=0;i<col;i++){
            int flag=0;
            for(int j=0;j<row;j++){
                if(grid[j][i]){
                    flag=1;
                    break;
                }
            }
            if(flag){
                left=i;
                break;
            }
        }
         for(int i=col-1;i>=0;i--){
            int flag=0;
            for(int j=0;j<row;j++){
                if(grid[j][i]){
                    flag=1;
                    break;
                }
            }
            if(flag){
                right=i;
                break;
            }
        }
        return (bottom-top+1)*(right-left+1);
    }
};