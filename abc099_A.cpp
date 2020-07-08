#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;

    if(N < 1000) {
        cout << "ABC" << endl;
    } else if(1000 <= N && N < 1999) {
        cout << "ABD" << endl;
    }
}