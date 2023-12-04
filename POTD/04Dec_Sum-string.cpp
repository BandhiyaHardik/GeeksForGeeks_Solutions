class Solution{   
public:
    int isSumString(string S){
        int n = S.size();
        
        auto sum = [](string a, string b) -> string {
            string ans = "";
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            
            int carry = 0;
            int index = 0;
            
            while(index < a.size() and index < b.size()){
                int sum = (a[index] - '0') + (b[index] - '0') + carry;
                carry = sum / 10;
                sum = sum % 10;
                
                ans += to_string(sum);
                ++index;
            }
            
            while(index < a.size()){
                int sum = (a[index] - '0') + carry;
                carry = sum / 10;
                sum = sum % 10;
                
                ans += to_string(sum);
                ++index;
            }
            
            while(index < b.size()){
                int sum = (b[index] - '0') + carry;
                carry = sum / 10;
                sum = sum % 10;
                
                ans += to_string(sum);
                ++index;
            }
            
            if(carry){
                ans += to_string(carry);
            }
            
            reverse(ans.begin(), ans.end());
            
            return ans;
        };
        
        function<bool(string &, string&, int, bool)> helper = [&](string &a, string &b, int p, bool valid) -> bool {
            if(p == n)
                return valid;
                
            string need = sum(a, b);
            
            string cur = "";
            
            for(int i = p; i < n; i++){
                cur += S[i];
                
                if(cur == need)
                    return helper(b, cur, i + 1, 1);
            }
            
            return 0;
        };
        
        for(int i = 1; i < n + 1; i++){ 
            for(int j = i + 1; j < n + 1; j++){ 
                string a = S.substr(0, i);
                string b = S.substr(i, j - i);
                
                if(helper(a, b, j, 0))
                    return 1;
            }
        }
        
        return 0;
    }
};
