/*
GIven a 2D array of either '\' or '/', find out how many pieces this
rectangle is divided into graphically.
For a 2*2 matrix with
/\
\/
The matrix split into 5 pieces
*/

/*
similar to finding the number of connected components in graph. 
DFS solution:
In this graph every node has at most 2 edges. Every position (x, y) 
has 2 nodes. If it's a '/' in (x, y) and current node is upper half 
of (x,y), the next two nodes to search is right half of (x - 1, y) 
and lower half of (x, y - 1).
Other than DFS, union find and BFS will work as well.
*/

public int segmentCount(char[][] m) {
        int len = m[0].length;
        boolean[] upperHalf = new boolean[m.length * len];
        boolean[] lowerHalf = new boolean[m.length * len];

        int count = 0;
        for(int i = 0; i < m.length; i++) {
            for(int j = 0; j < len; j++) {
                if(!upperHalf[i*len + j]) {
                    count++;
                    dfs(m, upperHalf, lowerHalf, i, j, 0);
                }
                if(!lowerHalf[i*len + j]) {
                    count++;
                    dfs(m, upperHalf, lowerHalf, i, j, 1);
                }
            }
        }
        return count;
    }
    //upper:0, lower:1, left:2, right:3
    private void dfs(char[][] m, boolean[] upperHalf, boolean[] lowerHalf, int x, int y, int position) {
        if(x < 0 || x == m.length || y == m[0].length || y < 0) {
            return;
        }
        if((position == 2 && m[x][y] == '\\') || (position == 3 && m[x][y] == '/')) position = 1;
        if((position == 2 && m[x][y] == '/') || position == 3 && m[x][y] == '\\') position = 0;
        int id = x * m[0].length + y;
        if((position == 0 && upperHalf[id]) || (position == 1 && lowerHalf[id])) { //if visited
            return;
        }
        if(position == 0) upperHalf[id] = true;
        else lowerHalf[id] = true;
        if(position == 0 && m[x][y] == '\\') {
            dfs(m, upperHalf, lowerHalf, x, y + 1, 2); //go right
            dfs(m, upperHalf, lowerHalf, x - 1, y, 1); //go up
        }
        if(position == 0 && m[x][y] == '/') {
            dfs(m, upperHalf, lowerHalf, x, y - 1, 3); //go left
            dfs(m, upperHalf, lowerHalf, x - 1, y, 1); //go up
        }
        if(position == 1 && m[x][y] == '\\') {
            dfs(m, upperHalf, lowerHalf, x, y - 1, 3); //go left
            dfs(m, upperHalf, lowerHalf, x + 1, y, 0); //go down
        }
        if(position == 1 && m[x][y] == '/') {
            dfs(m, upperHalf, lowerHalf, x, y + 1, 2); //go right
            dfs(m, upperHalf, lowerHalf, x + 1, y, 0); //go down
        }
    }
