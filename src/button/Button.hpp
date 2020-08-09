#ifndef SRC_SWITCH_SWITCH
#define SRC_SWITCH_SWITCH
namespace button
{
#define SWITCH_MAX_TIME_PRESS 4
    class Button
    {
    public:
        Button(int, void (*longPress)(), void (*shortPress)(), void (*release)(), int maxCountPress = 4);
        void check();

    private:
        int pin;
        void (*longPress)();
        void (*shortPress)();
        void (*release)();
        unsigned int maxCountPress = 4;
        unsigned int count = 0;
    };
} // namespace button
#endif /* SRC_SWITCH_SWITCH */
