//Uva 11727 - Cost Cutting
//alineregioli - 26 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int t, v[3], caso = 1;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&v[0],&v[1],&v[2]);
		sort(v,v+3);
		printf("Case %d: %d\n",caso++,v[1]);
	}
	return 0;
}	
