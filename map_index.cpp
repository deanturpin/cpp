#include <iostream>
#include <map>

int main() {

  std::map<int, std::string> m{
      {1, "one"},
      {2, "two"},
      {3, "three"},
  };

  std::map<int, double> d{
      {1, 1.0},
      {2, 2.0},
      {3, 3.0},
  };

  std::cout << m.size() << " size\n"
            << m[1] << '\n'
            << m[2] << '\n'
            << m[3] << '\n'
            << m[0] << '\n';

  std::cout << d.size() << " size\n"
            << d[1] << '\n'
            << d[2] << '\n'
            << d[3] << '\n'
            << d[0] << '\n';
}
