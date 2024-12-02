class Solution {
    public int isPrefixOfWord(String sentence, String searchWord) {
        String[] s = sentence.split(" ");
        int c = 1,k = searchWord.length();
        for(String sam:s){
            if(sam.length() >= k){
                String temp = sam.substring(0,k);
                if(searchWord.equals(temp)) return c;
            }
            c+=1;
        }
        return -1;
    }
}