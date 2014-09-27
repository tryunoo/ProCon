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
typedef vector< vector<int> > vi2;


int main() {
	int N,cnt,res=INF;
	string cmd;
	string scut = "ABXY";
	cin >> N >> cmd;

	for(auto w:scut) {
		for(auto x:scut) {
			for(auto y:scut) {
				for(auto z:scut) {
					cnt=0;
					rep(i,cmd.length()) {
						if((cmd[i] == w && cmd[i+1] == x) || (cmd[i] == y && cmd[i+1] == z)) {
							i++;
						}
						cnt++;
					}
					res = min(res,cnt);
				}
			}
		}
	}

	print(res);

	return 0;
}
