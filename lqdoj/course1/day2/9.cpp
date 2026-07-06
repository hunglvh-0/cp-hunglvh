#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
inline void sol(){
    float a,b;cin>>a>>b;
    float bmi=a/(b*b);
    if(bmi<18.5){
        cout<<"Thieu can";
    }
    else if(bmi>=18.5 and bmi<=22.9){
        cout<<"Binh thuong";
    }
    else{
        cout<<"Thua can";
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