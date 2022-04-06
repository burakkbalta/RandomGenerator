#pragma once

#include <random>

namespace bb {
namespace RandomGenerator {

template<typename T, int RangeBase = 0, int RangeEnd = 1, typename Distribution = void>
class RandomGeneratorBase
{		
	using disType = typename std::conditional<
			std::is_floating_point<T>::value,
			std::uniform_real_distribution<T>,
			std::uniform_int_distribution<T>>::type;
	
	using distributionType = typename std::conditional<
		std::is_void<Distribution>::value,
		disType,
		Distribution>::type;

protected:
	RandomGeneratorBase():
	engine(randomDevice()),
	distribution(rangeBase,rangeEnd)
	{
	}

protected:
	int rangeBase = RangeBase > RangeEnd ? RangeEnd : RangeBase;
	int rangeEnd = RangeBase > RangeEnd ? RangeBase : RangeEnd;
	
	std::random_device randomDevice;
	std::mt19937 engine;
	distributionType distribution;

public:
	template<typename Container>
	void GetRandomNumber(Container& container)
	{
		for(auto it = container.begin(); it!=container.end();++it) {
			*it = distribution(engine);
		}
	}
	
	T GetRandomNumber() {
		return  static_cast<T>(distribution(engine));
	}
	
	void SetSeed(T val1, T val2)
	{
		distributionType tempDist(val1,val2);
		distribution.param(tempDist.param());
	}
	
};

}
}