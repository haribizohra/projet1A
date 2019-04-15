#include "getpixel.h"


SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y)
{
    SDL_Color color;
    Uint32 col = 0 ;
    if (x >= 0 && y >= 0)
    {
        //determine position
        char* pPosition = ( char* ) pSurface->pixels ;
        //offset by y
        pPosition += ( pSurface->pitch * y ) ;
        //offset by x
        pPosition += ( pSurface->format->BytesPerPixel * x ) ;
        //copy pixel data
        memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;
        //convert color
    }
    SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
    return ( color ) ;
}

