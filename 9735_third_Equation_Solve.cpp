#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
typedef long double ld;

ll A, B, C, D;//계수
const ll maxi = 1000000;
ld firstX, secondX, thirdX;//해
set<ld> solution;//해(출력용)

//입력
void input() {
    solution.clear();//초기화
    cin >> A>>B>>C>>D;
}
//첫번째 해
void FirstSolution(ll A,ll B,ll C,ll D) {
    if (D == 0ll) {//상수항이 0
        firstX = 0.0;
        solution.insert(firstX);
        return;
    }
    for (ll i = 1; i <= maxi; i++) {
        if (abs(D) % i != 0ll) continue;//D/A의 약수여야함

        ll posiSol = i*(A * i*i + B * i + C  + D/i);//3차항에서 오버플로우
        ll negaSol = (-i)*(A * i*i - B * i + C - D/i);
        if (posiSol == 0ll) {
            firstX = (ld) i;
            break;
        }
        if (negaSol == 0ll) {
            firstX = (ld) (-i);
            break;
        }
    }
    solution.insert(firstX);
}
//2차 방정식
void SecondEquation() {
    //조립제법으로 2차 방정식 만들기
    ll a = A; ll b = B + a * (ll) firstX;
    ll c = A * (ll)(firstX * firstX) + B * (ll) firstX + C;

    //판별식
    ll Distinc = b * b - 4 * a * c;
    if (Distinc < 0ll) return;//허근

    //해 구하기
    secondX = (ld) ((ld) (-b) + sqrt(Distinc)) / (ld) (2.0 * a);
    thirdX = (ld) ((ld) (-b) - sqrt(Distinc)) / (ld) (2.0 * a);
    solution.insert(secondX);
    solution.insert(thirdX);
}
//출력
void output() {
    //소수점 4자리까지 출력
    cout << setprecision(4);
    cout << fixed;

    for (auto s : solution) cout << s << " ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        input();//입력
        FirstSolution(A,B,C,D);//첫번째 해
        SecondEquation();//2차 방정식
        output();//출력
    }
    return 0;
}
