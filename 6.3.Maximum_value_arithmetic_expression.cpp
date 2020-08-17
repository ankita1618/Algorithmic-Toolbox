#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll cal(ll x, ll y, char op)
{
    switch(op)
        {
            case '*': return x*y;
            case '+': return x+y;
            case '-': return x-y;
            default: return 0;
        }
}

ll maxValue(string s)
{
    ll n=(s.size()+1)/2,mm,mM,Mm,MM; //operands;
    vector < vector < ll > > MinA(n , vector <ll>(n ,0)),
                        MaxA(n,vector <ll>(n,0));
    int k=0;
    for(ll i=0;i<n;i++)
    {
        MinA[i][i] = (ll)s[k]-48;
        MaxA[i][i] = (ll)s[k]-48;
        k=k+2;

    }
    for(ll k=0;k<n-1;k++)
        for(ll i=0;i<n-k-1;i++)
    {
        ll j=k+i+1;

        ll minValue = LLONG_MAX;
        ll maxValue = LLONG_MIN;

        for(ll t=i;t<j;t++)
        {
            mm=cal(MinA[i][t],MinA[t+1][j],s[2*t+1]);
            mM=cal(MinA[i][t],MaxA[t+1][j],s[2*t+1]);
            Mm=cal(MaxA[i][t],MinA[t+1][j],s[2*t+1]);
            MM=cal(MaxA[i][t],MaxA[t+1][j],s[2*t+1]);

            minValue = min(minValue,min(mm,min(Mm,min(MM,mM))));
            maxValue = max(maxValue,max(mm,max(Mm,max(MM,mM))));
        }
        MinA[i][j]= minValue;
        MaxA[i][j]= maxValue;
    }
    return MaxA[0][n-1];
}

int main()
{
   string s;
   cin>>s;
   cout<<maxValue(s);
}

//Time complexity - O(n^3)
