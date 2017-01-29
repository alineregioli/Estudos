//Uva 12577 - Hajj-e-Akbar
//alineregioli - 26 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

char s[20];
int caso = 1;

int main(){
	while(scanf(" %s",s),s[0]!='*'){
		if(s[0] == 'H'){ //Hajj
			printf("Case %d: Hajj-e-Akbar\n",caso++);
		}	
		else{ //Umrah
			printf("Case %d: Hajj-e-Asghar\n",caso++);
		}
	}
	return 0;
}	
