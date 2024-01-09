vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            string look = pat + '?' + txt;
            
            vector<int> kmp = prefix_function(look);
            
            vector<int> ans;
            
            int start = 2 * pat.size();
            for(int i = start; i < look.size(); i++){
                if(kmp[i] == pat.size())
                    ans.push_back(i - start + 1);
            }
            
            return ans;
        }
     
};