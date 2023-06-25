#include <iostream>
using namespace std;

int n,m;
const int maxi = 31;
int dp[maxi][maxi];

//이항계수
void Pascal() {
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < maxi; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }
}
//입력
void input() {
    cin >> n>>m;
}
int main() {
    Pascal();//파스칼의 삼각형
    input();//입력
    cout << dp[n - 1][m - 1];
    return 0;
}
