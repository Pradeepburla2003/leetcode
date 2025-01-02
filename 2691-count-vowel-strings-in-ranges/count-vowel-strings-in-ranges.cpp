class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>temp(words.size()),ans(queries.size());
        int count = 0;
        for(int i=0;i<words.size();i++){
            string word = words[i];
            int n = word.size()-1;
            if((word[0]=='a' || word[0]=='e' || word[0]=='i' ||word[0]=='o' || word[0]=='u') &&
                (word[n]=='a' || word[n]=='e' || word[n]=='i' ||word[n]=='o' || word[n]=='u')){
                    count++;
            }
            temp[i]=count;
            cout<<temp[i]<<" ";
        }
        for(int i=0;i<queries.size();i++){
            if(queries[i][0]==0) ans[i]=temp[queries[i][1]];
            else ans[i]=temp[queries[i][1]]-temp[queries[i][0]-1];
        }
        return ans;
    }
};