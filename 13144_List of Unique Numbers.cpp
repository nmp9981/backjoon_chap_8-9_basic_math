#include <iostream>
using namespace std;
typedef long long ll;

ll n;
const int maxi = 100001;
int A[maxi];//수열
int numCount[maxi];//각 수가 몇개 잇는가?

//입력
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
}
//수 뽑기
void NumberSelect() {
    ll left = 0;
    ll right = 1;
    ll caseNum = n * (n + 1) / 2;//경우의 수
    numCount[A[left]] = 1;

    while (right < n) {
        if (numCount[A[right]] == 1) {//중복 O
            numCount[A[left]]--;
            left++;
            caseNum -= (n-right);
        }
        else {//중복 X
            numCount[A[right]]++;
            right++;
        }
    }
    cout << caseNum;//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    NumberSelect();//수 뽑기
    return 0;
}
