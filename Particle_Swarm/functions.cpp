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
	std::uniform_real_distribution<> distr(0, 1.0);
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
			for (int k = 0; k < n; ++k)
			{
				double r1, r2 = 0.0;
				r1 = distr(eng);
				r2 = distr(eng);
				population[j].v[k] = w * population[j].v[k] + c1 * r1 * (population[j].x_best[k] - population[j].x[k])
													  + c2 * r2 * (x_best[k] - population[j].x[k]);
				population[j].x[k] += population[j].v[k];
			}
			double y = f(population[j].x);
			if (y < y_best)
			{
				x_best = population[j].x;
				y_best = y;
				if (y < f(population[j].x_best))
				{
					population[j].x_best = population[j].x;
				}
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
		result += pow(vec[i], 2);
	}
	return result;
}

double wheeler_ridge(const std::vector<double>& vec)
{
	double temp = -pow((vec[0] * vec[1] - 1.5), 2) - pow((vec[1] - 1.5), 2);
	return -pow(2.71828, temp);
}

// initializes particles to random values
void randomize(std::vector<particle>& p)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<> distr(0.0, 10.0);
	std::uniform_real_distribution<> distr2(10.0, 20.0);

	size_t len = p.size();
	for (int i = 0; i < len; ++i)
	{
		particle temp;
		size_t len2 = temp.x.size();
		for (int j = 0; j < len2; ++j)
		{
			temp.x[j] = distr(eng);
			temp.x_best[j] = temp.x[j];
			temp.v[j] = distr2(eng);
		}
		p[i] = temp;
	}
}

// for printing the x coords of the population
void print_pop(const std::vector<particle>& p)
{
	size_t len = p.size();
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << p[i].x;
		std::cout << std::endl;
	}
	std::cout << std::endl;
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
