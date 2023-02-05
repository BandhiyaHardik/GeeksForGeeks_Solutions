class Solution {
  public:
    long long int minIncrements(vector<int> arr, int N) {
        // Code here
        sort(arr.begin(),arr.end());
        int pre = arr[0];
        long long int minIncrease=0;
        
        for(int i=1;i<N;i++){
            if(arr[i]<=pre){
                int temp=arr[i];
                arr[i]=pre;
                arr[i]++;
                minIncrease+= (arr[i]-temp);
            }
            pre=arr[i];
        }
        return minIncrease;
    }
};