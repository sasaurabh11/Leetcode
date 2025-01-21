class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        const int n = grid[0].size();

        long long U=reduce(grid[0].begin()+1, grid[0].end(), 0LL);
        long long D=0LL;
        long long Robot2=U; 

        for (int i=1; i < n; i++) {
            U-= grid[0][i]; 
            D+= grid[1][i-1]; 
            
            long long P=max(U, D);
            Robot2 = min(Robot2, P);
        }

        return Robot2;
    }
};