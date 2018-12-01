#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct edge{
	int u, v, cost;
	edge(int _u, int _v, int _cost){
		u = _u;
		v = _v;
		cost = _cost;
	}
};

int N, M;
vector<edge> edges;
int father[1001]; 

int findFather(int x);
int kruskal();
bool cmp(edge e1, edge e2);

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++){
		father[i] = i;
	}
	int v1, v2, cost;
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &v1, &v2, &cost);
		edges.push_back(edge(v1, v2, cost));
	}
	int result = kruskal();
	printf("%d\n", result);
	return 0;
} 

int findFather(int x){
	int a = x;
	while(x != father[x]){
		x = father[x];
	}
	while(a != father[a]){
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int kruskal(){
	int ans = 0, num_edge = 0;
	sort(edges.begin(), edges.end(), cmp);
	for(int i = 0; i < M; i++){
		int uFather = findFather(edges[i].u);
		int vFather = findFather(edges[i].v);
		if(uFather != vFather){
			father[uFather] = vFather;
			ans += edges[i].cost;
			num_edge++;
			if(num_edge == N - 1){
				break;
			}
		}
	}
	if(num_edge != N - 1){
		return -1;
	}
	return ans;
}

bool cmp(edge e1, edge e2){
	return e1.cost < e2.cost;
}
