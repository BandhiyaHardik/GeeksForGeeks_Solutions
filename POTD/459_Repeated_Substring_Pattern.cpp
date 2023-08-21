class Solution {
public:
    bool repeatedSubstringPattern(string s) {

        string t = s; 
        
        for(int i=0; i<s.size()-1; i++){ 
            t.push_back(t[0]);
            t.erase(0,1);
            if(t==s) { 
                return true; 
            }
        }
        return false;
    }
};