class Solution
{
  public:
    int minOperation(int n)
    {
        int res=0;
       while(n>0)
       {
           if(n%2==0)
               n=n/2;
            else
            n--;
            
            res++;
       }
       return res;
    }
};