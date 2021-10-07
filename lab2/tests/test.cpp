#include <gtest/gtest.h>
#include <iostream>

#include "lib.hpp"

TEST(PointMethodsTests, GetXGetYTest) {
    Curves::Point point(2.0, -4.0);
    EXPECT_DOUBLE_EQ(2.0, point.get_X());
    EXPECT_DOUBLE_EQ(-4.0, point.get_Y());
}

TEST(HypocycloidMethodsTests, GetKGetSRGetLRGetTypeTest) {
    Curves::Hypocycloid hypocycloid(3.0, 4.0, 5.0);
    EXPECT_DOUBLE_EQ(3.0, hypocycloid.get_SR());
    EXPECT_DOUBLE_EQ(4.0, hypocycloid.get_K());
    EXPECT_DOUBLE_EQ(12.0, hypocycloid.get_LR());
    EXPECT_EQ(Curves::Types::Extended, hypocycloid.get_type());
}

TEST(HypocycloidMethodsTests, GetPointGetCurveRadiusGetAreaTest) {
    Curves::Hypocycloid hypocycloid(3.0, 4.0, 5.0);
    double angle = 5.0;
    EXPECT_NEAR(25.27063, hypocycloid.get_sectorial_area(angle), 0.001);
    std::cout << hypocycloid.get_sectorial_area(angle) << std::endl;
    EXPECT_NEAR(5.66365, hypocycloid.get_curvative_radius(angle), 0.01);  
    std::cout << hypocycloid.get_curvative_radius(angle) << std::endl;
    Curves::Point point(-1.24548, -11.88176);
    EXPECT_NEAR(point.get_X(), hypocycloid.get_X(angle), 0.001);
    EXPECT_NEAR(point.get_Y(), hypocycloid.get_Y(angle), 0.001);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}