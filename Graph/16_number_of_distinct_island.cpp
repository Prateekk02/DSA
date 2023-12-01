// Link https://www.youtube.com/redirect?event=video_description&redir_token=QUFFLUhqbXJxSHpBTzJlSTVLdzFjNEctVWJKM013UUlRZ3xBQ3Jtc0ttMWk5bnltUlM0Ulo3SmE4SUdGcjRjSDdFa1NxUS1lVlp4bDNVNGhlVUZXdWgxeDI3WFlXdTZ6VHFZa3UtUlBHSTVUc2NCRnNiRV82ZmxRVVNWWE1OeUNlTzdjUkVFLWpnUzg3NmFVUjNicDNMcVhqaw&q=https%3A%2F%2Fbit.ly%2F3AsA08W&v=7zmgQSJghpo




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
  void dfs(int r,int c, int ir, int ic, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int,int>> &ans)
  {
      vis[r][c] = 1;
      int n = grid.size(), m=grid[0].size();
      int delr[] = {-1,0,1,0};
      int delc[] = {0,1,0,-1};
      
      ans.push_back({r-ir,c-ic});
      for(int i=0;i<4;i++)
      {
          int nr = r + delr[i];
          int nc = c + delc[i];
          
          if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc] == 1)
          {
              dfs(nr,nc,ir,ic,vis,grid,ans);
          }
      }
  }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int res = 0;
        set<vector<pair<int,int>>> s;
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis (n, vector<int> (m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int,int>> ans;
                    dfs(i,j,i,j,vis,grid,ans);
                    
                    s.insert(ans);
                }
                
            }
        }
        
        res = s.size();
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends