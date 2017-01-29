//Uva 11547 - Automatic Answer
//alineregioli - 26 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int t, n;

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		n = (63*n + 7492)*5 - 498;
		printf("%d\n",(abs(n/10))%10);
	}
	return 0;
}	
