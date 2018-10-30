#include <cassert>
#include <cmath>
#include <iostream>
#include <sstream>

int main() {

  // Create the public key for sharing
  const auto generate_public_key = [](const auto seed,
                                      const auto base) constexpr {
    return std::lrint(std::pow(base, seed)) %
           0b11111111'11111111'11111111'11111110;
  };

  // Generate and exchange keys
  const auto a{5ul};
  const auto b{4ul};
  const auto A{generate_public_key(a, 5)};
  const auto B{generate_public_key(b, 5)};
  const auto s1{generate_public_key(A, B)};
  const auto s2{generate_public_key(B, A)};

  // The secret
  const std::string plaintext{"llllllllllllllllllllllllllllllllllllllll"
                              "lllllllooooooooooooooooooolllllllllollll"
                              "lllllllooooooooooooooooooolllllllllollll"
                              "llllllllllllllollllllllllllllllllllollll"
                              "lllllllllllllllollllllllollllllllllollll"
                              "oolllooollllllllllolllllollllllllllollll"
                              "lloollloollllllllllolllllllllllllllollll"
                              "                                        "
                              "Beautiful is better than ugly. Explicit "
                              "is better than implicit. Simple is bette"
                              "r than complex. Complex is better than c"
                              "omplicated. Flat is better than nested. "};

  // Encrypt a message using supplied function
  const auto encrypt = [](const auto message, const auto func) {
    // Format the message for printing
    const auto format = [](const std::string in) {
      unsigned count{1};
      std::stringstream out;
      out << "\n\n";
      for (const auto c : in) {
        out << c;
        if (!(count % 40))
          out << '\n';

        ++count;
      }
      out << "----------------------------------------\n";

      return out.str();
    };

    return format(func(message));
  };

  // assert(s1 == s2);
  std::cout << A << " Alice's public key\n";
  std::cout << B << " Bill's public key\n";
  std::cout << s1 << " Alice's secret key\n";
  std::cout << s2 << " Bill's secret key\n";

  std::cout << "plaintext" << encrypt(plaintext, [](const std::string message) {
    return message;
  });

  std::cout << "rotate" << encrypt(plaintext, [](const std::string message) {
    auto ciphertext = message;
    for (auto &c : ciphertext) {
      const auto ascii_offset = 32ul;
      const auto rotate = 1ul;
      const auto wrap = 126ul - ascii_offset;
      c = ascii_offset + (c + rotate - ascii_offset) % wrap;
    }

    return ciphertext;
  });

  std::cout << "key schedule"
            << encrypt(plaintext, [](const std::string message) {
                 auto ciphertext = message;
                 for (auto &c : ciphertext) {
                   const auto ascii_offset = 32ul;
                   const auto rotate = 1ul;
                   const auto wrap = 126ul - ascii_offset;
                   static auto n = 0;
                   c = ascii_offset + (n + c + rotate - ascii_offset) % wrap;

                   ++n;
                 }

                 return ciphertext;
               });
}
