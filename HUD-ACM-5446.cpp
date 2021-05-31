#include<cstdio>//hdu 0ms
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
char mapp [10][10];
int idx [10][10];
bool bfs(int x,int y);
struct Node{
    int x, y;
};
int dir [4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int main()
{
    int t , flag;
    scanf("%d",&t);
    for(int Case = 1; Case <= t; Case ++){
        flag = 0;
        for(int i = 0; i < 9; i ++) scanf("%s",mapp[i]);
        for(int i = 0; i < 9; i ++){
            for(int j = 0; j < 9; j ++){
                if(mapp [i][j] == 'o' && bfs(i , j)){
                    flag = 1; break;
                }
            }
            if (flag) break;
        }
        if (flag) printf("Case #%d: Can kill in one move!!!\n",Case);
        else printf("Case #%d: Can not kill in one move!!!\n",Case);
    }
}
bool bfs(int x,int y)
{
    queue < Node > q;
    memset(idx , 0, sizeof(idx));
    int cnt = 0;
    Node a, temp;
    a.x = x, a.y = y;
    idx [x][y] = 1;
    q.push(a);
    while(!q.empty())
    {
        a = temp = q.front() , q.pop();
        for(int i = 0; i < 4; i ++){
            int xx = a.x + dir [i][0];
            int yy = a.y + dir [i][1];
            if(xx >= 0 && xx < 9 && yy >= 0 && yy < 9 && !idx[xx][yy] &&mapp[xx][yy] != 'x'){
                idx [xx][yy] = 1;
                if (mapp [xx][yy] == '.'){
                    cnt++;
                    if (cnt >= 2) return false;
                    continue;
                }
                a.x = xx,a.y = yy;
                q.push(a);
            }
            a = temp;
        }
    }
    return true;
}
