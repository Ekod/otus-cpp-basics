#include <vector>
#include <cmath>
#include "statistics.hpp"

class Std : public IStatistics {
public:
    Std() : m_sum{0}, m_quantity{0}, m_vec{} {}

    void update(double next) override {
        m_sum += next;
        m_quantity++;
        m_vec.push_back(next);
    }

    double eval() const override {
        double std = 0;
        double mean = m_sum / m_quantity;

        for (const double &value: m_vec) {
            std += pow(value - mean, 2);
        }

        return sqrt(std / m_quantity);
    }

    const char *name() const override { return "std"; }

private:
    double m_sum;
    double m_quantity;
    std::vector<double> m_vec;
};