#include <bits/stdc++.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define FORN(i, a, n) for (int i = a; i < n; i++)
#define FRON(i, a, n) for (int i = a; i > n; i--)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define FRO(i, a) for (int i = a; i > -1; i--)
#define mp make_pair
#define pb push_back
#define INF 1000000010
#define MOD 1000000007 // 998244353
#define PI 3.141592653589793238462643383279502884197169399375105820974945
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<vi> vii;

//debugging output in cerr
#define n_l '\n'
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]: "; cerr << to_string(__VA_ARGS__) << endl
template <typename T, size_t N> int SIZE(const T (&t)[N]){ return N; } template<typename T> int SIZE(const T &t){ return t.size(); } string to_string(const string s, int x1=0, int x2=1e9){ return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"'; } string to_string(const char* s) { return to_string((string) s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c){ return string({c}); } template<size_t N> string to_string(const bitset<N> &b, int x1=0, int x2=1e9){ string t = ""; for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){ t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A (&v), int x1=0, int x2=1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B> &p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A (&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if(l_v_l_v_l == 0) res += n_l; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2-x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if(e != l){ if(rnk > 1) { res += n_l; t_a_b_s = l_v_l_v_l; }; } else{ t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if(l_v_l_v_l == 0) res += n_l; return res; } void debugm(){;} template<typename Heads, typename... Tails> void debugm(Heads H, Tails... T){ cerr << to_string(H) << " | "; debugm(T...); } 
#define debugm(...) cerr << "[" << #__VA_ARGS__ << "]: "; debugm(__VA_ARGS__); cerr << endl

double round(double num, int dec) {return std::round(num*pow(10,dec))/pow(10,dec);}
vector<string> split(string s, char delim) {replace(s.begin(),s.end(),delim,' ');stringstream ss(s); string buf;vector<string> v;while (ss>>buf) v.push_back(buf);return v;}
template<typename T, int size> int siz(T(&)[size]){return size;}
long long POW(long long base, long long exp) {long long res = 1;while (exp > 0) {if (exp % 2 == 1){res= (res * base) % MOD;}exp = exp >> 1;base = (base * base) % MOD;}return res;}


int dp[5005];
int a[5005];

int main() {
    int n; cin >> n;
    FOR(i, n) {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(a[i]) > abs(a[j])) {
                if ((a[i] < 0 && a[j] > 0) || (a[i] > 0 && a[j] < 0))
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    int ans = 1;
    FOR(i, n)
        ans = max(ans, dp[i]);
    cout << ans;
}
