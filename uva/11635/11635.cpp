//Uva 11635	Hotel booking
//alineregioli - 12 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

const int N = 10004, H = 150, oo = 0x3f3f3f3f;

int n, h, m, c, a, b, t, u, v, w, d, x, ans;
int g[H][H], hotel[H], dist[N], visitado[H], ehHotel[N];
vector< vector<pair<int,int> > > grafo;

void Dijkstra(int x){
	memset(dist,oo,sizeof dist);
	priority_queue< pair<int,int>, vector<pair<int,int> >, greater< pair<int,int> > > pq;
	pq.push({0,x}); // (distância, cidade)
	g[ehHotel[x]][ehHotel[x]] = 1; //Tem caminho de x->x
	dist[x] = 0;
	while(!pq.empty()){
		int d = pq.top().first, u = pq.top().second; pq.pop(); //Chegando na cidade u com distância d
		if(dist[u] == d){
			for(int i = 0; i < (int)grafo[u].size(); i++){
				v = grafo[u][i].first;
				w = grafo[u][i].second;
				if( (d + w <=600) && ((d + w) < dist[v]) ){ //Existe caminho sem parar em hotel
					dist[v] = d + w;
					if(ehHotel[v]){
						g[ehHotel[x]][ehHotel[v]] = g[ehHotel[v]][ehHotel[x]] = dist[v]; //Tem caminho de x ao hotel v
					}
					pq.push({dist[v], v});
				}
			}
		}
	}
}

int main(){
	while(scanf("%d",&n),n){
		scanf("%d",&h);
		grafo.assign(n+3,vector< pair<int,int> >());
		for(int i = 0; i <= n; i++){
			ehHotel[i] = 0;
		}
		for(int i = 0; i < h; i++){
			scanf("%d",&hotel[i]);
			if(hotel[i] == 1 || hotel[i] == n){ //Nunca usará hoteis em cidades 1 e n
				h--;
				i--;
			}
			ehHotel[ hotel[i] ] = i + 2;
		}
		ehHotel[1] = 1;
		ehHotel[n] = h+2;
		scanf("%d",&m);
		for (int i = 0; i < m; i++){
			scanf("%d %d %d",&a,&b,&t);
			grafo[a].push_back({b,t});
			grafo[b].push_back({a,t});
		} 
		memset(g,0,sizeof g); //Grafo reduzido começa zerado
		Dijkstra(1);
		if(g[1][n] != 0){ //Existe caminho de 1 a n que dura até 10 horas => não precisa de nenhum hotel
			printf("0\n");
			continue;
		}
		for (int i = 0; i < h; i++){ //Dijkstra a partir de cada hotel
			x = hotel[i];
			Dijkstra(x);
		}
		//DFS partindo de 1, tentando alcançar n:
		memset(visitado,0,sizeof visitado);
		queue< pair<int,int> > q;
		q.push({0,1}); //(distância, cidade)
		ans = -1;
		visitado[1] = 1;
		while(!q.empty()){
			int d = q.front().first, u = q.front().second; q.pop(); //Chegando na cidade u com distância d
			if(u == h+2){ //Chegou no vértice n
				ans = d;
				break;
			}
			for(int i=1;i<=h+2;i++){
				if(g[u][i] and !visitado[i]){
					visitado[i] = 1;
					q.push({d+1,i});
				}
			}
		}
		printf("%d\n",(ans == -1)? -1 : ans-1 );
	}	
	return 0;
}	
