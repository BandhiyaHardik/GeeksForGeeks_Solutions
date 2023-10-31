class Solution{
public:
	void pushZerosToEnd(int arr[], int n) {
	  int st=0;
        for(int i=0;i <n; i++)
        {
            if(arr[i]!=0){
                 int t = arr[i];arr[i]=arr[st]; arr[st]=t;
                 st++;
            }
        }
	}
};