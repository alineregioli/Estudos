//Uva 10717 Mint
//alineregioli - 17 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

const int N = 52, T = 12;
int n, t, a, cnt;
int e[N], m[7000000];

int MDC(int a, int b){
	if(b == 0){
		return a;
	}
	return MDC(b,a%b);
}

int MMC(int a, int b){
	return (a*b)/MDC(a,b);
}

int main(){
	while(scanf("%d%d",&n,&t),n,t){
		for(int i=0; i<n ; i++){
			scanf("%d",&e[i]);
		}
		//Gerar todas as combinações de 4 elementos, e calcular MMC(e[i],e[j],e[k],e[l])
		cnt = 0;
		for(int i=0; i<n-3 ; i++){
			for(int j=i+1; j<n-2 ; j++){
				int m1 = MMC(e[i],e[j]);
				for(int k=j+1; k<n-1 ; k++){
					int m2 = MMC(m1,e[k]);
					for(int l=k+1; l<n ; l++){
						m[cnt++] = MMC(m2,e[l]);
					}
				}
			}
		}
		int menor, maior, aux;
		for(int j=0; j<t ; j++){
			scanf("%d",&a); //Consultas
			menor = 0; maior = 0x3f3f3f3f;
			for(int i=0; i<cnt ; i++){
				if(a >= m[i]){
					if(a % m[i] == 0){ //Melhor situação: é possível pernas com a altura desejada
						menor = maior = a;
						goto ANS; 
					}
					aux = a/m[i];
					menor = max(menor,aux*m[i]);
					maior = min(maior,(aux+1)*m[i]);
				}
				else{ //m[i] é maior que altura desejada
					maior = min(maior,m[i]);
				}
			}
			ANS:
			printf("%d %d\n", menor, maior);
		}
	}
	return 0;
}	
