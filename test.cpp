#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll=long long;
using ld=long double;
using pll=pair<ll, ll>;
//using mint = modint1000000007;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo 2e18
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
//priority_queue<ll, vector<ll>, greater<ll>> Q;
// LMAX = 18446744073709551615 (1.8*10^19)
// IMAX = 2147483647 (2.1*10^9)
/*

*/
ll ans = 0;
ll S[10];
void dfs(ll depth)
{
  if (depth==10){
    ll child = 0;
    rep(j, 6){
      child = child*10+S[j];
    }
    ll mot = 0;
    rep(j, 4){
      mot = mot*10 + S[j+6];
    }
//    cout << child << " " << mot << endl;
    if (child%mot) return ;
    if (child/mot == 555) ans++;
    return ;
  }
  rep(i, 10){
    if (depth==0 && i < 5) continue;
    if (depth==6 && i != 1) continue;
    S[depth] = i;
    dfs(depth+1);
  }
}
  
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  dfs(0);
  cout << ans << endl;
}
