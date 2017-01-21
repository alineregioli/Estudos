//Uva 11371 Number Theory for Newbies
//alineregioli - 20 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

long long x, y, tam;
char aux[20];

bool cmp(char a, char b){
	return a > b;
}
int main(){
	while(scanf(" %s",aux)!=EOF){
		tam = strlen(aux);
		sort(aux,aux+tam);
		for(int i=0; i< tam; i++){ //Não pode começar com zero
			if(aux[i] != '0'){
				swap(aux[0],aux[i]);
				break;
			}
		}
		sscanf(aux,"%lld",&x);
		sort(aux,aux+tam,cmp); //Descrescente
		sscanf(aux,"%lld",&y);
		printf("%lld - %lld = %lld = 9 * %lld\n",y,x,y-x,(y-x)/9 );
	}
	return 0;
}	
