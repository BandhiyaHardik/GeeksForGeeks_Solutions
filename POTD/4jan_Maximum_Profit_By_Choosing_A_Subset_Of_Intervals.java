class Solution {
    public static int maximum_profit(int n, int[][] intervals) {
        
        Arrays.sort(arr,(a,b)->{
            if(a[1]!=b[1]) return a[1]-b[1];
            return a[0]-b[0];
    });
    int[]dp=new int[n];
    return rec(n-1,arr,n,dp);
    }
    static int rec(int index,int[][]arr,int n,int[]dp){
    if(index<=0)return 0;
    if(dp[index]!=0)return dp[index];
    int not_select=rec(index-1,arr,n,dp);
    int nextIndex = findNext(index-1,arr[index][0],arr,n);
    int select = arr[index][2] + rec(nextIndex,arr,n,dp);
    return dp[index]=Math.max(select,not_selct);
    }
    static int findNext(int i,int prevStrat,int[][]arr,int n){
        while(i>=0){
            if(arr[i][1]<=prevStrat){
                break;
            }else{
                i--;
            }
        }
        return i;
    }
}