#ifndef SRC_SWITCH_SWITCH
#define SRC_SWITCH_SWITCH
namespace button
{
#define SWITCH_MAX_TIME_PRESS 4
    class Button
    {
    public:
        Button(int);
        void check(void (*lp)(), void (*sp)(), void (*r)());

    private:
        unsigned int switch1Count = 0;
        int pin;
    };
} // namespace button
#endif /* SRC_SWITCH_SWITCH */
