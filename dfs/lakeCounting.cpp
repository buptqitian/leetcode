#include <iostream>
using namespace std;


const int width = 6;
const int height = 4;
char field[height][width] = {'0','1','0','1','1','0',
                             '0','0','0','1','1','1',
                             '0','0','0','0','1','0',
                             '1','1','1','0','0','0'};
const int tx[4] = {-1, 1, 0, 0};
const int ty[4] = {0, 0, -1, 1};
void find(int x, int y){
    field[x][y] = '0';
    for(int i = 0; i < 4; i++){
        int nx = x + tx[i];
        int ny = y + ty[i];
        if(0<=nx && nx <height && 0<=ny && ny <width && field[nx][ny]=='1'){
            find(nx, ny);
        }
    }
    return;
}



int main()
{
    int res = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0;j < width; j++){
            if(field[i][j] == '1'){
                find(i, j);
                res++;
            }
        }
    }
    cout << res << endl;
}
