#include "solver.hpp"

#include <string>
#include <complex>

namespace solver {
    RealVariable::RealVariable(){
        value = 0;
        a = 0;
        b = 0;
        c = 0;
        leftside = TRUE;
    };
    RealVariable RealVariable::operator-(RealVariable sec){
        RealVariable newVariable();
        if (!this->leftside) {
            newVariable.a = this->a + sec->a;
            newVariable.b = this->b + sec->b;
            newVariable.c = this->c + sec->c;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a - sec->a;
        newVariable.b = this->b - sec->b;
        newVariable.c = this->c - sec->c;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator-(double sec){
        RealVariable newVariable();
        if (!this->leftside) {
            newVariable.a = this->a;
            newVariable.b = this->b;
            newVariable.c = this->c + sec;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c - sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator+(RealVariable sec){
        RealVariable newVariable();
        if (!this->leftside) {
            newVariable.a = this->a - sec->a;
            newVariable.b = this->b - sec->b;
            newVariable.c = this->c - sec->c;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a + sec->a;
        newVariable.b = this->b + sec->b;
        newVariable.c = this->c + sec->c;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator+(double sec){
        RealVariable newVariable();
        if (!this->leftside) {
            newVariable.a = this->a;
            newVariable.b = this->b;
            newVariable.c = this->c - sec;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c + sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    RealVariable RealVariable::operator*(RealVariable sec){
        RealVariable newVariable();
        newVariable.a = this->a*sec->c + this->b*sec->b + this->c*sec->a;
        newVariable.b = this->b*sec->c + this->c*sec->b;
        newVariable.c = this->c*sec->c;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator*(double sec){
        RealVariable newVariable();
        newVariable.a = this->a*sec;
        newVariable.b = this->b*sec;
        newVariable.c = this->c*sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
//need to think
    // RealVariable RealVariable::operator/(RealVariable sec){
    //     this->a = this->a*sec->c + this->b*sec->b + this->c*sec->a;
    //     this->b = this->b*sec->c + this->c*sec->b;
    //     this->c = this->c*sec->c;
    //     return this;
    // };
    RealVariable RealVariable::operator/(double sec){
        RealVariable newVariable();
        newVariable.a = this->a/sec;
        newVariable.b = this->b/sec;
        newVariable.c = this->c/sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    RealVariable RealVariable::operator/(RealVariable){};


    RealVariable RealVariable::operator^(int sec){
        RealVariable newVariable();
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c;
        newVariable.leftside = this->leftside;
        if (sec>2 || sec<0) {
            throw std::exception();
        }
        if (sec == 0) {
            newVariable.a = 0;
            newVariable.b = 0;
            newVariable.c = 1;
            return newVariable;
        }
        if (sec == 1) {
            return newVariable;
        }
        if (this->a != 0) {
            throw std::exception();
        }
        newVariable.a = this->b*this->b;
        newVariable.b = 2*this->b*this->c;
        newVariable.c = this->c*this->c;
        return newVariable;
    };
    RealVariable RealVariable::operator==(RealVariable){
        this->leftside = false;
        return this;
    };
    RealVariable RealVariable::operator==(double){
        this->leftside = false;
        return this;
    };

    ComplexVariable::ComplexVariable(){};
    ComplexVariable ComplexVariable::operator-(ComplexVariable){};
    ComplexVariable ComplexVariable::operator-(std::complex<double> ){};
    ComplexVariable ComplexVariable::operator+(ComplexVariable){};
    ComplexVariable ComplexVariable::operator+(std::complex<double> ){};
    ComplexVariable ComplexVariable::operator*(ComplexVariable){};
    ComplexVariable ComplexVariable::operator*(std::complex<double> ){};
    ComplexVariable ComplexVariable::operator/(ComplexVariable){};
    ComplexVariable ComplexVariable::operator/(std::complex<double> ){};
    ComplexVariable ComplexVariable::operator^(ComplexVariable){};
    ComplexVariable ComplexVariable::operator^(std::complex<double> ){};
    ComplexVariable ComplexVariable::operator==(ComplexVariable){};
    ComplexVariable ComplexVariable::operator==(std::complex<double> ){};
    double solve(solver::RealVariable){};
    std::complex<double> solve(solver::ComplexVariable){};

    RealVariable operator * (double sec ,const RealVariable & first){
        return first*sec;
    };
    RealVariable operator + (double sec,const RealVariable & first){
        if (!first.leftside) {
            first.a = -first.a;
            first.b = -first.b;
            first.c = -first.c - sec;
            return first
        }
        first.c = first.c + sec;
        return first
    };
    RealVariable operator - (double sec,const RealVariable & first){
        first.a = -first.a;
        first.b = -first.b;
        if (!first.leftside) {
            first.c = first.c - sec;
            return first
        }
        first.c = sec - first.c ;
        return first
    };
    RealVariable operator==(double ,const RealVariable & ){};

    ComplexVariable operator==(std::complex<double>  ,const ComplexVariable & ){};
    ComplexVariable operator * (std::complex<double>  ,const ComplexVariable & ){};
    ComplexVariable operator + (std::complex<double>  ,const ComplexVariable & ){};
    ComplexVariable operator - (std::complex<double>  ,const ComplexVariable & ){};

};
