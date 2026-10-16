/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==nullptr) return 0;
        queue<Node*>q;
        q.push(root);
        int l=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=1;i<=size;i++){
                Node*node=q.front();
                q.pop();
                for(Node*child:node->children){
                    q.push(child);
                }
            }
            l++;
        }
        return l;
    }
};