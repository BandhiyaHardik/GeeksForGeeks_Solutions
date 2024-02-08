const int N = 1e5;
const int LOG = log2(N) + 1;
vector<int> def(LOG, -1);

unordered_map<int, vector<int>> up;
unordered_map<int, int> depth;

void settingParents(Node * node, int parent, int d) {
    if(!node)
        return;
        
    int val = node -> data;
    
    up[val] = def;
        
    up[val][0] = parent;
    depth[val] = d;

    for(int i = 1; i < LOG; i++){
        if(up[val][i - 1] != -1)
            up[val][i] = up[up[val][i - 1]][i - 1];
    }

    settingParents(node -> left, node -> data, d + 1);
    settingParents(node -> right, node -> data, d + 1);
}

int get_lca(int x, int y) {
    if(depth[x] < depth[y])
        swap(x, y);

    int dx = depth[x] - depth[y];

    for(int i = LOG - 1; i > -1; i--){
        if((dx >> i) & 1)
            x = up[x][i];
    }

    if(x == y)
        return x;

    for(int i = LOG - 1; i > -1; i--){
        if(up[x][i] != up[y][i]){
            x = up[x][i];
            y = up[y][i];
        }
    }

    return up[x][0];
}

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        settingParents(root, -1, 0);
        
        int lca = get_lca(a, b);
        
        int ans = depth[a] + depth[b] - 2 * (depth[lca]);
        
        return ans;
    }
};