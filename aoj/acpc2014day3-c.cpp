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

struct node {
	vector<node*> next;
	int cost;
	int allcost;
	int cicada;
};

vector<node> nodes(1001);


int dfs(node &node) {
	vi ret,tmp;
	rep(i,node.next.size()) {
		node.allcost += dfs(*node.next[i]);
	}
	
	if(node.cicada == 0) return min(node.cost, node.allcost);
	return node.cost;
}

int main() {
	int N;
	vi T(1001);
	vi2 C(1001, vi(3));

	cin >> N;
	rep(i,N-1) cin >> T[i];
	rep(i,N-1) cin >> C[i][0] >> C[i][1] >> C[i][2];
	nodes[0].cost = INF;

	rep(i,N-1) {
		nodes[C[i][0]].next.pb(&nodes[C[i][1]]);
		nodes[C[i][1]].cost = (C[i][2]);
		nodes[C[i][1]].cicada = T[i];
	}

	print(dfs(nodes[0]));
	return 0;
}

