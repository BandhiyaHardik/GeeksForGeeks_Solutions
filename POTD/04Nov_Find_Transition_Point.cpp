class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
         int l=0; int h=n-1;
        while(l<=h)
        {
            int m = (l+h)/2;
            if(arr[m]==0)
            l=m+1;
            
            else if(arr[m]==1)
            {
                if(m-1>=0 && arr[m-1]==1)
                h=m-1;
                
                else
                return m;
            }
        }
        return -1;
    }
};