class Solution{   
    public:
        string printMinNumberForPattern(string s){
            int n = s.size();
            
            int i = 0;
            
            string ans = "1";
            int cur = 2;
            
            while(i < n){
                if(s[i] == 'D'){
                    int pos = i;
                    while(pos < n and s[pos] == 'D')
                        ++pos;
                        
                    int dx = pos - i;
                    int nx = cur + dx - 1;
                    
                    ans.pop_back();
                    
                    while(nx >= cur - 1){
                        ans += to_string(nx);
                        --nx;
                    }
                    
                    cur += dx;
                    i += dx;
                }
                else{
                    ans += to_string(cur);
                    ++cur;
                    ++i;
                }
            }
            
            return ans;
        }
    };