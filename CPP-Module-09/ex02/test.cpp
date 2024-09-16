// Time Test

#include <iomanip>
#include <iostream>
#include <sys/time.h>

int	main(void)
{
	struct timeval stop, start;

	gettimeofday(&start, NULL);
	for (size_t i = 0, j = 0; i < 500000000; ++i)
	{
		j++;
	}
	gettimeofday(&stop, NULL);
	std::cout << std::fixed << std::setprecision(5) << stop.tv_sec - start.tv_sec + (stop.tv_usec - start.tv_usec) / static_cast<double>(1000000) << "" << std::endl;
	return 0;
}
