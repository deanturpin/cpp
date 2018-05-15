#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {

  using namespace std;

  const std::string name("/tmp/blah.txt");

  std::string one = "one";
  double two = 1.123456789;
  bool three = false;
  bool four = true;

  {
    cout << "FIXED\n";
    cout << "OUT\t" << std::setprecision(10) << one << " " << two << " "
         << std::boolalpha << three << " " << four << "\n";

    ofstream out(name);
    out.precision(10);
    out << one << " " << two << " " << std::boolalpha << three << " " << four
        << "\n";
    out.close();

    // Don't need to set precision on way in
    ifstream in(name);
    in >> one >> two >> three >> four;

    cout << "IN\t" << std::setprecision(10) << one << " " << two << " "
         << std::boolalpha << three << " " << four << "\n";
  }

  {
    cout << "\nSCIENTIFIC\n";
    cout << "OUT\t" << std::scientific << one << " " << two << " "
         << std::boolalpha << three << " " << four << "\n";

    ofstream out(name);
    // out.precision(10);
    out << one << " " << std::scientific << two << " " << std::boolalpha
        << three << " " << four << "\n";
    out.close();

    // Don't need to set precision on way in
    ifstream in(name);
    in >> std::scientific >> one >> two >> three >> four;

    cout << "IN\t" << std::setprecision(10) << one << " " << two << " "
         << std::boolalpha << three << " " << four << "\n";
  }
}