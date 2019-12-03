#include "functions.h"
#include <random>

void particle_swarm_optimization(double(*f)(const std::vector<double>&),
	std::vector<particle>& population,
	int k_max,
	double w,
	double c1,
	double c2)
{
	int n = population[0].x.size();
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, n - 1);
	std::vector<double> x_best = population[0].x_best;
	double y_best = DBL_MAX;

	size_t len = population.size();
	for (size_t i = 0; i < len; ++i)
	{
		double y = f(population[i].x);
		if (y < y_best)
		{
			x_best = population[i].x;
			y_best = y;
		}
	}
	for (int i = 0; i < k_max; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
			double r1, r2 = 0.0;
			r1 = distr(eng);
			r2 = distr(eng);
			population[j].x += population[j].v;
			population[j].v = w * population[j].v + c1 * r1 * (population[j].x_best - population[j].x)
												  + c2 * r2 * (x_best - population[j].x);
			double y = f(population[j].x);
			if (y < y_best)
			{
				x_best = population[j].x;
				y_best = y;
			}
			if (y < f(population[j].x_best))
			{
				population[j].x_best = population[j].x;
			}
		}
	}
}

double func(const std::vector<double>& vec)
{
	size_t len = vec.size();
	double result = 0.0;
	for (size_t i = 0; i < len; ++i)
	{
		result += vec[i];
	}
	return result;
}

std::vector<double> operator-(const std::vector<double>& lhs, const std::vector<double>& rhs)
{
	size_t len = lhs.size();
	std::vector<double> result(len);
	for (size_t i = 0; i < len; ++i)
	{
		result[i] = lhs[i] - rhs[i];
	}
	return result;
}

std::vector<double> operator+(const std::vector<double>& lhs, const std::vector<double>& rhs)
{
	size_t len = lhs.size();
	std::vector<double> result(len);
	for (size_t i = 0; i < len; ++i)
	{
		result[i] = lhs[i] + rhs[i];
	}
	return result;
}

std::vector<double> operator+(double lhs, const std::vector<double>& rhs)
{
	size_t len = rhs.size();
	std::vector<double> result(len);
	for (size_t i = 0; i < len; ++i)
	{
		result[i] = lhs + rhs[i];
	}
	return result;
}


std::vector<double> operator*(double lhs, const std::vector<double>& rhs)
{
	size_t len = rhs.size();
	std::vector<double> result(len);
	for (size_t i = 0; i < len; ++i)
	{
		result[i] = lhs * rhs[i];
	}
	return result;
}

void operator+=(std::vector<double>& lhs, const std::vector<double>& rhs)
{
	size_t len = lhs.size();
	for (int i = 0; i < len; ++i)
	{
		lhs[i] += rhs[i];
	}
}

std::ostream& operator<<(std::ostream& out, const std::vector<double>& rhs)
{
	size_t len = rhs.size();
	for (size_t i = 0; i < len; ++i)
	{
		out << rhs[i] << " ";
	}
	return out;
}
