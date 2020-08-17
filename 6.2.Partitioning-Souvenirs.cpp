#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,sum=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
       {
           cin>>arr[i];
           sum=sum+arr[i];
       }
    bool dp[n+1][2*(sum/3)+1];
    if(sum%3!=0)
        {cout<<0<<endl;
         return 0 ;}
    else
    {
        sum=sum-sum/3;
         dp[n+1][sum+1];
             dp[0][0]=1;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=sum;j++)
            {
            if(i==0&&j==0)
                    dp[i][j]=1;
                else if(j==0&&i!=0)
                    dp[i][j]=1;
                else if(i==0&&j!=0)
                    dp[i][j]=0;

              else{

                        dp[i][j]=dp[i-1][j];
                    if(j>=arr[i-1])
                        dp[i][j] = dp[i-1][j-arr[i-1]]||dp[i][j];
                }

            }
    }
    cout<<dp[n][sum]<<endl;
}


