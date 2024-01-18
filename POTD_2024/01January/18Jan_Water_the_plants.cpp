class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        vector<pair<int,int>> cover(n);
        
        for(int i = 0; i < n; i++){
            if(gallery[i] == -1)
                cover[i] = {1e7, 1e7};
            else
                cover[i] = {i - gallery[i], i + gallery[i]};
        }
        
        sort(cover.begin(), cover.end());
        
        int take = 0, index = 0, ans = 0;
        
        while(take < n){
            int nax = take - 1;
            
            while(index < n and cover[index].first <= take){
                nax = max(nax, cover[index++].second);
            }
            
            if(nax + 1 > take){
                ++ans;
                take = nax + 1;
            }
            else
                return -1;
        }
        
        return ans;
    }
};