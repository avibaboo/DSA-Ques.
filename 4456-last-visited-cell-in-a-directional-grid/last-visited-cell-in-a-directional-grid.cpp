class Solution {
public:
    vector<int>visited(char move , int x , int y){
        if(move == 'L'){
            y--;
        }else if(move == 'R'){
            y++;
        }else if(move == 'D'){
            x++;
        }else if(move == 'U'){
            x--;
        }
        return {x , y};
    }
    
    
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n , vector<int>(m , 0));
        int currx = 0 , curry = 0;

        while(true){
            vis[currx][curry] = 1;
            vector<int>curr = visited(grid[currx][curry] , currx , curry);

            int x = curr[0];
            int y = curr[1];

            if(x < 0 || y < 0 || x >= n || y >= m || vis[x][y]){
                break;
            }

            currx = x;
            curry = y;
        }

        return {currx , curry};
    }
};