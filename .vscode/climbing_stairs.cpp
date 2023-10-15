#include<bits/stdc++.h>

using namespace std;

int climbing_ways(int n){
     int count=0;
     if(n<=1) return 1;

     return climbing_ways(n-1)+climbing_ways(n-2);
}
int main()
{
int n;
cin>>n;

cout<<climbing_ways(n);



    return 0;
}