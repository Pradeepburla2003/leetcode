struct Node{
        Node* links[26];
        bool flag = false;
        bool containsKey(char ch){
            return links[ch-'a']!=NULL;
        }
        void put(char ch,Node* node){
            links[ch-'a']=node;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            flag = true;
        }
        bool isEnd(){
            return flag;
        }
    };
class Solution {
public:
    Node* root = new Node();
    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    string help(){
        string prefix="";
        Node* node = root;
        while(true){
            int count=0;
            char nextChar;
            Node* nextNode;
            for(char ch='a';ch<='z';ch++){
                if(node->containsKey(ch)){
                    count++;
                    nextChar=ch;
                    nextNode=node->get(ch);
                }
            }
            if(count==1 && !node->isEnd()){
                prefix+=nextChar;
                node=nextNode;
            }
            else{
                break;
            }
        }
        return prefix;
    }
    string longestCommonPrefix(vector<string>& strs) {
        for(auto s:strs){
            insert(s);
        }
        return help();
    }
};