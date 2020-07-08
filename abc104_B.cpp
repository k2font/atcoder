#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    bool flag = false;

    if(S.at(0) == 'A' && islower(S.at(1)) && islower(S.at(S.size() - 1)) && S.at(S.size() - 1) != 'C') {
        int count = 0;
        for(int i = 2; i < S.size() - 1; ++i) {
            if(S.at(i) == 'C') {
                count++;
            }
        }

        if(count > 1 || count == 0) {
            flag = true;
        }
    } else {
        flag = true;
    }

    if(flag == true) {
        cout << "WA" << endl;
    } else {
        cout << "AC" << endl;
    }
}