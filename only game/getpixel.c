#include "getpixel.h"

SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y)
{
	SDL_Color color;
	Uint32 col = 0 ;
	if (x >= 0 && y >= 0)
	{
		char* pPosition;
		pPosition = ( char* ) pSurface->pixels ;	//determine position
		pPosition += ( pSurface->pitch * y ) ;	//offset by y
		pPosition += ( pSurface->format->BytesPerPixel * x ) ; //offset by x
		memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;	//copy pixel data
	}
	SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;	//convert color
	return ( color ) ;
}
