class Solution{
    public:
    int DivisibleByEight(string s){
        int n=s.length();
        if(n<3){
            while(n<3){
                s='0'+s;
                n++;
            }
        }
        
        int number=0;
        for(int i=n-3;i<=n-1;i++){
            number=number*10+(s[i]-'0');
        }
        if(number%8==0){
            return 1;
        }
        else{
            return -1;
        }
    }
};