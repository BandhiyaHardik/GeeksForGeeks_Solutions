class Solution {
  public:
    int isValid(string s) {

    int n=s.size();
    if(n<7) return 0;
    int dots=0;

    for(int i=0;i<n;i++){
        if(i>0 && s[i]==s[i-1] && s[i]=='.') return 0;
        if(s[i]=='.') dots++;
    }
    if(dots!=3) return 0;
    
    string num="";
    for(int i=0;i<=n;i++){
        if(s[i]=='.'||i==n){
            if(num.size()==0 || (num[0]=='0' && num.size()>1) || num.size()>3) return 0;
            int number=stoi(num);
            if(number>255) return 0;
            num="";
        }
        else num+=s[i];
    }
    return 1;
    }
};