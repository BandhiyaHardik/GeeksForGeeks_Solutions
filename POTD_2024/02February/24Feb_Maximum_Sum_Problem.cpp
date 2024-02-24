class Solution
{
    public:
        int maxSum(int n)
        {
            int ans=0;
            queue<int> q;
            q.push(n);
            while(q.size()>0){
                int x=q.front();
                q.pop();
                if(x/2+x/3+x/4>x){
                    q.push(x/2);
                    q.push(x/3);
                    q.push(x/4);
                }
                else{
                    ans+=x;
                }
            }
            return ans;
        }
};