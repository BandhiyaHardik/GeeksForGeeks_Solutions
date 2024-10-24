class Solution {
  public:
    vector<int> modifyAndRearrangeArray(vector<int> &arr) {

        int n = arr.size();
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1] and arr[i]!=0){
                arr[i]*=2;
                arr[i+1]=0;
                i++;
            }
        }
        int i=0;
        for(int j=0;j<n;j++){
            if(arr[j]){
                swap(arr[i],arr[j]);
                i++;
            }
        }
        return arr;
    }
};