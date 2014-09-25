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

struct node {
	vector<node*> next;
	int chiSum = 0;
	int bal = 0;
};

vector<node> nodes(1000001);

int N,tmp;
vi a(100001);

int dfs(node &node) {
	rep(i,node.next.size()) {
		tmp = dfs(*node.next[i]);
		node.bal = max(node.bal, tmp);
		node.chiSum += tmp;
	}
	
	node.bal = max(N-1-node.chiSum, node.bal);
	return node.chiSum+1;
}

int main() {
	cin >> N;
	erep(i,1,N,1) cin >> a[i];
	erep(i,1,N,1) nodes[a[i]].next.pb(&nodes[i]);

	dfs(nodes[0]);
	
	rep(i,N) print(nodes[i].bal);
	
	return 0;
}
