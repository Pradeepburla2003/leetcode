class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>mp;
        vector<int>ans;
        int count = 0;
        for(int i=0;i<A.size();i++){
            mp[A[i]]++;
            mp[B[i]]++;
            count+=2;
            ans.push_back(count-mp.size());
        }
        return ans;
    }
};