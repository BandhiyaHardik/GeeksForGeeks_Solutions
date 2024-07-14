class Solution {
  public:
     void segregate0and1(vector<int> &arr) {

        int zero=0,one=arr.size()-1;
        while(zero<one){
            if(arr[zero]){
                swap(arr[zero],arr[one]);
                one--;
            }
            else zero++;
        }
    }
};