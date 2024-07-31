class Solution {
  public:

     string longestCommonPrefix(vector<string> arr) {

        string temp = arr[0];
        int i=0,j=0;
        while(i<temp.length()){
            for(j=0;j<arr.size();j++){
                if(temp[i]!=arr[j][i])break;
            }
            if(j!=arr.size())break;
            i++;
        }
        if(i==0)return "-1";
        return temp.substr(0,i);
    }
};