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
	int num;
};

vector<node> nodes(1000001);
int N, v, dist;

void dfs(node &node, int cnt, int f) {
	if(dist <= cnt) {
		dist = cnt;
		v = node.num;
	}
	
	rep(i,node.next.size()) if(node.next[i]->num != f) dfs(*node.next[i], cnt+1, node.num);
}

int main() {
	vi2 A(1000001, vi(2));

	cin >> N;
	rep(i,N-1) cin >> A[i][0] >> A[i][1];

	rep(i,N-1) {
		nodes[A[i][0]-1].next.pb(&nodes[A[i][1]-1]);
		nodes[A[i][1]-1].next.pb(&nodes[A[i][0]-1]);
	}
	rep(i,N) nodes[i].num = i+1;
	
	dfs(nodes[0], 0, 0);
	cout << v << ' ';
	dfs(nodes[v-1], 0, 0);

	print(v);

	return 0;
}
