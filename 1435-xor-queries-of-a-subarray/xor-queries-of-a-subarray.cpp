class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans,prefix;
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum ^= arr[i];
            prefix.push_back(sum);
            cout<<sum<<" ";
        }
        for(int i=0; i<queries.size(); i++){
            if(queries[i][0] == 0){
                ans.push_back(prefix[queries[i][1]]);
            }
            else{
                int temp = prefix[queries[i][0]-1] ^ prefix[queries[i][1]];
                ans.push_back(temp);
            }
        }
        return ans;
    }
};