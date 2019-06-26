#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

template <typename T> void print_permutations(const T &a, const T &b) {

  // If we've extracted all the element then print the result
  if (a.empty()) {
    for (auto i : b)
      std::cout << i << " ";
    std::cout << "\n";
  } else {

    for (size_t i = 0; i < a.size(); ++i) {

      auto _a = a;
      auto _b = b;

      // Move current value to second container
      _b.push_back(a.at(i));
      _a.erase(_a.begin() + i);

      print_permutations(_a, _b);
    }
  }
}

std::string perms(const int n) {

  if (n == 0)
    return "\n";

  return std::to_string(n) + perms(n - 1);
}

std::string perm_str(std::string s) {
  return s.empty() ? "\n" : perm_str(s.substr(1)) + s[0];
}

std::string bin_tree(const int n) {
  if (n == 0)
    return "-\n";

  std::stringstream v;

  v << "L" << n << bin_tree(n - 1)
    << "R" << n << bin_tree(n - 1);

  // TODO - ostream

  return v.str();
}

int main() {
  std::cout << perms(4);
  std::cout << perm_str("1234") << "\n\n";
  std::cout << bin_tree(4);
}
