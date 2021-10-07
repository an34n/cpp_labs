#pragma once //please do not write me about usage of this thing, i'm sure there are problems much worse here

#include <iostream>
#include <cmath>

#define PI = 3.14159265358979323846;

namespace Curves {
    enum class Types {Normal, Shortened, Extended};
    std::ostream& operator<<(std::ostream& output, Curves::Types type);

    class Point {
        private:
            double _x;
            double _y;
        public:
            Point();
            Point(double new_x, double new_y);

            double get_X() const;
            double get_Y() const;

            //Point& operator=(const Point& new_point);
            

    };
    std::ostream& operator<<(std::ostream& output, Point point);

    class Hypocycloid {
        private:
            double _r;
            double _k;
            double _d;
        public:
            Hypocycloid();
            Hypocycloid(const double new_r, const double new_k);
            Hypocycloid(const double new_r, const double new_k, const double new_d);

            double get_K() const;
            double get_X(double angle) const;
            double get_Y(double angle) const;
            Point get_point(double angle) const;
            double get_SR() const; //get smaller radius
            double get_LR() const; //get larger radius
            Types get_type() const;
            double get_curvative_radius(double angle) const;
            double get_sectorial_area(double angle) const;

            void set_r(const double& new_r);
            void set_k(const double& new_k);
            void set_d(const double& new_d);
    };
}

//like how do you actually come up with appropriate names for classes and such?