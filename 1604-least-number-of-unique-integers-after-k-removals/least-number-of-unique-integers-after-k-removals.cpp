class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>temp;
        for(int i=0;i<arr.size();i++){
            temp[arr[i]]++;
        }
        vector<int>temp2;
        for(auto i:temp) temp2.push_back(i.second);
        sort(temp2.begin(),temp2.end());
        int c=0;
        for(int i=0;i<temp2.size();i++){
            if(k<temp2[i]) break;
            c+=1;
            k-=temp2[i];
        }
        return temp2.size()-c;
    }
};