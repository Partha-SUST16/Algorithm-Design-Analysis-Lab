#include<bits/stdc++.h>
using namespace std;

#define N 4

bool isSafe(int board[N][N],int row,int col)
{
    for(int i=0;i<col;i++)
        if(board[row][i])
            return false;
    for(int i=row,j=col;j>=0 and i>=0;i--,j--)
        if(board[i][j])
            return false;
    for(int i=row,j=col;j>=0 and i<N;i++,j--)
        if(board[i][j])
            return false;
    return true;
}
bool solveNQ(int board[N][N],int now)
{
    if(now>=N)return true;

    for(int i=0;i<N;i++)
    {
        if(isSafe(board,i,now))
        {
            board[i][now] = 1;
            if(solveNQ(board,now+1))
                return true;
            board[i][now] = 0;
        }
    }
    return false;
}
void show(int board[N][N])
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            cout<<board[i][j]<<" ";
        puts("");
    }
}
int main()
{
    int board[N][N]={0};

    if(solveNQ(board,0)!=false)
    {
        show(board);
    }
    else
        puts("No solution");
}
