#include <iostream>
#include <vector>
#include <set>

enum class State
{
    GOOD,
    BAD
};

struct Point
{
    static size_t X_LEN;

    size_t x = 0;
    size_t y = 0;

    Point(size_t _x, size_t _y) : x(_x), y(_y)
    {

    }

    auto operator<(const Point& other) const -> bool
    {
        return (x * X_LEN + y < other.x * X_LEN + other.y);
    }

    auto operator==(const Point& other) const -> bool
    {
        return x == other.x && y == other.y;
    }
};

size_t Point::X_LEN = 0;

struct Plus
{
    size_t x;
    size_t y;
    size_t area = 0;
    size_t distance = 0;
    std::set<Point> points;

    auto operator==(const Plus& other) -> bool
    {
        return x == other.x && y == other.y;
    }
};

using GridState = std::vector<std::vector<State>>;
using GridPluses = std::vector<std::vector<Plus>>;

/**
 * Is {x, y} point with distance +/- in all 4 directions in the {n, m} grid boundary?
 */
inline auto in_bounds(
    size_t n,
    size_t m,
    ssize_t x,
    ssize_t y,
    ssize_t distance
) -> bool
{
    if(
           x - distance >= 0
        && x + distance < n
        && y - distance >= 0
        && y + distance < m
    )
    {
        return true;
    }
    return false;
}

/**
 *  Is {x, y} point with distance +/- in all 4 directions have a good state?
 */
inline auto plus_can_grow(
    const GridState& grid_state,
    ssize_t x,
    ssize_t y,
    ssize_t distance
) -> bool
{
    // assume in bounds
    if(
           grid_state[x + distance][y] == State::GOOD
        && grid_state[x][y + distance] == State::GOOD
        && grid_state[x - distance][y] == State::GOOD
        && grid_state[x][y - distance] == State::GOOD
    )
    {
        return true;
    }

    return false;
}

auto search(
    const GridState& grid_state,
    GridPluses& grid_pluses
) -> void
{
    size_t n = grid_state.size();
    size_t m = grid_state[0].size();

    Point::X_LEN = n;

    for(ssize_t x = 0; x < n; ++x)
    {
        for(ssize_t y = 0; y < m; ++y)
        {
            auto& state = grid_state[x][y];
            auto& plus = grid_pluses[x][y];

            if(state == State::BAD)
            {
                // Nothing to do on a bad state
//                std::cout << x << "," << y << " BAD" << std::endl;
                continue;
            }

            // +1 size if the state is good
            plus.area = 1;
            plus.points.emplace(Point(plus.x, plus.y));

            // Iterate outwards from the central point adding
            // 4 to the size each time the plus size can grow.
            // Stop either at the grid boundary or a bad state is found.
            ssize_t distance = 1;
            while(
                   in_bounds(n, m, x, y, distance)
                && plus_can_grow(grid_state, x, y, distance)
            )
            {
                plus.points.emplace(x + distance, y);
                plus.points.emplace(x - distance, y);
                plus.points.emplace(x, y + distance);
                plus.points.emplace(x, y - distance);

                // Add four to the size and try again with +1 distance
                plus.area += 4;
                plus.distance = distance;
                ++distance;
            }

//            std::cout << x << "," << y << " " << plus.area << std::endl;
        }
    }
}

auto print_grid_state(const GridState& grid_state)
{
    for(auto& row : grid_state)
    {
        for(auto state : row)
        {
            auto c = (state == State::GOOD) ? 'G' : 'B';
            std::cout << c;
        }

        std::cout << std::endl;
    }
}

auto shrink_plus(Plus& plus) -> void
{
    if(plus.area == 1)
    {
        plus.area = 0;
        plus.distance = 0;
        plus.points.clear();
        return;
    }
    else
    {
        auto it = plus.points.find(Point(plus.x + plus.distance, plus.y));
        plus.points.erase(it);
        it = plus.points.find(Point(plus.x - plus.distance, plus.y));
        plus.points.erase(it);
        it = plus.points.find(Point(plus.x, plus.y + plus.distance));
        plus.points.erase(it);
        it = plus.points.find(Point(plus.x, plus.y - plus.distance));
        plus.points.erase(it);

        plus.area -= 4;
        --plus.distance;
    }
}

int main(int argc, char* argv[])
{
    uint64_t n_size;
    uint64_t m_size;
    std::cin >> n_size >> m_size;

    GridState grid_state;
    GridPluses grid_pluses;
    grid_state.resize(n_size);
    grid_pluses.resize(n_size);

    for(auto& row : grid_state)
    {
        row.resize(m_size);
    }
    for(auto& row : grid_pluses)
    {
        row.resize(m_size);
    }

    // Read each M value across and then each N value down
    for(size_t n = 0; n < n_size; ++n)
    {
        for(size_t m = 0; m < m_size; m++)
        {
            char c;
            std::cin >> c;
            grid_state[n][m] = (c == 'G') ? State::GOOD : State::BAD;

            grid_pluses[n][m].x = n;
            grid_pluses[n][m].y = m;
        }
    }

//    print_grid_state(grid_state);

    search(grid_state, grid_pluses);

    size_t product = 0;
    for(auto& row : grid_pluses)
    {
        for(auto& plus : row)
        {
            // Skip bad cells
            if(plus.area == 0)
            {
                continue;
            }

            Plus shrink = plus;
            while(shrink.area != 0)
            {
                for(auto& row2 : grid_pluses)
                {
                    for(auto& plus2 : row2)
                    {
                        if(plus2.area == 0)
                        {
                            continue;
                        }

                        if(plus == plus2)
                        {
                            continue;
                        }

                        Plus shrink2 = plus2;
                        while(shrink2.area != 0)
                        {
                            bool overlap = false;
                            for(auto& p : shrink.points)
                            {
                                auto found = shrink2.points.find(p);
                                if(found != shrink2.points.end())
                                {
                                    overlap = true;
                                    break;
                                }
                            }

                            if(overlap)
                            {
                                shrink_plus(shrink2);
                            }
                            else
                            {
                                product = std::max(product, shrink.area * shrink2.area);
                                break;
                            }
                        }
                    }
                }
                shrink_plus(shrink);
            }
        }
    }


    std::cout << product << std::endl;

    return 0;
}
