#include "Base.hpp"

int main()
{
    Base  base;
    Base* another = base.generate();
    base.identify(another);
    base.identify(*another);
    return 0;
}
