#pragma once

constexpr double SALARY_MIN = 4300.0;
constexpr double TAX_REDUCE_AMOUNT() {
    return 3600.0 / 12;
};
constexpr unsigned int TAX_BASE_PERCENT = 12;
constexpr unsigned int INCOME_COSTS(bool isHigher) {
    return isHigher ? 300 : 250;
};

struct IncomeCalculatorConfig {
    double salary;
    unsigned int taxBasePercent;
    unsigned long taxIncomeThreshold;
    bool higherIncomeCosts;

    IncomeCalculatorConfig() {
        salary = SALARY_MIN;
        taxBasePercent = TAX_BASE_PERCENT;
        higherIncomeCosts = false;
    }
};

struct ZUSContributions {
    double pension;  /*<< Emerytalne */
    double annuity;  /**< Rentowe */
    double sickness; /*<< Chorobowe */

    double sum() const {
        return pension + annuity + sickness;
    }
};

struct IncomeReport {
    ZUSContributions zus;
    double healthCareContribution; /*<< Zdrowotna */
    unsigned int taxPrePayment;    /*<< Zaliczka na PIT */
    unsigned int income;           /**< Podstawa opodatkowania */
    double netSalary;              /**< Wynagrodzenie netto */
};

class IncomeCalculator {
public:
    IncomeCalculator();
    IncomeCalculator(const IncomeCalculatorConfig& incDescr);
    ~IncomeCalculator() = default;

    IncomeCalculator(const IncomeCalculator&) = delete;
    IncomeCalculator(IncomeCalculator&&) = delete;

    IncomeCalculator& operator=(const IncomeCalculator&) = delete;
    IncomeCalculator& operator=(IncomeCalculator&&) = delete;

    IncomeReport GetReport() const;

private:
    IncomeCalculatorConfig mIncomeDescr;
    ZUSContributions zusCalc() const;
    double healthCareCalc(const IncomeReport& ir) const;
    unsigned int incomeCalc(const IncomeReport& ir) const;
    unsigned int taxPrePaymentCalc(const IncomeReport& ir) const;
    double netSalaryCalc(const IncomeReport& ir) const;
};
