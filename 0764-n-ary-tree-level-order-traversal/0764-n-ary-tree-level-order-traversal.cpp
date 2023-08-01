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
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*> que;
        que.push(root);
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        
        while(!que.empty()){
            int sz = que.size();
            vector<int> level;
            for(int i = 0; i < sz; i++){
                Node* curr = que.front();
                que.pop();
                if(curr!=NULL)
                level.push_back(curr->val);
                else
                    break;
                
                for(auto node :curr->children){
                
                    que.push(node);
                }
            }
            ans.push_back(level);
        }
        return ans;
    }
};