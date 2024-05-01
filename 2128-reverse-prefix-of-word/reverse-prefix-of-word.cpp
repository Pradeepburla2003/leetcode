class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos=-1;
        for(int i=0;i<word.size();i++){
            if(word[i]==ch){
                pos=i;
                break;
            }
        }
        if(pos==-1) return word;
        char temp;
        // int end;
        // if(pos%2) end=-1
        for(int i=0;i<=pos;i++){
            temp=word[i];
            word[i]=word[pos];
            word[pos]=temp;
            cout<<i<<" "<<pos<<endl;
            pos--;
        }
        return word;
    }
};