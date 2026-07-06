#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define el "\n"
#define task ""
inline void sol(){
    float a,b,c;cin>>a>>b>>c;
    float tbm=((a*2)+(b*2)+c)/5;
    if(tbm>=8){
        cout<<"gioi";
    }
    else if(tbm>=6.5){
        cout<<"kha banh";
    }
    else if(tbm>=5){
        cout<<"trung binh";
    }
    else cout<<"yeu";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(task".INP","r")){
        freopen(task".INP","r",stdin);
        freopen(task".OUT","w",stdout);
    }
    sol();
}