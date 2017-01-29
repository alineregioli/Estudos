//Uva 11498 - Division of Nlogonia
//alineregioli - 26 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int k, x, y, ox, oy;

int main(){
	while(scanf("%d",&k),k){
		scanf("%d%d",&ox,&oy);
		for(int i=0;i<k;i++){
			scanf("%d%d",&x,&y);
			if(x == ox || y == oy){
				printf("divisa\n");
			}
			else if(x < ox){ //Oeste
				if( y > oy)
					printf("NO\n"); //Norte
				else
					printf("SO\n"); //Sul
			}
			else{ //Leste
				if( y > oy)
					printf("NE\n"); //Norte
				else
					printf("SE\n"); //Sul
			}
		}
	}
	return 0;
}	
