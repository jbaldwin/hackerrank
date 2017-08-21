#include <iostream>
#include <vector>
#include <cmath>

struct Sieve {
    uint64_t num;
    std::vector<uint64_t> primes;
};

Sieve prime_sieve(uint64_t limit)
{
    uint64_t sievebound = (limit - 1) / 2;
    char sieve[sievebound];
    uint64_t crosslimit = floor(sqrt(sievebound));
    for(uint64_t i = 1; i < sievebound; i++)
    {
        sieve[i] = 1;
    }

    for(uint64_t i = 1; i < crosslimit; i++)
    {
        if(sieve[i])
        {
            for(uint64_t j = 2 * i * (i + 1); j < sievebound; j += 2 * i + 1)
            {
                sieve[j] = 0;
            }
        }
    }

    uint64_t num = 1;
    for(uint64_t i = 1; i < sievebound; i++)
    {
        if(sieve[i])
        {
            num++;
        }
    }

    Sieve result;
    result.num = num;
    result.primes = std::vector<uint64_t>(num, 0);

    result.primes[0] = 2;
    int p = 1;
    for(uint64_t i = 1; i < sievebound; i++) {
        if(sieve[i]) {
            result.primes[p] = 2 * i + 1;
            p++;
        }
    }

    return result;
}

int main(int argc, char* argv[])
{
    uint64_t game_count;
    std:: cin >> game_count;

    for(uint64_t game = 0; game < game_count; ++game)
    {
        uint64_t n;
        std::cin >> n;

        if(n == 1)
        {
            std::cout << "Bob" << std::endl;
            continue;
        }
        if(n == 2)
        {
            std::cout << "Alice" << std::endl;
            continue;
        }

        auto sieve = prime_sieve(n + 2);
        if(sieve.num % 2 == 1)
        {
            std::cout << "Alice" << std::endl;
        }
        else
        {
            std::cout << "Bob" << std::endl;
        }
    }

    return 0;
}
