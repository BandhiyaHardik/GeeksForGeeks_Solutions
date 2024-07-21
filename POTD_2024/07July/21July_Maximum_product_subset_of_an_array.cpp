class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {

        if(arr.size()==1)return arr[0];
        long long int pos=1,neg=1,negLar=INT_MIN,mod=1e9+7,c1=0,c2=0;
        for(auto x:arr){
            if(x<0){
                neg=(neg*(long long int)x)%mod;
                negLar = max((long long int)x,negLar);
                c1++;
            }
            if(x>0){
                pos=(pos*(long long int)x)%mod;
                c2++;
            }
        }
        if(c1<=1 and c2==0)return 0;
        if(neg<0)neg/=negLar;
        return (pos*neg)%mod;
    }
};