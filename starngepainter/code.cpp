#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <unordered_set>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPrintable(vector<vector<int>> &grid)
    {
        // Step 1: Finding Distant Colors in the Grid || ex: 1, 1, 1, 1 -> 1
        unordered_set<int> st; // Set to store distinct colors in the grid
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                st.insert(grid[i][j]); // Insert all colors in the grid into the set 'st' || ex: 1, 2, 2, 1 -> 1, 2
            }
        }

        // Step 2: Finding Coordinates of Colors
        map<int, vector<int>> row, col; // Maps to store the starting and ending row and column coordinates for each color

        for (auto it : st)
        {
            int mn1 = n, mn2 = m, mx1 = 0, mx2 = 0; // Variables to store the starting and ending row and column coordinates for each color

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    if (grid[i][j] == it) // If the color at (i, j) is equal to 'it', update the coordinates || ex: 1, 1, 1, 1 -> 1, 4, 1, 4
                    {
                        mn1 = min(i, mn1); // Update the coordinates || ex: 1, 1, 1, 1 -> 1, 4, 1, 4
                        mx1 = max(i, mx1);
                        mn2 = min(j, mn2);
                        mx2 = max(j, mx2);
                    }
                }
            }
            row[it].push_back(mn1); // Add the coordinates to the maps
            row[it].push_back(mx1);
            col[it].push_back(mn2);
            col[it].push_back(mx2);
        }

        // Step 3: Building the Dependency Graph
        vector<vector<int>> graph(61, vector<int>()); // 2D vector representing the dependency graph between colors
        int indeg[61];                                // Array to store the in-degree of each color
        memset(indeg, 0, sizeof indeg);

        for (auto it : st)
        {
            int mnr = row[it][0], mxr = row[it][1], mnc = col[it][0], mxc = col[it][1]; // Variables to store the starting and ending row and column coordinates for color 'it' || ex: 1, 1, 1, 1 -> 1, 4, 1, 4
            set<int> st2;                                                               // Set to store colors that are inside the rectangle of color 'it'

            for (int i = mnr; i <= mxr; i++)
            {
                for (int j = mnc; j <= mxc; j++)
                {
                    if (it != grid[i][j])
                        st2.insert(grid[i][j]); // Insert all colors inside the rectangle of color 'it' into the set 'st2'
                }
            }
            indeg[it] += st2.size(); // Increment the in-degree of color 'it' based on the number of colors inside its rectangle
            for (auto pt : st2)
                graph[pt].push_back(it); // Add edges from colors inside the rectangle to color 'it'
        }

        // Step 4: Standard Topological Sort
        int cnt = 0;  // Variable to count the number of colors processed during topological sort
        queue<int> q; // Queue for the BFS-based topological sort

        for (int i = 1; i <= 60; i++)
        {
            if (st.find(i) != st.end() && indeg[i] == 0)
                q.push(i); // Add colors with in-degree 0 to the queue to start the topological sort
        }

        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            cnt++;

            for (auto it : graph[x])
            {
                indeg[it]--;
                if (indeg[it] == 0)
                    q.push(it); // If the in-degree of a color becomes 0, add it to the queue for processing
            }
        }

        // Step 5: Checking the Result
        // If the 'cnt' variable is equal to the number of distinct colors in the 'targetGrid',
        // it means all colors were successfully processed in the topological sort, and we can return true.
        // Otherwise, we return false.
        return cnt == st.size();
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 2, 2, 1},
                                {1, 2, 2, 1},
                                {1, 1, 1, 1}};
    cout << s.isPrintable(grid) << endl;
    return 0;
}