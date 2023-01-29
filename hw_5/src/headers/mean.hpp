#include "statistics.hpp"

class Mean : public IStatistics {
public:
    Mean() : m_sum{0}, m_quantity{0} {}

    void update(double next) override {
        m_sum += next;
        m_quantity++;
    }

    double eval() const override { return m_sum / m_quantity; }

    const char *name() const override { return "mean"; }

private:
    double m_sum;
    double m_quantity;
};