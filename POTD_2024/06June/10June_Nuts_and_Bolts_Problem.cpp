class Solution {
  public:

    void matchPairs(int n, char nuts[], char bolts[]) {
        char temp[]={'!','#','$','%','&','*','?','@','^'};
        unordered_map<char,int> mm;
        int j=0;
        for(int i=0;i<n;i++)mm[nuts[i]]++;
        for(int i=0;i<9;i++){
            if(mm[temp[i]]){
                nuts[j]=temp[i];
                bolts[j]=temp[i];
                j++;
            }
        }
    }
};