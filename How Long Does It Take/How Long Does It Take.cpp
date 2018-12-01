#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct node{
	int v;
	int len;
	node(int _v, int _len){
		v = _v;
		len = _len; 
	}
};

int N, M, inDegree[100], INF = 1000000000, minLen = INF;
vector<node> graph[100];
int countInq[100], d[100];
bool inq[100];

void init();
bool spfa(int s);

int main(){
	scanf("%d %d", &N, &M);
	fill(inDegree, inDegree + N, 0);
	int S, E, L;
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &S, &E, &L);
		graph[S].push_back(node(E, -L));
		inDegree[E]++;
	}
	for(int i = 0; i < N; i++){
		if(inDegree[i] == 0){
			init();
			bool flag = spfa(i);
			if(flag){
				for(int j = 0; j < N; j++){
					if(d[j] < minLen){
						minLen = d[j];
					}
				}
			}
		}
	}
	if(minLen == INF){
		printf("Impossible\n");
	}else{
		printf("%d\n", -minLen);
	}
	return 0;
} 

void init(){
	fill(countInq, countInq + N, 0);
	fill(d, d + N, INF);
	fill(inq, inq + N, false);
}

bool spfa(int s){
	queue<int> q;
	q.push(s);
	d[s] = 0;
	countInq[s]++;
	inq[s] = true;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		inq[u] = false;
		for(int i = 0; i < graph[u].size(); i++){
			int v = graph[u][i].v;
			int len = graph[u][i].len;
			if(len + d[u] < d[v]){
				d[v] = len + d[u];
				if(!inq[v]){
					q.push(v);
					inq[v] = true;
					countInq[v]++;
					if(countInq[v] > N - 1){
						return false;
					}
				}
			}
		}
	}
	return true;
}
