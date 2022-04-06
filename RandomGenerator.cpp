#include "RandomGenerator.h"

namespace bb {
namespace RandomGenerator {

// Explicit Instantiations for Given Types
template class RandomGenerator<bool>;
template class RandomGenerator<char>;

template class RandomGenerator<unsigned char>;
template class RandomGenerator<short>;
template class RandomGenerator<int>;
template class RandomGenerator<long>;
template class RandomGenerator<long long>;
template class RandomGenerator<unsigned short>;
template class RandomGenerator<unsigned int>;
template class RandomGenerator<unsigned long>;
template class RandomGenerator<unsigned long long>;

template class RandomGenerator<float>;
template class RandomGenerator<double>;
template class RandomGenerator<long double>;

}
}