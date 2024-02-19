class Solution{
public:
    int minValue(string s, int k){
        unordered_map<char,int> mm;
        for(auto x:s)mm[x]++;
        priority_queue<int> pq;
        for(auto x:mm)pq.push(x.second);
        int ans = 0;
        while(k--){
            int temp = pq.top();
            pq.pop();
            temp--;
            pq.push(temp);
        }
        while(pq.size()){
            int temp = pq.top();
            pq.pop();
            ans+=temp*temp;
        }
        return ans;
    }
};