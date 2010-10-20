#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <string.h>
#include "SDL/SDL_image.h"

SDL_Surface *Load_Image (char *filename)
{
    SDL_Surface *Loaded_Image=NULL;
    SDL_Surface *Optimized_Image=NULL;
    Loaded_Image = IMG_Load (filename);
    if (Loaded_Image != NULL)
    {
        Optimized_Image = SDL_DisplayFormat (Loaded_Image);
        SDL_FreeSurface (Loaded_Image);
        if (Optimized_Image != NULL)
        {
            Uint32 colorkey = SDL_MapRGB (Optimized_Image->format, 0xFF, 0xFF, 0xFF);
            SDL_SetColorKey (Optimized_Image, SDL_SRCCOLORKEY, colorkey);
        }
    }
    return Optimized_Image;
}


SDL_Event event;

Uint32 callback ( Uint32 interval, void*p)
{
 *(int*)p=0;
 return 0;
}

int main( int argc, char *args [])
{
    int quite = 0;
    int shoulderx=36/2, shouldery=65,x,y,press,length,height,score=0;
    struct cloth {SDL_Surface*picture,SDL_Rect rect, int flag};
    SDL_Surface* screen = NULL;
    SDL_Surface* background = NULL;
    SDL_Surface* dita = NULL;
    struct cloth dress,blackshoes,whitecoat,bag,forcoat,fordress,forshoes,forbags,forshoestxt,forovercoatstxt,fordressestxt,forbagstxt;
    int nenuzhnaya=1;

    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Rect offset;

    screen = SDL_SetVideoMode( 1024, 700, 16, SDL_SWSURFACE );

    SDL_AddTimer(7000,callback, &nenuzhnaya);
    background = IMG_Load("background1.jpg");
    dress.picture = Load_Image ("dress.png");
    dress.flag=1;
    blackshoes = Load_Image ("blackshoes.png");
    dita = Load_Image("dita.png");
    whitecoat = Load_Image("whitecoat.png");
    bag= Load_Image("bag.png");
    forcoat= IMG_Load ("forcoat1.png");
    fordress= IMG_Load ("fordress.png");
    forshoes= Load_Image("forshoes.png");
    forbags= Load_Image("forbags.png");
    forshoestxt= Load_Image("forshoestxt.png");
    forovercoatstxt= Load_Image("forovercoatstxt.png");
    fordressestxt= Load_Image("fordressestxt.png");
    forbagstxt= Load_Image("forbagstxt.png");



    offset.x = 1024/2-dita->w/2;
    offset.y = 700/2-dita->h/2;
    dress.rect.x = (1024/2-dita->w/2)+ shoulderx;
    dress.rect.y = (700/2-dita->h/2)+ shouldery;
    offset3.x = 1024/2-blackshoes->w/2-10;
    offset3.y = 1024/2-15;
    offset4.x = (1024/2-dita->w/2)+ shoulderx-14;
    offset4.y = (700/2-dita->h/2)+ shouldery-20;
    offset5.x = (1024/2-dita->w/2)+ 5.3*shoulderx;
    offset5.y = (700/2-dita->h/2)+ 3*shouldery;
    offset6.x = 1024/16;
    offset6.y = 700/12;
    offset7.x = 3000/4;
    offset7.y = 700/14;
    offset8.x= 1024/16;
    offset8.y= 2000/5;
    offset9.x= 3000/4;
    offset9.y= 800/2;



    while (quite == 0)
    {
        while( SDL_PollEvent( &event ) )
        {
            if( event.type == SDL_QUIT )
            {
                quite = 1;
            }

        }
    SDL_BlitSurface( background, NULL, screen, NULL );
    SDL_BlitSurface (dita, NULL, screen, &offset);
    SDL_BlitSurface (dress, NULL, screen, &offset2);
    SDL_BlitSurface (blackshoes, NULL, screen, &offset3);
    SDL_BlitSurface (whitecoat, NULL, screen, &offset4);
    SDL_BlitSurface (bag, NULL, screen, &offset5);
    SDL_BlitSurface (forcoat, NULL, screen, &offset6);
    SDL_BlitSurface (fordress, NULL, screen, &offset7);
    SDL_BlitSurface (forshoes, NULL, screen, &offset8);
    SDL_BlitSurface (forbags, NULL, screen, &offset9);

    if ( nenuzhnaya)
    {
    SDL_BlitSurface (forshoestxt, NULL, screen, &offset8);
    SDL_BlitSurface (forovercoatstxt, NULL, screen, &offset6);
    SDL_BlitSurface (fordressestxt, NULL, screen, &offset7);
    SDL_BlitSurface (forbagstxt, NULL, screen, &offset9);
    }
    SDL_Flip( screen );
    }

    if( event.button.button == SDL_BUTTON_LEFT )
    {x = event.button.x;
     y = event.button.y;
     length=offset9.x + whitecoat->w;
     height=offset9.y + whitecoat->h;
     if (x>offset9.x && x<(length) && y>offset9.y && y<(height))
      press=1;
    }
    if(press)
    {if( event.button.button == SDL_BUTTON_LEFT )
     {x = event.button.x;
     y = event.button.y;
     length=offset6.x + forcoat->w;
     height=offset6.y + forcoat->h;
     }
     if (x>offset6.x && x<(length) && y>offset6.y && y<(height))
     score=score+10;


    }



    return 0;
}
