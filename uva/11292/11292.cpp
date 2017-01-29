//Uva 11292  Dragon of Loowater
//alineregioli - 12 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

const int N = 20005;

int n, m, cabeca, cavaleiro;
long long d[N], a[N], ans;

int main(){
	while(scanf("%d%d",&n,&m)){
		if(!n and !m){ //0 0
			break;
		}
		for(int i=0;i<n;i++){
			scanf("%lld",&d[i]);
		}
		for(int i=0;i<m;i++){
			scanf("%lld",&a[i]);
		}
		if(n > m){ //Existe mais cabeças do que cavaleiros
			printf("Loowater is doomed!\n");
			continue;
		}
		sort(d,d+n);
		sort(a,a+m);
		cabeca = cavaleiro = 0;
		ans = 0;
		while(cabeca < n){
			while(cavaleiro < m and d[cabeca] > a[cavaleiro]){ //"cavaleiro" não consegue matar "cabeca"
				cavaleiro++;
			}
			if(cavaleiro == m){ //Não foi possível matar a "cabeca"
				ans = -1; 
				break;
			}
			ans += a[cavaleiro]; //"cavaleiro" matou "cabeca"
			cavaleiro++;
			cabeca++;
		}
		if(ans == -1){
			printf("Loowater is doomed!\n");
		}
		else{
			printf("%lld\n", ans);
		}
	}
	return 0;
}	
