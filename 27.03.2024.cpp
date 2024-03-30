// For the given code earlier there are some certain cases which will fail because we are moving just left but there may be some case where we need to move right as well for example:
// 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 0 1 1 1 1 1 1 1 1 1 1 1 1
// 1 1 1 0 1 1 1 0 0 0 0 0 0 1 1 1
// 1 1 1 0 1 1 1 1 1 1 1 1 0 1 1 1
// 1 1 1 0 1 1 1 1 1 1 1 1 0 1 1 1
// 1 1 1 0 1 1 1 1 1 1 1 1 0 1 1 1
// 1 1 1 0 0 0 0 0 0 1 1 1 0 1 1 1
// 1 1 1 1 1 1 1 1 0 1 1 1 0 1 1 1
// 1 1 1 1 1 1 1 1 0 1 1 1 0 1 1 1
// 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
// 1 1 1 0 1 1 1 1 1 1 1 1 0 1 1 1


// Here is my solution whic cover all the cases.............

//User function Template for C++


class Solution
{
public:
    int solve(int row, int col, vector<vector<int>> &v, vector<vector<int>> &mat)
    {
        if(col == mat[0].size() -1) return 1;
        if(v[row][col] >= 0) return v[row][col];
        else if(v[row][col] == -1)
        {
            v[row][col] = -2;
            
            int cl = col > 0 ? col-1 : 0;
            int cr = col < mat[0].size() -1 ? col+1 : col;
            int ru = row > 0 ? row-1 : 0;
            int rd = row < mat.size() -1 ? row+1 : row;
            if(mat[row][cl] == 0 || mat[row][cr] == 0 || mat[ru][col] == 0 || mat[rd][col] == 0) return v[row][col] = INT_MAX/2;
            
            cl = INT_MAX, cr = INT_MAX, ru = INT_MAX, rd = INT_MAX;
            
            if(col +1 < mat[0].size())  cr = solve(row, col+1, v, mat);
            if(col -1 >= 0)  cl = solve(row, col-1, v, mat);
            if(row +1 < mat.size())  rd = solve(row+1, col, v, mat);
            if(row -1 >= 0)  ru = solve(row-1, col, v, mat);
            
            int tmp = min(cr, min(cl, min(ru, rd))) +1;
            if(tmp > INT_MAX/2)
            {
                v[row][col] = -1;
                return tmp;
            }
            return v[row][col] = tmp;
        }
        else return INT_MAX/2;
    }
    int findShortestPath(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        int ans = INT_MAX;
        vector<vector<int>> v(r, vector<int>(c,-1));
        for(int i = 0; i < r; i++)
        {
            ans = min(ans, solve(i, 0, v, mat));
        }
        if(ans >= INT_MAX/2) return -1;
        return ans;
    }
};
