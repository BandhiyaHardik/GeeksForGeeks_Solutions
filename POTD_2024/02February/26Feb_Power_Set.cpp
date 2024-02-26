class Solution{
	public:
		vector<string> ans;
        void f(string s, int idx, string temp){
            if(idx==s.size()){
                if(temp.size()!=0)
                ans.push_back(temp);
                return;
            }
            f(s,idx+1, temp+s[idx]);
            f(s, idx+1, temp);
        }
        vector<string> AllPossibleStrings(string s){
            f(s,0,"");
            sort(ans.begin(), ans.end());
            return ans;
        }
};