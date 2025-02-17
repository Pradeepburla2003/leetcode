class Solution {
public:
    void help(string tiles,vector<int>&vis,int &count,string temp){
        // cout<<count
        for(int i=0;i<tiles.size();i++){
            if(vis[i]==1 || (i>0 && tiles[i]==tiles[i-1]) && !vis[i-1]) continue;
            temp.push_back(tiles[i]);
            count++;
            vis[i]=1;
            help(tiles,vis,count,temp);
            vis[i]=0;
            temp.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        int count=0;
        vector<int>vis(tiles.size());
        help(tiles,vis,count,"");
        return count;
    }
};