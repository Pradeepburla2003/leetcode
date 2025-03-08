class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans=k,blacks=0,white=0,start=0;
        for(int i=0;i<blocks.size();i++){
            if(blocks[i]=='B') blacks++;
            else white++;
            if(i-(k-1)>=0){
                ans=min(ans,k-blacks);
                if(blocks[start]=='B') blacks--;
                else white--;
                start++;
            }
        }
        return ans;
    }
};