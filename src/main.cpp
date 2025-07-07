#include "platform.h"
#include "constants.h"

int main(int argc, char* argv[])
{
    Platform platform("The game", WIDTH, HEIGHT);
    platform.run();

    return 0;
}