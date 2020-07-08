#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N >> S;

    for(int i = 0; i < S.size(); ++i) {
        if(S[i] + N > 'Z') {
            int tmp = 'Z' - S[i];
            S[i] = 'A' + N - tmp - 1;
        } else {
            S[i] = S[i] + N;    
        }
    }

    cout << S << endl;
}
