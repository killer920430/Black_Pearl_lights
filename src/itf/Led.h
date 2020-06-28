#ifndef SRC_IF_LED
#define SRC_IF_LED

namespace itf
{
    class Led
    {
    public:
        virtual void write(int &) = 0;
    };
} // namespace itf
#endif /* SRC_IF_LED */
