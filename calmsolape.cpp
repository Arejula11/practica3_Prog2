#include <iostream>
using namespace std;
#include "maxsolape.hpp"



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
	tpSolape sol= maxSolFBruta(inters,5);
	tpSolape sol2= maxSolFBruta(inters2,5);
	
	cout<<"Solape = "<<sol.solape<<" A = "<<sol.interA<<" B = "<<sol.interB<<endl;
	cout<<"Solape = "<<sol2.solape<<" A = "<<sol2.interA<<" B = "<<sol2.interB<<endl;
	return 0;
}
