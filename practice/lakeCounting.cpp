#include <iostream>
using namespace std;

const int m = 5;
const int n = 5;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

int A[m][n] = {0, 0, 1, 1, 0,
               0, 1, 1, 0, 0,
               0, 0, 0, 0, 1,
               1, 1, 0, 0, 1,
               1, 1, 1, 0, 1};


void dfs(int x, int y){
    A[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(A[nx][ny] == 1 && nx>=0 && nx < m && ny >=0 && ny < n){
            dfs(nx, ny);
        }
    }
}

int main()
{
    int count = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(A[i][j] == 1){
                dfs(i, j);
                count++;
            }
        }
    }
    cout << count << endl;
}
