//Uva 12372 - Packing for Holiday 
//alineregioli - 26 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int t, a, b, c;

int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d%d",&a,&b,&c);
		if(a<=20 && b<=20 && c<=20){
			printf("Case %d: good\n",i);
		}
		else{
			printf("Case %d: bad\n",i);
		}
	}
	return 0;
}	
