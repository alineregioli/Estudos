//Uva 10550 Combination Lock
//alineregioli - 20 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int a, b, c, d, ans;

int main(){
	while(scanf("%d%d%d%d",&a,&b,&c,&d)){
		if(!a && !b && !c && !d) break;
		ans = 720+360;
		ans += ((40+a-b)%40)*9;
		ans += ((40+c-b)%40)*9;
		ans += ((40+c-d)%40)*9;
		printf("%d\n", ans);
	}
	return 0;
}	
