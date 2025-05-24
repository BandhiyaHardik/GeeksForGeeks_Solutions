class Solution {
  public:
    int sumSubstrings(string &s) {

        long long int sum=0;
        long long int mf=1;
        for(int i=s.size()-1;i>=0;i--){
            sum+=(s[i]-'0')*(i+1)*mf;
            mf=mf*10+1;
        }
        return sum;
    }
};