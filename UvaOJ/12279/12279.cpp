//Uva 12279 - Emoogle Balance
//alineregioli - 26 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int n, reason, treat, event, caso = 1;

int main(){
	while(scanf("%d",&n),n){
		reason = treat = 0;
		while(n--){
			scanf("%d",&event);
			if(!event) treat++;
			else reason++;
		}
		printf("Case %d: %d\n", caso++, reason-treat);
	}
	return 0;
}	
