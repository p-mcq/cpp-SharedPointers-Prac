#include "I_Printable.h"

std::ostream &operator<<(std::ostream &os, const I_Printable &obj)
{
    obj.print(os);
    return os;
}

void print(std::ostream &os)
{
    os << "I_Printable object";
}