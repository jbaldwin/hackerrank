#include <iostream>
#include <vector>
#include <map>

struct City
{
    bool traversed = false;
    std::map<uint64_t, City*> neighbors;
};

struct Query
{
    uint64_t cities = 0;
    uint64_t roads = 0;
    uint64_t library_cost  = 0;
    uint64_t road_cost = 0;
    std::vector<City> graph;  ///<< this is the full graph key'ed by a city id.
};

auto parse_graph(Query& query) -> void;
auto calculate_cost(Query& query) -> uint64_t;
auto calculate_road_costs(uint64_t road_cost, City* city) -> uint64_t;

int main(int argc, char* argv[])
{
    size_t query_count;
    std::cin >> query_count;

    for(int i = 0; i < query_count; ++i)
    {
        Query query;
        std::cin >> query.cities >> query.roads >> query.library_cost >> query.road_cost;

        parse_graph(query);

        auto cost = calculate_cost(query);
        std::cout << cost << std::endl;
    }

    return 0;
}

auto parse_graph(Query& query) -> void
{
    // Start by creating a node for every city, this is important as
    // 'island' cities will not have connections.
    query.graph.reserve(query.cities);
    for(int city_id = 0; city_id < query.cities; ++city_id)
    {
        query.graph.push_back(City{});
    }

    for(int connection = 0; connection < query.roads; ++connection)
    {
        uint64_t city_id_1;
        uint64_t city_id_2;
        std::cin >> city_id_1 >> city_id_2;
        --city_id_1; // for proper indexing into the vector
        --city_id_2;

        // Now bi-directionally link them.
        query.graph[city_id_1].neighbors[city_id_2] = &query.graph[city_id_2];
        query.graph[city_id_2].neighbors[city_id_1] = &query.graph[city_id_1];
    }
}

auto calculate_cost(Query& query) -> uint64_t
{
    // If the road cost is greater than or equal to the library cost
    // then simply build a library in every city.
    if(query.road_cost >= query.library_cost)
    {
        return query.cities * query.library_cost;
    }

    uint64_t cost = 0;

    /**
     * Iterate over every city in the graph.  If that city has already been 'traversed'
     * then it is accounted for and can be skipped.  If a city has not been traversed
     * then it is the starting point for a new library and roads are built externally
     * outwards.
     */
    for(auto& city : query.graph)
    {
        // Ignore cities we've already traversed
        if(!city.traversed)
        {
            // This is a starting city for a library since it hasn't been traversed yet, build one.
            city.traversed = true;
            cost += query.library_cost;

            // Now traverse this cities neighbors graph and calculate road costs
            cost += calculate_road_costs(query.road_cost, &city);
        }
    }

    return cost;
}

auto calculate_road_costs(uint64_t road_cost, City* city) -> uint64_t
{
    uint64_t cost = 0;
    for(auto& neighbor_node : city->neighbors)
    {
        auto* neighbor_city = neighbor_node.second;
        if(!neighbor_city->traversed)
        {
            // Build a road to this city.
            neighbor_city->traversed = true;
            cost += road_cost;

            // Now build out the neighbors network of roads since it hasn't been traversed yet.
            cost += calculate_road_costs(road_cost, neighbor_city);
        }
    }

    return cost;
}
