#pragma once

/*  
    This header file allow to include automatically
    the SDL_image image depending on the platform you are
    working with, due to the different ways the library usage is 
    beetween windows and linux
*/

#ifdef __linux__
    #include <SDL2/SDL_image.h>
#else
    #include <SDL_image.h>
#endif