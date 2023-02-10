#include <iostream>
#include "statistics.hpp"
#include "min.hpp"
#include "std.hpp"
#include "mean.hpp"
#include "max.hpp"

int main() {

    const size_t statistics_count = 4;
    IStatistics *statistics[statistics_count];

    statistics[0] = new Min{};
    statistics[1] = new Max{};
    statistics[2] = new Mean{};
    statistics[3] = new Std{};

    double val = 0;
    while (std::cin >> val) {
        for (IStatistics *statistic: statistics) {
            statistic->update(val);
        }
    }

    // Handle invalid input data
    if (!std::cin.eof() && !std::cin.good()) {
        std::cerr << "Invalid input data\n";
        return 1;
    }

    // Print results if any
    for (IStatistics *statistic: statistics) {
        std::cout << statistic->name() << " = " << statistic->eval() << std::endl;
    }

    // Clear memory - delete all objects created by new
    for (IStatistics *statistic: statistics) {
        delete statistic;
    }

    return 0;
}