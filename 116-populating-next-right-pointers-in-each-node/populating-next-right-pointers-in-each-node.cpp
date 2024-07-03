/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*>q;
        Node* ans=root;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<Node*>vc;
            for(int i=0;i<size;i++){
                Node* temp=q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    vc.push_back(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                    vc.push_back(temp->right);
                }
            }
            if(vc.size()==0) break;
            
            for(int i=0;i<vc.size()-1;i++){
                cout<<vc[i]->val<<" ";
                vc[i]->next=vc[i+1];
            }
            cout<<endl;
            // return ans;
        }
        return ans;
    }
};