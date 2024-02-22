class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ind=1,c=0,k=trust.size();
        if(n-k>1){
            // cout<<n<<" "<<trust.size()<<endl<<(n-trust.size());
            return -1;
        }
        vector<int>temp(n+1,0);
        for(int i=0;i<trust.size();i++){
            temp[trust[i][1]]++;
            if(temp[trust[i][1]]>c){
                c=temp[trust[i][1]];
                ind=trust[i][1];
            }
        }
        for(int i=0;i<trust.size();i++){
            if(trust[i][0]==ind) return -1;
        }
        if(temp[ind]==n-1) return ind;
        return -1;
        
    }
};