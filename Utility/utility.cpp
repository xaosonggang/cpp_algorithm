#include "utility.h"
#include <random>
#include <ctime>

vector<int> GetRandomVecInt(int nCount, int nMaxNum /*= 9999*/)
{
	static vector<int> defaultVec;
	if (nCount < 1) return defaultVec;

	if (nMaxNum < 1)
	{
		nMaxNum = 10;
	}

	int tick = static_cast<int>(std::clock() * 1000 / CLOCKS_PER_SEC);
	std::default_random_engine engine(tick);
	std::uniform_int_distribution<int> uniform(0, nMaxNum);
	
	vector<int> vec;
	for (int i = 0; i < nCount; ++i)
	{
		vec.push_back(uniform(engine));
	}
	return vec;
}

int GetRandomInt(int nMin, int nMax)
{
	static int tick = static_cast<int>(std::clock() * 1000 / CLOCKS_PER_SEC);
	static std::default_random_engine engine(tick);

	if (nMin > nMax)
	{
		int temp = nMax;
		nMax = nMin;
		nMin = temp;
	}
	std::uniform_int_distribution<int> uniform(nMin, nMax);
	return uniform(engine);
}
