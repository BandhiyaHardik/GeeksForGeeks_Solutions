class meet {
    public:
    int start, end, index;
    
    meet(int a, int b, int c){
        start = a;
        end = b;
        index = c;
    }
};

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<meet> times;
        
        for(int i = 0; i < N; i++){
            times.emplace_back(meet(S[i], F[i], i + 1));
        }
        
        sort(times.begin(), times.end(), [](meet &a, meet &b){
            if(a.end == b.end){
                return a.index < b.index;
            }
            
            return a.end < b.end;
        });
        
        vector<int> ans;
        int lastEnd = -1;
        
        for(int i = 0; i < N; i++){
            if(times[i].start > lastEnd){
                ans.push_back(times[i].index);
                lastEnd = times[i].end;
            }    
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};