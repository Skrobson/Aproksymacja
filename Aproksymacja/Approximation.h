#pragma once
#include <vector>
#include "MathUtilities.h"
#include <iostream>
#include <fstream>



//TODO: sprawdzanie czy punkty sa rownolegle
class Approximation
{
public:
	
	Approximation(int degree, std::vector<double> x, std::vector<double> y);

	Approximation(int degree, std::ifstream & input);

	double aj( int degree);
	
	double operator()(int degree, double x);

	std::vector<double> m_x;
	std::vector<double> m_y;
	std::vector<int> m_q;
	std::vector<double> m_aj;
	std::vector<double> m_daj;

	friend std::ostream & operator<<(std::ostream & output, const Approximation input);

	~Approximation();
protected:
	
	double mRange;
	int mDegree;
	int mNodesAmount;

	double linearTransformation(double x);
	void linearTransformation();

	double grammProduct(double r, int n);
	double grammPolymonial(int degree, double q);
	
	double cj(int degree);
	double sj(int degree);

	void aj();

	double deltaAj(int degree);
	void deltaAj();

	void clear();
	
	//std::vector<double> m_cj;
	//std::vector<double> m_sj;
	//std::vector<std::vector<double>> m_Pjq;
	//void grammPolymonial(int degree);
};



