#include "platform.h"
#include "constants.h"

int main(int argc, char* argv[])
{
    Platform::init_instance("The test", WIDTH, HEIGHT);
    Platform::get_instance().run();

    Platform::destroy_instance();
    return 0;
}