#include <iostream>
using namespace std;
typedef long long ll;

ll n;
const int maxi = 41000;
int A[maxi+1];//제곱수

//SFI 개수
ll SFI(ll x) {
    ll cnt = 0;
    for (int i = 1; i * i <= x; i++) cnt += (A[i] * x) / (i * i);
    return cnt;
}
//뫼비우스
void Mobius() {
    A[1] = 1;
    for (int i = 1; i <= maxi; i++) {
        for (int j = 2 * i; j <= maxi; j += i) A[j] -= A[i];
    }
}
//이분탐색
ll BinarySearch() {
    ll left = 0; ll right = n * 2;
    while (left < right - 1) {
        ll mid = (left + right) / 2;
        if (SFI(mid) < n)left = mid;
        else right = mid;
    }
    return right;
}
int main() {
    //빠른 입력
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;//입력
    Mobius();//뫼비우스 반환값
    cout<<BinarySearch();//이분탐색
    return 0;
}
