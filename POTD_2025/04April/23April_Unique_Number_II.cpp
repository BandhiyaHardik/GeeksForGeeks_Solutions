class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {

        int xor_all=0;
        for(int it:arr) xor_all^=it;
        
        int set_bit=xor_all & -xor_all;
        int G1=0,G0=0;
        for(int it : arr){
            if(it & set_bit) G1^=it;
            else G0^=it;
        }
        if(G1<G0) return {G1,G0};
        else return {G0,G1};
    }
};