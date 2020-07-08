#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;

    for(int i = 0; i < S.size(); i = i + 2) {
        if(S[i] != 'h' || S[i + 1] != 'i') {
            cout << "No" << endl;
            break;
        }

        if(i == S.size() - 2) {
            cout << "Yes" << endl;
        }
    }
}