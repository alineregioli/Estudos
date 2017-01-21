//Uva 579 Clock Hands
//alineregioli - 20 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int h, m;
double H, M, ans;

int main(){
	while(scanf("%d:%d",&h,&m),h){
		H = 30.0*h + m/2.0; //Cada 12 hr são 360° e a cada 6 min são 6°
		M = 6.0*m ; //Cada 60 min são 360°
		ans = fabs(H-M);
		if(ans > 180)
			ans = 360.0 - ans;
		printf("%.3lf\n", ans);
	}
	return 0;
}	
