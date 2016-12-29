#include <iostream>
#include <cmath>
#include <vector>

#include "Approximation.h"
#include "MathUtilities.h"

#include <conio.h>


	


int main()
{
	////TODO: wczytywanie z klawiatury
	//int nodesAmount = 50;
	//double downRange = -2.0;
	//double upRange = 2.0;
	//double range = (upRange - downRange) / nodesAmount;
	//auto lambdaF = [](double x) {return pow(cos(x), 2)*cos(x); };
	//auto lambdaTest = [](double x) {return pow(cos( x),2)*pow(sin( x),2); };

	//std::vector<double> x;
	//std::vector<double> y;
	//disctretization(nodesAmount, downRange, upRange,x,y, lambdaF);
	//Approximation a(25, x, y);
	
	
	

	
	


	

	std::vector<double> x2(5);
	std::vector<double> y2(5);
	x2[0] = 0.0;
	y2[0] = 0.1;

	x2[1] = 0.5;
	y2[1] = 0.3;

	x2[2] = 1.0;
	y2[2] = 1.1;

	x2[3] = 1.5;
	y2[3] = 2.2;

	x2[4] = 2.0;
	y2[4] = 4.2;
	Approximation b(2,x2, y2);
	std::cout<<  std::endl;
	//std::cout << b.aj(0) << std::endl;
	//std::cout << b.aj(1)<<std::endl;
	//std::cout << b.aj(2) << std::endl;
	//std::cout << b.aj(3) << std::endl;

	for(auto obj:b.m_q)
		std::cout <<"q: "<< obj << std::endl;
	for (auto obj : b.m_x)
		std::cout << "x: " << obj << std::endl;
	for (auto obj : b.m_y)
		std::cout << "y: " << obj << std::endl;

	for (auto obj : b.m_aj)
		std::cout << "aj: " << obj << std::endl;
	for (auto obj : b.m_daj)
		std::cout << "d a: " << obj << std::endl;
	//for (int i=0; i <= 2; ++i)
	//{
	//	for (int j = 0; j <= 4; ++j)
	//	{
	//		std::cout << "Pj: " << b.m_Pjq[i][j] << std::endl;
	//	}
	//}
	
		_getch();
	return 0;
}