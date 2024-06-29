//#include <iostream>
//using namespace std;
//class Polynomial
//{
//    friend ostream& operator<<(ostream& , const Polynomial& );
//private:
//    int* coefficients;
//    int* exponents;
//    int numTerms;
//
//public:
//    Polynomial(int num, int coeff[], int exp[]) 
//    {
//        numTerms = num;
//        coefficients = new int[numTerms];
//        exponents = new int[numTerms];
//
//        for (int i = 0; i < numTerms; ++i)
//        {
//            coefficients[i] = coeff[i];
//            exponents[i] = exp[i];
//        }
//    }
//    Polynomial& operator=(const Polynomial& pol)
//    {
//        if (this != &pol)
//        {
//            delete[] coefficients;
//            delete[] exponents;
//
//            numTerms = pol.numTerms;
//            coefficients = new int[numTerms];
//            exponents = new int[numTerms];
//
//            for (int i = 0; i < numTerms; ++i)
//            {
//                coefficients[i] = pol.coefficients[i];
//                exponents[i] = pol.exponents[i];
//            }
//        }
//        return *this;
//    }
//    Polynomial(const Polynomial& pol) 
//    {
//        numTerms = pol.numTerms;
//        coefficients = new int[numTerms];
//        exponents = new int[numTerms];
//
//        for (int i = 0; i < numTerms; ++i) {
//            coefficients[i] = pol.coefficients[i];
//            exponents[i] = pol.exponents[i];
//        }
//    }
//
//    ~Polynomial() {
//        delete[] coefficients;
//        delete[] exponents;
//    }
//
//    Polynomial operator+(const Polynomial& pol) 
//    {
//        Polynomial result = *this;
//
//        for (int i = 0; i < pol.numTerms; i++)
//        {
//            bool found = false;
//            for (int j = 0; j < result.numTerms; j++)
//            {
//                if (result.exponents[j] == pol.exponents[i]) 
//                {
//                    result.coefficients[j] += pol.coefficients[i];
//                    found = true;
//                    break;
//                }
//            }
//
//            if (!found)
//            {
//                int* newCoefficients = new int[result.numTerms + 1];
//                int* newExponents = new int[result.numTerms + 1];
//                for (int j = 0; j < result.numTerms; j++)
//                {
//                    newCoefficients[j] = result.coefficients[j];
//                    newExponents[j] = result.exponents[j];
//                }
//                newCoefficients[result.numTerms] = pol.coefficients[i];
//                newExponents[result.numTerms] = pol.exponents[i];
//
//                delete[] result.coefficients;
//                delete[] result.exponents;
//                result.coefficients = newCoefficients;
//                result.exponents = newExponents;
//                result.numTerms++;
//            }
//        }
//
//        return result;
//    }
//
//    bool operator==(const Polynomial& pol)
//    {
//        if (numTerms != pol.numTerms) 
//        {
//            return false;
//        }
//        for (int i = 0; i < numTerms; i++) 
//        {
//            if (coefficients[i] != pol.coefficients[i] || exponents[i] != pol.exponents[i]) 
//            {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    bool operator!=(const Polynomial& pol)
//    {
//        return !(*this == pol);
//    }
//
//    bool operator!() const {
//        return numTerms == 1 && coefficients[0] == 0;
//    }
//
//    Polynomial operator++() 
//    {
//        for (int i = 0; i < numTerms; i++) 
//        {
//            coefficients[i]++;
//        }
//        return *this;
//    }
//
//    Polynomial operator++(int) 
//    {
//        Polynomial temp = *this;
//        for (int i = 0; i < numTerms; i++) 
//        {
//            coefficients[i]++;
//        }
//        return temp;
//    }
//    Polynomial operator+(int constant)
//    {
//        Polynomial result = *this;
//
//        for (int i = 0; i < result.numTerms; i++)
//        {
//            result.coefficients[i] += constant;
//        }
//
//        return result;
//    }
//};
//ostream& operator<<(ostream& os, const Polynomial& polynomial)
//{
//    for (int i = 0; i < polynomial.numTerms; i++)
//    {
//        if (i > 0) {
//            os << "+";
//        }
//        os << polynomial.coefficients[i];
//        if (polynomial.exponents[i] != 0) {
//            os << "x^" << polynomial.exponents[i];
//        }
//    }
//    return os;
//}
//int main() {
//    int coeff_P1[] = { 1, 2, 5 };
//    int exp_P1[] = { 4, 2, 0 };
//    int coeff_P2[] = { 4, 3 };
//    int exp_P2[] = { 6, 2 };
//    Polynomial P1(3, coeff_P1, exp_P1);
//    Polynomial P2(2, coeff_P2, exp_P2);
//
//    std::cout << "P1 = " << P1 << std::endl;
//    std::cout << "P2 = " << P2 << std::endl;
//
//    if (!P1) {
//        std::cout << "P1 is zero" << std::endl;
//    }
//
//    if (P1 != P2) {
//        std::cout << "P1 is Not Equal to P2" << std::endl;
//    }
//
//    std::cout << ++P1 << std::endl;
//    std::cout << P1 << std::endl;
//    std::cout << P1++ << std::endl;
//    std::cout << P1 << std::endl;
//
//    Polynomial P3 = P1 + P2;
//    std::cout << "P3 = " << P3 << std::endl;
//
//    P3 = P1 + 2;
//    std::cout << "P3 = " << P3 << std::endl;
//
//    return 0;
//}
