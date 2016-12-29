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
	////std::cout << x.size();
	//Approximation a(nodesAmount, 3, x, y);
	//std::cout << a.aj(0) << std::endl;
	//std::cout << a.aj(1) << std::endl;
	//std::cout << a.aj(2) << std::endl;
	//std::cout << a.aj(3) << std::endl;

	//std::vector<node> disNodes; 
	
	////test
	//for (auto obj : disNodes)
	//{
	//	std::cout << obj.x << " " << obj.y << std::endl;
	//}
	//std::vector<double> normalizeQ;
	//for (int i = 0; i <= nodesAmount; ++i)
	//{
	//	normalizeQ.push_back(linearTransformation(range, disNodes[0].x, disNodes[i].x));
	//	//test
	//	//std::cout << normalizeQ.back() << std::endl;
	//}
	////test
	////std::cout  << std::endl;//grammPolymonial( 4, 3,  1)
	////std::cout << aproximation(nodesAmount, 3, normalizeQ, disNodes);

	////test
	//auto testL = [](double x) {return 1 - x*x; };
	//std::vector<node> testNodes;
	//testNodes= disctretization(4, -1, 1, testL);
	//std::vector<double> normalizeQ2;
	//double tempRange = (1 - (-1)) / 4;
	//for (int i = 0; i <= 4; ++i)
	//{
	//	normalizeQ2.push_back(linearTransformation(0.5, testNodes[0].x, testNodes[i].x));
	//}
	//for (int i = 0; i <= 3; ++i)
	//{
	//	//std::cout << "a" << i << ": "<<aproximation(4, i, normalizeQ2, testNodes) << std::endl;
	//}

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