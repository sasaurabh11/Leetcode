#define ll long long 

class DisjointSet {
public:
 
	vector<ll> rank, parent, size;
 
	DisjointSet(ll n) {
		rank.resize(n + 1, 0);
		parent.resize(n + 1);
		size.resize(n + 1, 1);
		for(ll i = 1; i <= n; i++) parent[i] = i;
	}
 
	void unionByRank(ll x, ll y) {
 
		ll par_x = findPar(x);
		ll par_y = findPar(y);
 
		if(par_x == par_y) return;
 
		if(rank[par_x] < rank[par_y]) {
			parent[par_x] = par_y;
		} else if(rank[par_y] < rank[par_x]) {
			parent[par_y] = par_x;
		} else {
			parent[par_x] = par_y;
			rank[par_y]++;
		}
	}
 
	void unionBySize(ll x, ll y) {
 
		ll par_x = findPar(x);
		ll par_y = findPar(y);
 
		if(par_x == par_y) return;
 
		if(size[par_x] < size[par_y]) {
			parent[par_x] = par_y;
			size[par_y] += size[par_x];
		} else {
			parent[par_y] = par_x;
			size[par_x] += size[par_y];
		}
	}
 
	ll findPar(ll x) {
 
		if(parent[x] == x) return x;
 
		return parent[x] = findPar(parent[x]);
	}
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        DisjointSet dsu(n + 1);
        for(int i = 0; i < n; i++) {
            int u = edges[i][0], v = edges[i][1];
            if(dsu.findPar(u) == dsu.findPar(v)) {
                return {u, v};
            }

            dsu.unionByRank(u, v);
        }

        return {};
    }
};
