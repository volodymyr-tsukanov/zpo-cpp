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
        std::cerr << "Expected type is '"<<expected_type<<"'" << std::endl;
    }
};

class FileError : public Error
{
private:
    std::string path;

public:
    FileError(std::string _path) : path(_path) {}

    void error() override {
        std::cerr << "File: "<<path<<" failed to open" << std::endl;
    }
};

class ProgressError : public Error
{
private:
    int prg;
    std::string msg;

public:
    ProgressError(int _progress, std::string _msg) : prg(_progress), msg(_msg) {}

    void error() override {
        std::cerr << prg<<" ~ "<<msg << std::endl;
    }
};

#endif // ERROR_H
