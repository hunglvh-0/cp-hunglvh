
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int n = 8;
    int states = 0;
    for(int a=0; a<=n/2; a++) {
        for(int b=0; b<=n; b++) {
            if (n - 2*a - b >= 0) states++;
        }
    }
    cout << states << endl;
}

