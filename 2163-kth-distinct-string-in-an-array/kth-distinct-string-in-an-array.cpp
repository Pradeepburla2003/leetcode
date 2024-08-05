class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int count=0;
        for(int i=0;i<arr.size();i++){
            int flag=0;
            for(int j=0;j<arr.size();j++){
                if(arr[i]==arr[j] and i!=j){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                count+=1;
                if(count==k) return arr[i];
            }
        }
        return "";
    }
};