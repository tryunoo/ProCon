#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define rep(i,l) for(int(i)=0; (i)<int(l); i++)
#define erep(i,l,j,x) for(int(i)=int(l); (i)<int(j); i+=x)
#define mp(x,y) make_pair(x, y)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb(x) push_back(x)
#define pob(x) pop_back(x)
#define pf(x) push_front(x)
#define pof(x) pop_front(x)
#define srtg(x) sort(all(x), greater<int>())
#define print(x) cout<<x<<endl;
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef vector<string> vs; typedef vector<double> vd;
typedef pair<int, int> pi;
typedef priority_queue<int> pqi; typedef priority_queue<int, vector<int>, greater<int> > pqig;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }
 
 
int main() {
    int T,D,t_A,t_B,d_A,d_B;
     
    double res=INF;
 
    cin >> T >> D;
    cin >> t_A >> t_B;
    cin >> d_A >> d_B;
 
    erep(i, 0, D+1, d_A) {
        erep(n, 0, D-i+1, d_B) {
            if(i+n > 0) amin(res, abs(double(T) - double(t_A * i + t_B * n) / double(i + n)));
        }
    }
 
    print(setprecision(20) << res);
    return 0;
}
