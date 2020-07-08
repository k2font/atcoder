#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N; cin >> N;

    long long i = 0;
    while(true) {
        if(i != 0 && i % 2 == 0 && i % N == 0) {
            cout << i << endl;
            break;
        }
        i += N;
    }
}