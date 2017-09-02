#include <iostream>
#include <string>
#include <algorithm>

constexpr uint64_t modulus = 1'000'000'007;

auto char_2_int(char c) -> uint64_t
{
    return c - '0';
}

int main(int argc, char* argv[])
{
    std::string string_numbers;
    std::cin >> string_numbers;

    uint64_t base  = 0;
    uint64_t state = 0;
    uint64_t total = 0;

    std::reverse(std::begin(string_numbers), std::end(string_numbers));

    for(auto letter : string_numbers)
    {
        base = (base * 10 + 1) % modulus;

        state += char_2_int(letter) * base;

        total += state;
        total %= modulus;
    }

    std::cout << total << std::endl;

    return 0;
}
