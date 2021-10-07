#include "lib.hpp"

//Point class methods
Curves::Point::Point() {
    _x = 0.0;
    _y = 0.0;
}

Curves::Point::Point(const double new_x, const double new_y) {
    _x = new_x;
    _y = new_y;
}

double Curves::Point::get_X() const {
    return _x;
}

double Curves::Point::get_Y() const {
    return _y;
}

/* Curves::Point& Curves::Point::operator=(const Curves::Point& new_point) {
    this->_x = new_point.get_X();
    this->_y = new_point.get_Y();
    return *this;
} */
 
std::ostream& Curves::operator<<(std::ostream& output, Point point) {
    output << '(' << point.get_X() << ", " << point.get_Y() << ')';
    return output;
}



//Hypocycloid class methods
Curves::Hypocycloid::Hypocycloid() {
    _r = 1.0;
    _k = 1.0;
    _d = 1.0;
}

Curves::Hypocycloid::Hypocycloid(const double new_r, const double new_k) {
    if (new_r < 0 || new_k < 0) {
        throw "values must be positive!";
    }
    _r = new_r;
    _k = new_k;
    _d = new_r;
}

Curves::Hypocycloid::Hypocycloid(const double new_r, const double new_k, const double new_d) {
    if (new_r < 0 || new_d < 0 || new_k < 0) {
        throw "values must be positive!";
    }
    _r = new_r;
    _k = new_k;
    _d = new_d;
}

double Curves::Hypocycloid::get_K() const {
    return _k;
}

double Curves::Hypocycloid::get_X(double angle) const {
    return (_r*(_k - 1.0) * cos(angle) + _d * cos(angle * (_k - 1.0)));
}

double Curves::Hypocycloid::get_Y(double angle) const {
    return (_r*(_k - 1.0) * sin(angle) - _d * sin(angle * (_k - 1.0)));
}

Curves::Point Curves::Hypocycloid::get_point(double angle) const {
    return Point(this->get_X(angle), this->get_Y(angle));
}

double Curves::Hypocycloid::get_SR() const {
    return _r;
}

double Curves::Hypocycloid::get_LR() const {
    return _r * _k;
}

Curves::Types Curves::Hypocycloid::get_type() const {
    if (_d < _r) {
        return Types::Shortened;
    } else if (_d > _r) {
        return Types::Extended;
    } else {
        return Types::Normal;
    }
}

double Curves::Hypocycloid::get_curvative_radius(double angle) const { //i didn't enjoyed doing this
    return ((_k * _r - _r) * (pow((_r * _r + _d * _d - 2 * _d * _r * cos((-1.0) * _k * angle)), 1.5)) / abs((-1.0) * _r * _r * _r + _d * _d * _r * (_k - 1.0) - _d * _r * _r * (_k - 2.0) * cos((-1.0) * _k * angle)));
}

void Curves::Hypocycloid::set_r(const double& new_r) {
    if (new_r < 0) {
        throw "Radius must be positive!";
    }
    _r = new_r;
}

void Curves::Hypocycloid::set_k(const double& new_k) {
    if (new_k < 0) {
        throw "Radiuses must be positive!";
    }
    _k = new_k;
}

void Curves::Hypocycloid::set_d(const double& new_d) {
    if (new_d < 0) {
        throw "Distance must be positive!";
    }
    _d = new_d;
}

double Curves::Hypocycloid::get_sectorial_area(double angle) const { //i really didn't enjoyed doing this
    return (_r * (_k - 1.0) / 2 * (angle * (_r * (_k - 1.0) - (_d * _d) / _r) - _d * _r * (_k - 2.0) / (_k * _r) * sin((-1) * _k * angle)));
}


//Types output
std::ostream& Curves::operator<<(std::ostream& output, Curves::Types type) {
    switch(type) {
        case Curves::Types::Normal:
            output << "normal";
            break;
        case Curves::Types::Shortened:
            output << "shortened";
            break;
        case Curves::Types::Extended:
            output << "extended";
            break;
        default:
            output << "eheheheheh...???" << std::endl;
    }
    return output;
}