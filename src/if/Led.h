#ifndef SRC_IF_LED
#define SRC_IF_LED
class Led
{
    virtual void init() = 0;
    virtual void write(int &) = 0;
};
#endif /* SRC_IF_LED */
