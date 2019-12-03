#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <vector>
#include <random>

const int DIMENSIONS = 2;

struct particle
{
	std::vector<double> x = std::vector<double>(DIMENSIONS);
	std::vector<double> v = std::vector<double>(DIMENSIONS);
	std::vector<double> x_best = std::vector<double>(DIMENSIONS);
};

void particle_swarm_optimization(double(*f)(const std::vector<double>&),
	std::vector<particle>& population,
	int k_max,
	double w = 1.0,
	double c1 = 1.0,
	double c2 = 1.0);

double func(const std::vector<double>& vec);
double wheeler_ridge(const std::vector<double>& vec);

void randomize(std::vector<particle>& p);

void print_pop(const std::vector<particle>& p);

std::ostream& operator<<(std::ostream& out, const std::vector<double>& rhs);

#endif