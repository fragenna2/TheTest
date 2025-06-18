#include "main.h"
#include "assets.h"

int main(int argc, char* argv[])
{
    Platform* platform = new Platform("The game", WIDTH, HEIGHT);
    platform->initAndRun();

    delete platform;
    return 0;
}