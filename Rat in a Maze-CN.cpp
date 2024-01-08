/*
    Time Complexity: O(3^(N^2))
    Space Complexity: O(N*N)

    Where 'N*N' is the total number of cells in the maze.
*/
void solve(int i, int j, string path, vector<vector<int>> &matrix, int row, int column, vector<string>& ans)
{
    // Checking out of bounds conditions.
    if (i < 0 or i >= row or j < 0 or j >= column)
    {
        return;
    }
    // Avoid recursive calls on blocked or visited numbers.
    if (matrix[i][j] == 0)
    {
        return;
    }

    // If reached the destination, add the path to the answer vector.
    if (i == row - 1 and j == column - 1)
    {
        ans.push_back(path);
        return; 
    }

    // Mark the current cell as visited (0).
    matrix[i][j] = 0;

    // Recursive calls for exploring the next possible moves.
    // Up
    solve(i - 1, j, path + 'U', matrix, row, column, ans);
    // Down
    solve(i + 1, j, path + 'D', matrix, row, column, ans);
    // Left
    solve(i, j - 1, path + 'L', matrix, row, column, ans);
    // Right
    solve(i, j + 1, path + 'R', matrix, row, column, ans);

    // Restore the current cell to its original state (1).
    matrix[i][j] = 1;
    return;
}

vector<string> ratMaze(vector<vector<int>> &mat)
{
    string path = "";
    int n = mat.size();
    vector<string> ans;
    solve(0, 0, path, mat, n, n, ans);
    return ans;
}
