class Solution {
    public boolean canMakeSubsequence(String str1, String str2) {
        int j = 0;
        for(int i=0;i<str1.length();i++){
            if(j>=str2.length()) return true;
            if(str1.charAt(i)=='y' && str2.charAt(j)=='z') j++;
            else if (str1.charAt(i)=='a' && str2.charAt(j)=='z'){
                
            }
            else{
                int c1 = (str1.charAt(i) - 'a')%25 ;
                int c2 = (str2.charAt(j) - 'a')%25;
                if (j < str2.length() && c2-c1>=0 && c2-c1<=1) {
                    j++;
                }
                System.out.println(c1 + " " + c2);
            }
        }
        System.out.println(j);
        return j == str2.length();

    }
}