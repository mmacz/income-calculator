#include "IncomeCalculator.hxx"

IncomeCalculator::IncomeCalculator()
    : mIncomeDescr() {
}

IncomeCalculator::IncomeCalculator(const IncomeCalculatorConfig& incDescr)
    : mIncomeDescr(incDescr) {
}

ZUSContributions IncomeCalculator::zusCalc() const {
    ZUSContributions zc;
    zc.pension = (9.76 * mIncomeDescr.salary) / 100;
    zc.annuity = (1.5 * mIncomeDescr.salary) / 100;
    zc.sickness = (2.45 * mIncomeDescr.salary) / 100;
    return zc;
}

double IncomeCalculator::healthCareCalc(const IncomeReport& ir) const {
    return (9 * (mIncomeDescr.salary - ir.zus.sum())) / 100;
}

unsigned int IncomeCalculator::incomeCalc(const IncomeReport& ir) const {
    return static_cast<unsigned int>(mIncomeDescr.salary - ir.zus.sum() - INCOME_COSTS(mIncomeDescr.higherIncomeCosts));
}

unsigned int IncomeCalculator::taxPrePaymentCalc(const IncomeReport& ir) const {
    return static_cast<unsigned int>((ir.income * mIncomeDescr.taxBasePercent) / 100.f - TAX_REDUCE_AMOUNT());
}

double IncomeCalculator::netSalaryCalc(const IncomeReport& ir) const {
    return mIncomeDescr.salary - ir.zus.sum() - ir.healthCareContribution - ir.taxPrePayment;
}

IncomeReport IncomeCalculator::GetReport() const {
    IncomeReport ir;
    ir.zus = zusCalc();
    ir.healthCareContribution = healthCareCalc(ir);
    ir.income = incomeCalc(ir);
    ir.taxPrePayment = taxPrePaymentCalc(ir);
    ir.netSalary = netSalaryCalc(ir);
    return ir;
}
