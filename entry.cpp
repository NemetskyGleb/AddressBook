#include "entry.h"


QString Entry::fullname() const
{
    return secondName + ' ' + firstName + ' ' + thirdName;
}
