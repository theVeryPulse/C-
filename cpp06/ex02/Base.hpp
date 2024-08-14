#pragma once
#ifndef BASE_HPP
#define BASE_HPP

class A;
class B;
class C;

class Base
{
  public:
    enum Type
    {
        Undefined,
        BaseType,
        AType,
        BType,
        CType
    };
    Base* generate();
    void  identify(Base* ptr);
    void  identify(Base& ref);

    virtual Type type();
};

#endif /* BASE_HPP */