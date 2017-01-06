#include "Approximation.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
Approximation::Approximation(int degree,std::vector<double> x, std::vector<double> y) :mDegree(degree),m_x(x), m_y(y)
{
	mNodesAmount = x.size() - 1;
	mRange = (m_x.back()-m_x.front()) / mNodesAmount;
	linearTransformation();
	aj();
	deltaAj();
}

Approximation::Approximation(int degree, std::ifstream & input) :mDegree(degree)
{
	std::string temp;
	while (getline(input,temp))
	{
		m_x.push_back(atof(temp.c_str()));
		getline(input, temp);
		m_y.push_back(atof(temp.c_str()));
	}

	mNodesAmount = m_x.size() - 1;
	mRange = (m_x.back() - m_x.front()) / mNodesAmount;
	linearTransformation();
	aj();
	deltaAj();
}

double Approximation::cj(int degree)
{
	double sum = 0;

	for (int i = 0; i <= mNodesAmount; ++i)
	{
		sum += m_y[i]* grammPolymonial(degree, m_q[i]);
	}
	
	return sum;
}

double Approximation::sj( int degree)
{
	double sum = 0.0;
	for (int i = 0; i <= mNodesAmount; ++i)
	{
		sum += pow(grammPolymonial(degree,m_q[i]), 2);
	}
	return sum;
}

double Approximation::aj( int degree)
{
	double cJ = cj( degree);
	double sJ = sj( degree);
	double aj = cJ / sJ;
	
	return aj;
}

double Approximation::operator()(int degree, double x)
{
	double y = 0.0;
	int q = linearTransformation(x);
	for (int i = 0; i <= degree; ++i)
	{
		y += aj(i)*grammPolymonial(i,q);
	}
	return y;
}

double Approximation::grammPolymonial( int degree, double q)
{
	
	double sum = 0.0;
	
	for (int i = 0; i <= degree; ++i)
	{
		double temp = 0.0;
		temp = pow(-1, i);
		temp *= newtonSymbol(degree, i);
		temp *= newtonSymbol(degree + i, i);
		temp *= grammProduct(q, i) / grammProduct(mNodesAmount, i);
		sum += temp;
	}
	//std::cout << "Pj: " << degree<< " " << q << " " << sum << std::endl;
	
	return sum;
}



void Approximation::aj()
{
	for (int i = 0; i <= mDegree; ++i)
	{
		m_aj.push_back(aj(i));
	}
}

double Approximation::linearTransformation(double x)
{
	return (x - m_x.front()) / mRange;
}

void Approximation::linearTransformation()
{
	for (auto x : m_x)
	{
		m_q.push_back(static_cast<int>(linearTransformation(x)));
	}
}

double Approximation::grammProduct(double r, int n)
{
	if (n == 0)
		return 1;
	else if (n == 1)
		return r;

	double tempProduct = r;
	for (int i = 1; i < n; ++i)
		tempProduct *= (r - i);
	return tempProduct;
}

double Approximation::deltaAj(int degree)
{
	double daj=0.0;
	double tempDaj=0.0;
	for (int i = 0; i <= mNodesAmount; ++i)
	{
		double tempSum = 0.0;
		for (int j = 0; j <= degree; ++j)
		{
			tempSum += m_aj[j]* pow(m_x[i], j);
			tempSum -= m_y[i];
		}
		tempDaj += pow(tempSum, 2);
	}
	tempDaj /= mNodesAmount + 1;
	daj = sqrt(tempDaj);
	return daj;
}

void Approximation::deltaAj()
{
	for (int i = 0; i <= mDegree; ++i)
	{
		m_daj.push_back(deltaAj(i));
	}
}

void Approximation::clear()
{
	m_x.clear();
	m_y.clear();
	m_q.clear();
	m_aj.clear();
	//m_Pjq.clear();
	//m_cj.clear();
	//m_sj.clear();
}

std::ostream & operator<< (std::ostream & output, const Approximation input)
{
	for (int i = 0; i < input.m_q.size(); ++i)
	{
		output<<"i:"<<i<<" " << "q: " << input.m_q[i] << "   x: " << input.m_x[i] << "\t  y: " << input.m_y[i] << std::endl;
	}
	for (int i = 0; i < input.m_aj.size(); ++i)
	{
		output << "a" << i << " " << input.m_aj[i] << std::endl;
	}
	return output;
}

Approximation::~Approximation()
{
}

//void Approximation::grammPolymonial(int degree)
//{
//	for (auto q : m_q)
//	{
//		m_Pjq[degree].push_back(grammPolymonial(degree, q));
//	}
//}