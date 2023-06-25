class Solution
{
    public:
    // #define MAX 1000
    vector<vector<int>> uniqueRow(int arr[MAX][MAX],int n,int m)
    {
    vector<vector<int>> ans;
   
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        vector<int> curr;
        for (int j = 0; j < m; j++) {
            curr.push_back(arr[i][j]);
        }
        if (st.find(curr) == st.end()) {
            st.insert(curr);
            ans.push_back(curr);
        }
    }

    return ans;
    }
};