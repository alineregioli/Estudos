//Uva 10911	Forming Quiz Teams
//alineregioli - 12 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

const int N = 17;
const double oo = 1e10; // Infinito : oo = 10B

int n, todos, caso = 1;
char nome[50];
double x[N], y[N], dist[N][N], memo[1<<17];

double pd(int mask){
	if(mask == todos){ //Todos estudantes já foram agrupados
		return 0;
	}
	if(memo[mask] > -0.9){ //Essa situação já foi calculada
		return memo[mask];
	}
	int x, y;
	for(x=0;x<n;x++){
		if(mask & (1<<x)){ //Estudante x já foi agrupado
			continue;
		}
		break; //x contém índice do primeiro estudante não agrupado
	}
	double ans = oo;
	for(y=x+1; y<n;y++){
		if( !(mask & (1 << y)) ){ //Estudante y ainda não foi agrupado
			ans = min(ans, dist[x][y] + pd(mask | (1<<x) | (1<<y) )); //Calcular agrupamento de y com x
		}
	}
	return memo[mask] = ans;
}


int main(){
	while(scanf("%d",&n),n){
		n = n<<1; // n = 2*n
		for(int i=0;i<n;i++){
			scanf(" %s %lf %lf",nome,&x[i],&y[i]);
		}
		for (int i = 0; i < n; i++){
			dist[i][i] = 0;
			for (int j = i+1; j < n; j++){
				dist[i][j] = dist[j][i] = hypot(x[i]-x[j], y[i]-y[j]); //Pré-calcular distância todos X todos
			}
		}
		todos = (1<<n) - 1; //Bitmask completa
		for(int i=0;i<=todos;i++){ 
			memo[i] = -1; //Limpar matriz de memorização
		}
		printf("Case %d: %.2lf\n",caso++,pd(0));
	}
	return 0;
}	
