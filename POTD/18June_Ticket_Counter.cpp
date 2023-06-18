class Solution {
  public:
    int distributeTicket(int N, int K) {
    int st=1; int end=N;
        while(st<end)
        {
            int time=K;
            while(st<end && time-- >0) st++;
            time=K;
            while(st<end && time-- >0) end--;
            
        }
        return st;
        
    }
};