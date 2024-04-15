class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,int q) {
        int mx=-1;
        for(int i=0;i<n;i++)mx=max(mx,b[i]);
        vector<int> heap(mx+1,0);
        for(int i=0;i<n;i++)heap[b[i]]++;
        for(int i=1;i<=mx;i++)heap[i]+=heap[i-1];
        vector<int> ans;
        for(int i=0;i<q;i++){
            if(a[query[i]]>mx){
                ans.push_back(n);
            }
            else ans.push_back(heap[a[query[i]]]);
        }
        return ans;
    }
};