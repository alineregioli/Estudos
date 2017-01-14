//Uva 12403 Save Setu
//alineregioli - 13 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int t, k, total = 0;
char comando[30];

int main(){
	scanf("%d",&t); 
	while(t--){
		scanf(" %s",comando);
		if(comando[0]=='d'){ //Donate
			scanf("%d",&k);
			total += k;
		}
		else{ //Report
			printf("%d\n", total);
		}
	}
	return 0;
}	
