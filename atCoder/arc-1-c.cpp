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

int check(vs boad, int x, int i) {
	rep(n,8) if(((boad[n][i] == 'Q' ||  boad[n][i+(n-x)] == 'Q' || boad[n][i-(n-x)] == 'Q') && n!=x) || (boad[x][n] == 'Q' && n!=i)) return 1;

	return 0;
}

int dfs(vs boad, int x) {
	if(x == 8) {
		rep(i,8) print(boad[i]);
		exit(0);
	}

	rep(i,8) {
		if(boad[x][i] == 'Q') {
			if(check(boad, x, i)) {
				print("No Answer");
				exit(0);
			}
			return dfs(boad, x+1);
		}
	}
	
	rep(i,8) {
		if(!check(boad, x, i)) {
			boad[x][i] = 'Q';
			dfs(boad, x+1);
			boad[x][i] = '.';
		}
	}
	return 0;
}


int main() {
	vs boad(10);
	rep(i,8) cin >> boad[i];

	dfs(boad, 0);
	print("No Answer");
	return 0;
}

