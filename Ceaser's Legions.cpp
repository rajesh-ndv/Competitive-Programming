#include <bits/stdc++.h>
using namespace std;
int global_k1,global_k2;
int dp[101][101][11][11];
int solve(int f,int h,int k1,int k2){
    if((f+h)==0) return 1;
    if(dp[f][h][k1][k2]!=-1) return dp[f][h][k1][k2];
    int x=0,y=0;
    if(f>0 && k1>0)
    x=solve(f-1,h,k1-1,global_k2);
    if(h>0 && k2>0)
    y=solve(f,h-1,global_k1,k2-1);
    return dp[f][h][k1][k2]=x+y;
}
int main() {
    int f,h;
    cin>>f>>h>>global_k1>>global_k2;
    for(int i=0;i<=f;i++){
        for(int j=0;j<=h;j++){
            for(int k=0;k<=global_k1;k++){
                for(int l=0;l<=global_k2;l++){
                    dp[i][j][k][l]=-1;
                }
            }
        }
    }
    cout<<solve(f,h,global_k1,global_k2)<<endl;
}
