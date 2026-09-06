class Solution {
private:
    int solve(string& s,string& t,int i,int j,vector<vector<int>>& visit){
        int m = t.length();
        int n = s.length(); 
        if(j == m){
            return 1;
        }
        if(i == n){
            return 0;
        }
        if(visit[i][j] != -1){
            return visit[i][j];
        }
        int res = solve(s,t,i + 1,j,visit);
        if(t[j] == s[i]){
            res += solve(s,t,i + 1,j + 1,visit);
        }
        visit[i][j] = res;
        return visit[i][j];
    }
public:
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length(); 
        vector<vector<int>> visit(n,vector<int>(m,-1));
        return solve(s,t,0,0,visit);
    }
};