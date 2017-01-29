//Uva 12289 - One-Two-Three
//alineregioli - 26 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int t, um, dois;
char palavra[20], one[] = "one", two[] = "two" ;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf(" %s",palavra);
		if(strlen(palavra) == 5){
			printf("3\n");
			continue;
		}
		um = dois = 0;
		for(int i=0;i<3;i++){	
			if(palavra[i] == one[i]) um++;
			else if(palavra[i] == two[i]) dois++;
		}
		printf("%d\n",(um>dois)? 1 : 2);
		
	}
	return 0;
}	
