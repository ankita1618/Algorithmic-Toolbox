#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll W,n;
    cin>>W>>n;
    ll s[n];
    for(ll i=0;i<n;i++)
        cin>>s[i];
    vector < vector<ll> > w(n+1, vector < ll> (W+1));
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=W;j++)
        {
            if(i==0||j==0)
                w[i][j]=0;
            else if(s[i-1]<=j)
                w[i][j] = max(w[i-1][j]
                              ,s[i-1]+w[i-1][j-s[i-1]]);
            else
                 w[i][j]=w[i-1][j];

        }

        cout<<w[n][W]<<endl;
}
