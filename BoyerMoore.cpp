#include<iostream>
#include<string>
using namespace std;

int cnt1, cnt2 = 0;
int jump[27] = {0, };

void computJump(string &A){
    int n = A.size() - 1;
    for(int i = 1; i <= 26; i++){
        jump[i] = A.size() - 1;
    }
    for(int i = 1; i <= n; i++){
        if(i == n) jump[A[i] - 96] = A.size() - 1;
        else jump[A[i] - 96] = (A.size() - 1) - i;
    }
}

void BoyerMooreHorspool(string &A, string &P){
    int i = 1;
    int n = A.size() - 1;
    int m = P.size() - 1;

    computJump(P);

    while(i <= n - m + 1){
        int j = m;
        int k = i + m - 1;
        while(j > 0 && P[j] == A[k]){
            cnt1++;
            j--;
            k--;
        }
        if(j == 0) cnt2++;
        i = i + jump[A[i + m - 1] - 96];
    }
}

int main(){
    string A = " ";
    string P = " ";
    string word1, word2;
    cin >> word1 >> word2;

    A += word1;
    P += word2;

    BoyerMooreHorspool(A, P);

    cout << cnt1 << " " << cnt2 << endl;

    return 0;
}

