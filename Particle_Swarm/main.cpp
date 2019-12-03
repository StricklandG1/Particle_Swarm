#include "functions.h"

const int SMALL_SET = 5;

int main()
{
	std::vector<particle> p(SMALL_SET);
	randomize(p);

	print_pop(p);

	particle_swarm_optimization(func, p, 10, 0.1, 0.5, 1);

	print_pop(p);

	std::cout << std::endl;
	system("pause");
	return 0;
}


