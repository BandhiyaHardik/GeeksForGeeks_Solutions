class Solution {
    public:
    
    void solve(Node* root, int level, unordered_set<Node*>& result, vector<Node*>& path, int& k) {
        if(!root) {
            return;
        }
        
        path.push_back(root);
        if(!root->left && !root->right) {
            if(level - k >= 0) {
                result.insert(path[level-k]);
            }
        }
        
        solve(root->left, level+1, result, path, k);
        solve(root->right, level+1, result, path, k);
        path.pop_back();
    }
    
    //Function to return count of nodes at a given distance from leaf nodes.
    int printKDistantfromLeaf(Node* root, int k) {
        vector<Node*> path;
        unordered_set<Node*> result;
    	
    	solve(root, 0, result, path, k);

    	return result.size();
    }
};
