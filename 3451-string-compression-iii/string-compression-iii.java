class Solution {
    public String compressedString(String word) {
        int i = 0;
        String ans = "";
        while(i<word.length()){
            int count = 1;
            char ch = word.charAt(i);
            while(i+1<word.length() && word.charAt(i) == word.charAt(i+1)){
                count++;
                i++;
                if(count == 9) break;
            }
            // System.out.println(count);
            ans = ans + String.valueOf(count) + ch;
            i+=1;
        }
        return ans;
    }
}