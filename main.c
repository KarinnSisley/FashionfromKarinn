#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <string.h>
#include "SDL/SDL_image.h"

struct cloth
{
    SDL_Surface*picture;
    SDL_Rect offset;
    int flag;
};
void blitcloth( struct cloth*c, SDL_Surface * dest)
{
    if (c->flag)
        SDL_BlitSurface (c->picture, NULL, dest, &c->offset);

}

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
    int shoulderx=36/2, shouldery=65,x,y,length,height,score=0;

    SDL_Surface* screen = NULL;
    SDL_Surface* background = NULL;
    struct cloth dita,dress,blackshoes,whitecoat,bag,forcoat,fordress,forshoes,forbags,forshoestxt,forovercoatstxt,fordressestxt,forbagstxt;
    int nenuzhnaya=1;
    struct cloth *cloth_selected=NULL;

    SDL_Init( SDL_INIT_EVERYTHING );

    screen = SDL_SetVideoMode( 1024, 700, 16, SDL_SWSURFACE );

    SDL_AddTimer(7000,callback, &nenuzhnaya);
    background = IMG_Load("background1.jpg");
    dita.picture = Load_Image("dita.png");
    dita.flag=1;
    dress.picture = Load_Image ("dress.png");
    dress.flag=1;
    blackshoes.picture = Load_Image ("blackshoes.png");
    blackshoes.flag=1;
    whitecoat.picture = Load_Image("whitecoat.png");
    whitecoat.flag=1;
    bag.picture= Load_Image("bag.png");
    bag.flag=1;
    forcoat.picture= IMG_Load ("forcoat1.png");
    forcoat.flag=1;
    fordress.picture= IMG_Load ("fordress.png");
    fordress.flag=1;
    forshoes.picture= Load_Image("forshoes.png");
    forshoes.flag=1;
    forbags.picture= Load_Image("forbags.png");
    forbags.flag=1;
    forshoestxt.picture= Load_Image("forshoestxt.png");
    forshoestxt.flag=1;
    forovercoatstxt.picture= Load_Image("forovercoatstxt.png");
    forovercoatstxt.flag=1;
    fordressestxt.picture= Load_Image("fordressestxt.png");
    fordressestxt.flag=1;
    forbagstxt.picture= Load_Image("forbagstxt.png");
    forbagstxt.flag=1;



    dita.offset.x = 1024/2-dita.picture->w/2;
    dita.offset.y = 700/2-dita.picture->h/2;
    dress.offset.x = (1024/2-dita.picture->w/2)+ shoulderx;
    dress.offset.y = (700/2-dita.picture->h/2)+ shouldery;
    blackshoes.offset.x = 1024/2-blackshoes.picture->w/2-10;
    blackshoes.offset.y = 1024/2-15;
    whitecoat.offset.x = (1024/2-dita.picture->w/2)+ shoulderx-14;
    whitecoat.offset.y = (700/2-dita.picture->h/2)+ shouldery-20;
    bag.offset.x = (1024/2-dita.picture->w/2)+ 5.3*shoulderx;
    bag.offset.y = (700/2-dita.picture->h/2)+ 3*shouldery;
    forcoat.offset.x = 1024/16;
    forcoat.offset.y = 700/12;
    fordress.offset.x = 3000/4;
    fordress.offset.y = 700/14;
    forshoes.offset.x= 1024/16;
    forshoes.offset.y=800/2;
    forbags.offset.x= 3000/4;
    forbags.offset.y= 800/2;
    forshoestxt.offset.x=1024/18;
    forshoestxt.offset.y=430;
    forovercoatstxt.offset.x=1024/16;
    forovercoatstxt.offset.y=700/9;
    fordressestxt.offset.x=3000/4;
    fordressestxt.offset.y= 22;
    forbagstxt.offset.x= 3000/4;
    forbagstxt.offset.y=800/2;


    while (quite == 0)
    {
        while ( SDL_PollEvent( &event ) )
        {
            if ( event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
            {
                x = event.button.x;
                y = event.button.y;
                length=bag.offset.x + bag.offset.w;
                height=bag.offset.y + bag.offset.h;
                if (x>bag.offset.x && x<(length) && y>bag.offset.y && y<(height))
                {
                    cloth_selected=&bag;
                    continue;
                }

                if (cloth_selected==&bag)
                {

                    x = event.button.x;
                    y = event.button.y;
                    length=forbags.offset.x + forbags.offset.w;
                    height=forbags.offset.y + forcoat.offset.h;

                    if (x>forbags.offset.x && x<(length) && y>forbags.offset.y && y<(height))
                        score=score+10;
                    bag.flag=0;
                    cloth_selected=NULL;
                }

                x = event.button.x;
                y = event.button.y;
                length=whitecoat.offset.x + whitecoat.offset.w;
                height=whitecoat.offset.y + whitecoat.offset.h;
                if (x>whitecoat.offset.x && x<(length) && y>whitecoat.offset.y && y<(height))
                {
                    cloth_selected=&whitecoat;
                    continue;
                }

                if (cloth_selected==&whitecoat)
                {

                    x = event.button.x;
                    y = event.button.y;
                    length=forcoat.offset.x + forcoat.offset.w;
                    height=forcoat.offset.y + forcoat.offset.h;

                    if (x>forcoat.offset.x && x<(length) && y>forcoat.offset.y && y<(height))
                        score=score+10;
                    whitecoat.flag=0;
                    cloth_selected=NULL;
                }
                 x = event.button.x;
                y = event.button.y;
                length=blackshoes.offset.x + blackshoes.offset.w;
                height=blackshoes.offset.y + blackshoes.offset.h;
                if (x>blackshoes.offset.x && x<(length) && y>blackshoes.offset.y && y<(height))
                {
                    cloth_selected=&blackshoes;
                    continue;
                }

                if (cloth_selected==&blackshoes)
                {

                    x = event.button.x;
                    y = event.button.y;
                    length=forcoat.offset.x + forcoat.offset.w;
                    height=forcoat.offset.y + forcoat.offset.h;

                    if (x>forshoes.offset.x && x<(length) && y>forshoes.offset.y && y<(height))
                        score=score+10;
                    blackshoes.flag=0;
                    cloth_selected=NULL;
                }
            }
            if ( event.type == SDL_QUIT )
            {
                quite = 1;
            }
        }
        SDL_BlitSurface( background, NULL, screen, NULL );

        blitcloth (&dita, screen);
        blitcloth (&dress, screen);
        blitcloth (&blackshoes,screen);
        blitcloth (&whitecoat, screen);
        blitcloth (&bag, screen);
        blitcloth (&forcoat,screen);
        blitcloth (&fordress,screen);
        blitcloth (&forshoes, screen);
        blitcloth (&forbags, screen);
        if (nenuzhnaya)
        {
            blitcloth (&forshoestxt,screen);
            blitcloth (&forovercoatstxt,screen);
            blitcloth (&fordressestxt,screen);
            blitcloth (&forbagstxt,screen);
        }
        SDL_Flip( screen );
    }
    return 0;
}
