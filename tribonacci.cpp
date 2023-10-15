#include<bits/stdc++.h>

using namespace std;
const int N=1e3;
int visited[N];


int tribonacci(int n){
    if(n<=3)return 1;
     
     if(visited[n]!=-1){
        return visited[n];
     }

     int ans=tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
     visited[n]=ans;
     return ans;

     

}
int main()
{
memset(visited,-1,sizeof(visited));

int n;
cin>>n;

cout<<tribonacci(n)<<" ";


    return 0;
}