#include <iostream>
using namespace std;
typedef long long ll;

ll n,m;
const int maxi = 1000001;
const int modMaxi = 1001;
ll A[maxi];//수열
ll csum[maxi];//부분합
ll restCount[modMaxi];//i로 나눈 나머지 개수

//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < n; i++) cin >> A[i];
}
//부분합
void SubSum() {
    csum[0] = A[0];
    restCount[csum[0]%m] = 1;
    for (int i = 1; i < n; i++) {
        csum[i] = csum[i - 1] + A[i];//누적합
        int rest = (int) (csum[i] % m);//나머지
        restCount[rest]+=1;//나머지 rest의 개수
    }
}
//구간 개수 구하기
void CountSection() {
    ll total = restCount[0];//나누어 떨어지는 경우
    for (int i = 0; i < modMaxi; i++) {
        ll cnt = restCount[i];
        total += (cnt * (cnt - 1) / 2);
    }
    cout << total;//출력
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    input();//입력
    SubSum();//부분합
    CountSection();//구간 개수 구하기
    return 0;
}
