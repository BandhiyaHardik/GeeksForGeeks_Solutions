class Solution {
  public:
    string countAndSay(int n) {

        if(n==1) return "1";
        string curr="1";
        for(int i=2;i<=n;i++){
            string curr_i="";
            int count =1;
            for(int j=1;j<curr.length();j++){
                if(curr[j]==curr[j-1]) count++;
                else{
                    curr_i+=to_string(count) + curr[j-1];
                    count=1;
                }
            }
            curr_i+=to_string(count) + curr.back();
            curr=curr_i;
        }
        return curr;
    }
};