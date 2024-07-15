class Solution {
  public:
     string smallestNumber(int s, int d) {

        string ans="";
        int i=1;
        while(i<=d){
            int num = s-(d-i)*9<=0?0:s-(d-i)*9;
            if(num==0 and i==1)num=1;
            if(num>9)return "-1";
            ans+=(num+'0');
            i++;
            s-=num;
        }
        return ans;
    }
};