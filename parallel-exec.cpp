#include <algorithm>
#include <cassert>
#include <numeric>
// #include <execution>
// #include <parallel_for_each.h>
#include <cmath>
#include <iostream>
#include <vector>

int main() {

  std::vector<double> vec(500); // '000'000);
  std::iota(vec.begin(), vec.end(), 0);

  // std::for_each(std::execution::par, vec.begin(), vec.end(), [](auto &i){
  std::for_each(vec.begin(), vec.end(),
                [](auto &i) { i = std::sqrt(std::sqrt(std::sqrt(i))); });

  std::for_each(vec.cbegin(), std::next(vec.cbegin(), 10),
                [](const auto &i) { std::cout << i << "\n"; });
}
