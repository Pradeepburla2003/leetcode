class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int xorVal=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                xorVal^=grid[i][j];
            }
        }
        int n=grid.size()*grid.size(),i=1;
        while(i<=n) xorVal^=(i++);
        int bitPos=0;
        while(bitPos<32){
            if(xorVal&(1<<bitPos)) break;
            bitPos++;
        }
        int zeros=0,ones=0;
        for(i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]&(1<<bitPos)) ones^=grid[i][j];
                else zeros^=grid[i][j];
            }
        }
        for(i=1;i<=n;i++){
            if(i&(1<<bitPos)) ones^=i;
            else zeros^=i;
        }
        int zeroCount=0,oneCount=0;
        for(i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(zeros==grid[i][j]) zeroCount++;
            }
        }
        // cout<<zeros<<" "<<zeroCount<<endl<<ones<<" "<<oneCount<<endl;
        if(zeroCount==2) return {zeros,ones};
        return {ones,zeros};
    }
};