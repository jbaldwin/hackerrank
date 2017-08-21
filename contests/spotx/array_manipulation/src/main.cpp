#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    // add a value k to elements ranging from index {a to b} inclusive.
    // the input indices starts at 1 (not zero)

    uint64_t n = 0;
    uint64_t operations = 0;
    std::cin >> n >> operations;

    std::vector<uint64_t> totals(n + 2, 0);

    for(uint64_t i = 0; i < operations; ++i)
    {
        uint64_t a;
        uint64_t b;
        uint64_t k;
        std::cin >> a >> b >> k;

        totals[a] += k;
        totals[b + 1] -= k;
    }

    uint64_t current = 0;
    uint64_t max = 0;
    for(uint64_t i = 1; i <= n; ++i)
    {
        if(totals[i] != 0)
        {
            current += totals[i];
            max = std::max(max, current);
        }
    }

    std::cout << max << std::endl;

    return 0;
}
