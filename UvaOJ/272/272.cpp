//Uva 272 TEX Quotes
//alineregioli - 20 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

char linha[100000];
int aux = 0;

int main(){
	while(scanf(" %[^\n]",linha) != EOF){
		for(int i=0; linha[i] ; i++){
			if(linha[i]=='\"'){
				aux? printf("''") : printf("``") ;
				aux ^= 1;
			}
			else{
				putchar(linha[i]);
			}
		}
		putchar('\n');
	}
	return 0;
}	
