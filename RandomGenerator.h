#pragma once

#include "RandomGeneratorBase.h"

namespace bb {
namespace RandomGenerator {

// Template Random Generator Class	
template<typename T, int RangeBase = 0, int RangeEnd = 1, typename Distribution = void>
class RandomGenerator : public RandomGeneratorBase<T,RangeBase, RangeEnd, Distribution> 
{	
};

// Template Specialization For The Type of Char	
template<int RangeBase, int RangeEnd, typename Distribution>
class RandomGenerator<char, RangeBase, RangeEnd, Distribution> : 
	public RandomGeneratorBase<char, RangeBase, RangeEnd, std::uniform_int_distribution<int>>
{
	
// Type Definition	
	using Base = RandomGeneratorBase<char, RangeBase, RangeEnd, std::uniform_int_distribution<int>>;
	
// Public Functions		
public:	
	template<typename Container>
	void GetRandomNumber(Container& container) {
		auto range = (Base::rangeEnd - Base::rangeBase) >= 52 ? 52 : (Base::rangeEnd - Base::rangeBase + 1); 
		for(auto it = container.begin(); it!=container.end();++it) {
			auto val = (Base::distribution(Base::engine) % range);
			*it = Base::rangeBase + val;
		}
	}
	
	char GetRandomNumber() {
		auto range = (Base::rangeEnd - Base::rangeBase) >= 52 ? 52 : (Base::rangeEnd - Base::rangeBase + 1); 
		auto val = Base::rangeBase + (Base::distribution(Base::engine) % range);
		return val;
	}
	
	void SetSeed(char val1, char val2) {
		std::uniform_int_distribution<int> tempDist((int)val1,(int)val2);
		Base::rangeBase = val1;
		Base::rangeEnd = val2;
		Base::distribution.param(tempDist.param());
	}
	
	void SetSeed(int val1, int val2) {
		std::uniform_int_distribution<int> tempDist(val1,val2);
		Base::rangeBase = 'A' + val1;
		Base::rangeEnd = 'A' + val2;
		Base::distribution.param(tempDist.param());
	}

};

// Template Specialization For The Type of Boolean	
template<int RangeBase, int RangeEnd, typename Distribution>
class RandomGenerator<bool, RangeBase, RangeEnd, Distribution> : 
	public RandomGeneratorBase<bool, 0, 1, std::uniform_int_distribution<int>>
{	
	using Base = RandomGeneratorBase<bool, 0, 1, std::uniform_int_distribution<int>>;	
	
public:
	template<typename Container>
	void GetRandomNumber(Container& container) {
		for(auto it = container.begin(); it!=container.end();++it) {			
			*it = (Base::distribution(Base::engine)) == 1 ? true : false;
		}
	}
	
	bool GetRandomNumber() {
		auto val = (Base::distribution(Base::engine)) == 1 ? true : false;
		return val;
	}
	
	void SetSeed(bool val1, bool val2) {
		//Not implemented. Because there are two options for the type of boolean. To set seed does not make sense.
	}
	
};

// Extern Template Specializations
extern template class RandomGenerator<bool>;
extern template class RandomGenerator<char>;

extern template class RandomGenerator<unsigned char>;
extern template class RandomGenerator<short>;
extern template class RandomGenerator<int>;
extern template class RandomGenerator<long>;
extern template class RandomGenerator<long long>;
extern template class RandomGenerator<unsigned short>;
extern template class RandomGenerator<unsigned int>;
extern template class RandomGenerator<unsigned long>;
extern template class RandomGenerator<unsigned long long>;

extern template class RandomGenerator<float>;
extern template class RandomGenerator<double>;
extern template class RandomGenerator<long double>;

}
}