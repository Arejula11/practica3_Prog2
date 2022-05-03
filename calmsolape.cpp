#include <iostream>
using namespace std;
#include "maxsolape.hpp"


void probarMax(double  inters[N][2], double inters2[N][2]){

	tpSolape sol= maxSolFBruta(inters,5);
	tpSolape sol2= maxSolFBruta(inters2,5);
	
	cout<<"Solape = "<<sol.solape<<" A = "<<sol.interA<<" B = "<<sol.interB<<endl;
	cout<<"Solape = "<<sol2.solape<<" A = "<<sol2.interA<<" B = "<<sol2.interB<<endl;
}
void probarInt(double inters[N][2], tpInter indinters[N], int n){
	crearvind(inters, indinters, n);
	for(int i=0; i<n; i++){
		cout << indinters[i].ind << ": " << indinters[i].ini << " - " << indinters[i].fin << endl;
	}

}
void pruebaMergesortIndInters(tpInter indinters[N], int n){
	int p=0;
	int f=4;
	mergesortIndInters(indinters, p,f);
	for(int i=0; i<n; i++){
		cout << indinters[i].ind << ": " << indinters[i].ini << " - " << indinters[i].fin << endl;
	}
	
}
int main(){
	double inters[N][2] = {
        	{1.5, 8.0},
        	{0.0, 4.5},
        	{2.0, 4.0},
      		{1.0, 6.0},
	        {3.5, 7.0},
	};
double inters2[N][2] = {
        	{4.0, 8.0},
        	{0.0, 4.5},
        	{0.5, 4.0},
      		{1.0, 6.0},
	        {3.5, 7.0},
	};
	cout<<"PROBAR MAX:"<<endl;
	probarMax(inters,inters2);
	cout<<"PROBAR CREARINT"<<endl;
	tpInter inditerns[N];
	probarInt(inters, inditerns,5);
	cout<<endl;
	tpInter inditerns2[N];
	probarInt(inters2, inditerns2,4);
	cout<<endl;

	cout<<"PROBAR MERGESORT"<<endl;
	pruebaMergesortIndInters(inditerns,5);
	
	return 0;
}
