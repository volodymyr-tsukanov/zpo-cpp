#ifndef ERROR_H
#define ERROR_H
#include <iostream>


class Error
{
public:
    virtual ~Error(){};

    virtual void error()=0;
};


class TypeMissmatchError : public Error
{
private:
    std::string expected_type;

public:
    TypeMissmatchError(std::string _expected):expected_type(_expected){}

    void error() override {
        std::cout << "Expected type is '"<<expected_type<<"'" << std::endl;
    }
};

class WrongArgError : public Error
{
public:
    void error() override {
        std::cout << "Expected int > 0" << std::endl;
    }
};

class ArgOverflowError : public Error
{
public:
    void error() override {
        std::cout << "Over 21! try <" << std::endl;
    }
};

#endif // ERROR_H
