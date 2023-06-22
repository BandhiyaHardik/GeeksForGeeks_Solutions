class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int five=0; int ten=0;
        for(int i=0; i<N; i++)
        {
            int x = bills[i];
            if(x==5)
            five++;
            else if(x==10)
            {
                five--; ten++;
            }
            else
            {
                if(x==20)
                {
                    if(ten>0)
                    {
                        ten--; five--;
                    }
                    else
                    {
                        five-=3;
                    }
                }
            }
            if(five<0)
            return false;
        }
        return true;
    }
};