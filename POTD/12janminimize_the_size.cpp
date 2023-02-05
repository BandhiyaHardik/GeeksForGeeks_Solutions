class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        // code here
        int sum = 0;
        if(N == 1)
            return sum;
          map<int, int>m;
        for(auto x: arr)
            m[x]++;
        while(m.size() != 1 || m.begin()-> second > 1){
            int sum1 = 0;
            for(int i=0;i<2;i++){
                auto x = m.begin();
                x->second--;
                sum1 += x->first;
                if(x->second == 0)
                     m.erase(x);
            }
            m[sum1]++;
            sum += sum1;
        }
        return sum;
        
    }
};