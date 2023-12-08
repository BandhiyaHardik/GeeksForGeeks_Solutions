bool computed = 0;
vector<int> primes;

class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        if(!computed){
            vector<int> isPrime(1e6 + 10, 1);
            isPrime[0] = isPrime[1] = 0;
            
            for(int i = 2; i * i < 1e6 + 10; i++){
                if(isPrime[i]){
                    for(int j = i + i; j < 1e6 + 10; j += i)
                        isPrime[j] = 0;
                }
            }
            
            for(int i = 0; i < 1e6 + 10; i++)
                if(isPrime[i])
                    primes.push_back(i);
                    
            computed = 1;
        }
                
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += arr[i];
            
        auto p = lower_bound(primes.begin(), primes.end(), sum);
        
        return *p - sum;
    }
};