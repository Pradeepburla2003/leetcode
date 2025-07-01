class Solution {
    public int possibleStringCount(String word) {
        int ans=1,i=0,n=word.length();
        while(i<n){
            int j=i+1;
            while(j<n && word.charAt(i)==word.charAt(j)) j++;
            ans+=j-i-1;
            i=j;
        }
        return ans;
    }
}