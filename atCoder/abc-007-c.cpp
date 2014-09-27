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
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int R,C,sy,sx,gy,gx,wx,wy;
vs c(50);
int d[51][51];
int res;
 
int bfs() {
	queue<pi> que;
	que.push(pi(sx, sy));
	d[sx][sy] = 0;
 
	while(que.size()) {
		pi p = que.front();
		que.pop();
 
		if(p.first == gx && p.second == gy) break;
		rep(i,0,4) {
			wx = p.first + dx[i];
			wy = p.second + dy[i];
 
			if(c[wx][wy] != '#' && d[wx][wy] == INF) {
				d[wx][wy] = d[p.first][p.second] + 1;
				que.push(pi(wx, wy));		
			}
		}
	}
	return d[gx][gy];
}
 
int main() {
	cin >> R >> C;
	cin >> sx >> sy;
	cin >> gx >> gy;
	
	sx -= 1; sy -=1;
	gx -= 1; gy -=1;
	rep(i,0,R) {
		cin >> c[i];
	}
 
	rep(i,0,R) {
		rep(l,0,C) {
			d[i][l] = INF;
		}
	}
	
	res = bfs();
 
	cout << res << endl;
	return 0;
}
