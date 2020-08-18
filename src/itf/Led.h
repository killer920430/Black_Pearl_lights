#ifndef SRC_IF_LED
#define SRC_IF_LED
#include "stdint.h"

namespace itf
{
    class Led
    {
    public:
        virtual void write(const uint8_t &) = 0;
    };
} // namespace itf
#endif /* SRC_IF_LED */
