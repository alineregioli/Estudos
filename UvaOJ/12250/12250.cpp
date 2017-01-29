//Uva 12250 - Language Detection
//alineregioli - 26 Janeiro 2017

#include<bits/stdc++.h>

using namespace std;

int caso = 1;
char s[20];
map<string,string> pais;

int main(){
	pais["HELLO"] = "ENGLISH";
	pais["HOLA"] = "SPANISH";
	pais["HALLO"] = "GERMAN";
	pais["BONJOUR"] = "FRENCH";
	pais["CIAO"] = "ITALIAN";
	pais["ZDRAVSTVUJTE"] = "RUSSIAN";
	while(scanf(" %s",s),s[0]!='#'){
		printf("Case %d: ",caso++);
		if(pais.count(s)){
			printf("%s\n",pais[s].c_str());
		}
		else{
			printf("UNKNOWN\n");
		}
	}
	return 0;
}	
