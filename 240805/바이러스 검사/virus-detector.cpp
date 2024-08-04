#include <iostream> 
#define loop(i, s, n) for(int i = s; i <= n; i++)
#define MAXN 1000001
#define endl '\n'

using namespace std;

long long n, customer, mento, mentee, arr[MAXN], ans;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    loop(i, 1, n){
        cin >> arr[i];
    }

    cin >> mento >> mentee;

    loop(i, 1, n){
        int t = arr[i] / mento;
        arr[i] -= t * mento;
        if(!(arr[i] % mentee)) ans += t + arr[i] / mentee;
        else ans += t + arr[i] / mentee + 1;
    }

    cout << ans << endl;

}