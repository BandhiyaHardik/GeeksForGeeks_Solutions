class Solution{
public:
    int isPossible(int n, int m, string s){
        int t_l = 0, t_r = 0, t_u = 0, t_d = 0; // max consecutive l,r,ud
    int f_lr = 0, f_ud = 0;
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'L')
            f_lr++;
        else if (s[i] == 'R')
            f_lr--;
        else if (s[i] == 'U')
            f_ud++;
        else
            f_ud--;
        
        if (f_lr >= 0)
            t_l = max(t_l, f_lr);
        else
            t_r = min(t_r, f_lr);
        
        if (f_ud >= 0)
            t_u = max(t_u, f_ud);
        else
            t_d = min(t_d, f_ud);
    }
    
    if (t_l - t_r < m && t_u - t_d < n)
        return 1;
    
    return 0;
    }
};