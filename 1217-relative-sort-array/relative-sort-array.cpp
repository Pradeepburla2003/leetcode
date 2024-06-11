class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        int j=0;
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]){
                arr1[j]=arr2[i];
                mp[arr2[i]]--;
                j++;
            }
        }
        for(auto i:mp){
            while(i.second){
                arr1[j]=i.first;
                i.second--;
                j++;
            }
        }
        return arr1;
    }
};