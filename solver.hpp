#pragma once

#include <string>
#include <complex>

namespace solver {
    class RealVariable {
    public:
        double value;
        RealVariable();
        RealVariable(double);
        RealVariable operator-(RealVariable);
        RealVariable operator-(double);
        RealVariable operator+(RealVariable);
        RealVariable operator+(double);
        RealVariable operator*(RealVariable);
        RealVariable operator*(double);
        RealVariable operator/(RealVariable);
        RealVariable operator/(double);
        RealVariable operator^(RealVariable);
        RealVariable operator^(double);
        RealVariable operator==(RealVariable);
        RealVariable operator==(double);
    };
    class ComplexVariable {
    public:
        std::complex<double> value;
        ComplexVariable();
        ComplexVariable(std::complex<double>);
        ComplexVariable operator-(ComplexVariable);
        ComplexVariable operator-(double);
        ComplexVariable operator+(ComplexVariable);
        ComplexVariable operator+(double);
        ComplexVariable operator*(ComplexVariable);
        ComplexVariable operator*(double);
        ComplexVariable operator/(ComplexVariable);
        ComplexVariable operator/(double);
        ComplexVariable operator^(ComplexVariable);
        ComplexVariable operator^(double);
        ComplexVariable operator==(ComplexVariable);
        ComplexVariable operator==(double);
    };
    RealVariable operator*(double ,const RealVariable & );
    RealVariable operator+(double ,const RealVariable & );
    RealVariable operator-(double ,const RealVariable & );
    RealVariable operator==(double ,const RealVariable & );

    ComplexVariable operator==(double ,const ComplexVariable & );
    ComplexVariable operator*(double ,const ComplexVariable & );
    ComplexVariable operator+(double ,const ComplexVariable & );
    ComplexVariable operator-(double ,const ComplexVariable & );
	double solve(RealVariable);
    std::complex<double> solve(ComplexVariable);

}
