#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
    std::string a;
    std::string b;

    std::cin >> a >> b;

    std::vector<std::vector<uint64_t>> cache;
    cache.resize(a.length() + 1);
    for(auto& child : cache)
    {
        child.resize(b.length() + 1, 0);
    }

    for(size_t a_idx = 0 ; a_idx <= a.length(); ++a_idx)
    {
        for(size_t b_idx = 0; b_idx <= b.length(); ++b_idx)
        {
            if(a_idx == 0 || b_idx == 0)
            {
                cache[a_idx][b_idx] = 0;
            }
            else if(a[a_idx - 1] == b[b_idx - 1])
            {
                cache[a_idx][b_idx] = cache[a_idx - 1][b_idx - 1] + 1;
            }
            else
            {
                cache[a_idx][b_idx] = std::max(
                    cache[a_idx - 1][b_idx],
                    cache[a_idx][b_idx - 1]
                );
            }
        }
    }

    std::cout << cache[a.length()][b.length()] << std::endl;

    return 0;
}
