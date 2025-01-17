class Solution {
public:
    bool help(vector<int>original,vector<int>derived){
        int size=original.size();
        for(int j=2;j<size;j++){
            original[j]=original[j-1]^derived[j-1];
        }
        for(int i=0;i<size-1;i++){
            if((original[i]^original[i+1])!=derived[i]) return false;
        }
        return ((original[0]^original[size-1])==derived[size-1]);
    }
    bool doesValidArrayExist(vector<int>& derived) {
        int size=derived.size();
        if(size<2) return derived[0]^1;
        vector<int>original(size);
        if(derived[0]==0){
            original[0]=0,original[1]=0;
            if(help(original,derived)) return true;
            original[0]=1,original[1]=1;
            if(help(original,derived)) return true;
        }
        else{
            original[0]=0,original[1]=1;
            if(help(original,derived)) return true;
            original[0]=1,original[1]=0;
            if(help(original,derived)) return true;
        }
        return false;
    }
};