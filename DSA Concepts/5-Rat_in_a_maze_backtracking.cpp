#include <iostream>
#include <vector>
using namespace std;

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &ans)
{
    // Base Case
    int n = mat.size(); // total size of matrix
    if (r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1)
        return;
    // Result Base Case
    if (r == n - 1 && c == n - 1)
    {
        ans.push_back(path);
        return;
    }
    // mark current cell as visited to avoid cycles
    mat[r][c] = -1; // visit

    // helper(mat, r + 1, c, path + "D", ans); // down
    // helper(mat, r - 1, c, path + "U", ans); // up
    // helper(mat, r, c + 1, path + "R", ans); // right
    // helper(mat, r, c - 1, path + "L", ans); // left

    // better logic
    path.push_back('D');
    helper(mat, r + 1, c, path, ans);
    path.pop_back();

    path.push_back('L');
    helper(mat, r, c - 1, path, ans);
    path.pop_back();

    path.push_back('R');
    helper(mat, r, c + 1, path, ans);
    path.pop_back();

    path.push_back('U');
    helper(mat, r - 1, c, path, ans);
    path.pop_back();

    // unmark for other paths
    mat[r][c] = 1; // unvisit
}

vector<string> findPath(vector<vector<int>> &mat)
{
    vector<string> ans;
    // Edge Case
    if (mat.empty() || mat[0][0] == 0)
        return ans;
    string path = "";
    helper(mat, 0, 0, path, ans);

    return ans;
}

int main()
{
    // Time Complexity = O(3^{n^2})
    // Space Complexity = O(n^2)
    vector<vector<int>> mat = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = findPath(mat);
    cout << "The avaliable paths are : \n";
    for (string path : ans)
        cout << path << endl;

    return 0;
}