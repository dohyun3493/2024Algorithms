#include<iostream>
#include<string>
using namespace std;

int cnt = 0;
int check = false;
int pp[1001];

void preprocessing(string& P){
    int j = 1;
    int k = 0;
    int m = P.size() - 1;
    pp[1] = 0;
    while(j <= m){
        if(k == 0 || P[j] == P[k]){
            j++;
            k++;
            pp[j] = k;
        }
        else k = pp[k];
    }
}

void KMP(string &A, string &P){
    preprocessing(P);
    int i = 1;
    int j = 1;
    int n = A.size() - 1;
    int m = P.size() - 1;

    while(i <= n){
        cnt++;
        if(j == 0 || A[i] == P[j]){
            i++;
            j++;
        }else j = pp[j];
        if(j == m + 1){
            check = true;
            cout << cnt << endl;
            j = pp[j];
        }
    }

    if(check == false) cout << "fail" << endl;
}

int main(){
    string A = " ";
    string P = " ";
    string word1, word2;
    cin >> word1 >> word2;

    A += word1;
    P += word2;

    KMP(A, P);

    return 0;
}