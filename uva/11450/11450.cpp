//Uva 11450	Wedding shopping
//alineregioli - 12 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

const int C = 25, M = 205, oo = 1e9;
int n, m, c, k[C], custo[C][C], memo[C][M], calculado[C][M];

int pd(int tipo, int dinheiro){ //Escolher a peça para o "tipo" tendo "dinheiro"
	if(tipo == c){ //Já calculou para todos os tipos
		return 0;
	}
	if(dinheiro == 0){ //Acabou o dinheiro e não comprou uma peça de cada tipo
		return -oo;
	}
	if(calculado[tipo][dinheiro] ){ //Essa situação já foi calculada
		return memo[tipo][dinheiro];
	}
	int ans = -oo;
	for(int i=0;i<k[tipo];i++){
		if(dinheiro >= custo[tipo][i]){ 
			ans = max(ans, custo[tipo][i] + pd(tipo+1, dinheiro-custo[tipo][i]));
		}
		else{ //Como os custos estão ordenados, se não foi possível comprar custo[tipo][i], não será possível comprar custo[tipo][i+1]
			break;
		}
	}
	calculado[tipo][dinheiro] = 1;
	return memo[tipo][dinheiro] = ans;
}

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&m,&c);
		for(int i=0;i<c;i++){
			scanf("%d",&k[i]);
			for(int j=0;j<k[i];j++){
				scanf("%d",&custo[i][j]);
			}
			sort(custo[i], custo[i]+k[i]); //Ordenar custos
			unique(custo[i], custo[i]+k[i]); //Remover repetições
		}
		memset(calculado,0,sizeof calculado); //Limpar matriz que determina se situação (tipo,dinheiro) já foi calculada
		int ans = pd(0,m);
		if(ans >= 0){
			printf("%d\n", ans);
		}
		else{
			printf("no solution\n");
		}
	}
	return 0;
}	