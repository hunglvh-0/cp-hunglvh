#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
inline void sol(){
    int n;cin>>n;
    if(n%400 == 0 or n%4==0 and n%100!=0){
        cout<<"Nam nhuan"<<el;
    }else{
        cout<<"Khong la nam nhuan";
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
    sol();
}