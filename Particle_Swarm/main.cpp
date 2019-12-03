#include "functions.h"

const int SMALL_SET = 10;

int main()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_real_distribution<> distr(-10.0, 10.0);

	std::vector<particle> p;
	for (int i = 0; i < SMALL_SET; ++i)
	{
		particle temp;
		size_t len = temp.x.size();
		for (int j = 0; j < len; ++j)
		{
			temp.x[j] = distr(eng);
		}
		p.push_back(temp);
	}

	size_t len = p.size();
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << p[i].x;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	particle_swarm_optimization(func, p, 30);

	for (size_t i = 0; i < len; ++i)
	{
		std::cout << p[i].x_best;
		std::cout << std::endl;
	}

	std::cout << std::endl;
	system("pause");
	return 0;
}


