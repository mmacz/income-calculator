#include "IncomeCalculator.hxx"
#include "IncomeCalculatorFixture.hxx"

constexpr IncomeReport MinimalIncomeReport() {
    return {{419.68, 64.50, 105.35}, 333.94, 115, 3460, 3261.53};
};

TEST(Salary, Minimal) {
    IncomeCalculator ic;
    auto ir = ic.GetReport();
    auto ref = MinimalIncomeReport();
    ASSERT_NEAR(ir.zus.pension, ref.zus.pension, 0.01);
    ASSERT_NEAR(ir.zus.annuity, ref.zus.annuity, 0.01);
    ASSERT_NEAR(ir.zus.sickness, ref.zus.sickness, 0.01);
    ASSERT_NEAR(ir.healthCareContribution, ref.healthCareContribution, 0.01);
    ASSERT_EQ(ir.income, ref.income);
    ASSERT_NEAR(ir.netSalary, ref.netSalary, 0.01);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
