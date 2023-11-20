class Solution{
  public:
      int mod = 1000000007;
        int ans;
        unordered_map<int, int> mp;
    int sumK(Node *root,int k)
    {
       mp.clear();
        ans = 0;
        dfs(root, k, 0);
        return ans;
    }

    void dfs(Node* root, int k, int cur) {
        if (root == nullptr)
            return;

        if ((cur + root->data) == k)
            ans = (ans + 1) % mod;

        ans = (ans + mp[(cur + root->data - k)] + mod) % mod;

        mp[cur + root->data] = (mp[cur + root->data] + 1) % mod;

        dfs(root->left, k, cur + root->data);
        dfs(root->right, k, cur + root->data);

        mp[cur + root->data] = ((mp[cur + root->data] - 1) + mod) % mod;
    }
};