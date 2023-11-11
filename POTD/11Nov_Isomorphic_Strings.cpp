class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string s1, string s2)
    {
        
        int n1 = s1.length(), n2 = s2.length();
        if (n1 != n2)
            return false;

        unordered_map<char, char> map; 
        unordered_map<char, int> vis; 

        for (int i = 0; i < n1; i++) {
            char c1 = s1[i], c2 = s2[i];
            if (map.find(c1) == map.end())
            {
                if (vis.find(c2) == vis.end()) {
                    map[c1] = c2;
                    vis[c2] = 1;
                } 
                else if (vis[c2] == 1) 
                return false;
            }
            
            else if (map[c1] != c2) 
                return false;
            
        }
        return true;
        
    }
};