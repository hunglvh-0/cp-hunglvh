#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
int gcd(int a,int b)
{
    return gcd(b,a/b);
}
void sol(){
    int a,b;
    cin >> a>>b;
    cout<<gcd(a,b);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
    sol();
}