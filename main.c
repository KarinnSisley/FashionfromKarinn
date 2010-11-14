#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <string.h>
#include "SDL/SDL_image.h"
#include "SDL_ttf.h"


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
    char b[15];
    int shoulderx=36/2, shouldery=65,x,y,length,height,score=0,quite = 0,nenuzhnaya=1,level;
    TTF_Init();
    SDL_Surface* screen = NULL;
    SDL_Surface *message = NULL;
    TTF_Font *font = NULL;
    SDL_Surface* background = NULL;
    SDL_Rect text;
    struct cloth girl,dress,shoes,coat,bag,jewelry,trousers,forjewelry,fortrousers,forcoat,fordress,forshoes,forbags,forshoestxt,forovercoatstxt,fordressestxt,forbagstxt,fortrouserstxt,forjewelrytxt;
    struct cloth *cloth_selected=NULL;
    font = TTF_OpenFont( "lazy.ttf", 28 );
    SDL_Color textColor = { 153, 51, 51 };

    SDL_Init( SDL_INIT_EVERYTHING );

    screen = SDL_SetVideoMode( 1024, 700, 16, SDL_SWSURFACE );

    SDL_AddTimer(3000,callback, &nenuzhnaya);
    level=2;
    background = IMG_Load("background1.jpg");
    girl.picture = Load_Image("dita.png");
    girl.flag=1;
    dress.picture = Load_Image ("dress.png");
    dress.flag=1;
    shoes.picture = Load_Image ("blackshoes.png");
    shoes.flag=1;
    coat.picture = Load_Image("whitecoat.png");
    coat.flag=1;
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



    girl.offset.x = 1024/2-girl.picture->w/2;
    girl.offset.y = 700/2-girl.picture->h/2;
    dress.offset.x = (1024/2-girl.picture->w/2)+ shoulderx;
    dress.offset.y = (700/2-girl.picture->h/2)+ shouldery;
    shoes.offset.x = 1024/2-shoes.picture->w/2-10;
    shoes.offset.y = 1024/2-15;
    coat.offset.x = (1024/2-girl.picture->w/2)+ shoulderx-14;
    coat.offset.y = (700/2-girl.picture->h/2)+ shouldery-20;
    bag.offset.x = (1024/2-girl.picture->w/2)+ 5.3*shoulderx;
    bag.offset.y = (700/2-girl.picture->h/2)+ 3*shouldery;
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
            if (level==1)
            {
                if ( !nenuzhnaya && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
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
                        length=forbags.offset.x + forbags.offset.w;
                        height=forbags.offset.y + forcoat.offset.h;

                        if (x>forbags.offset.x && x<(length) && y>forbags.offset.y && y<(height))
                            score=score+10;
                        bag.flag=0;
                        cloth_selected=NULL;
                    }


                    length=coat.offset.x + coat.offset.w;
                    height=coat.offset.y + coat.offset.h;
                    if (x>coat.offset.x && x<(length) && y>coat.offset.y && y<(height))
                    {
                        cloth_selected=&coat;
                        continue;
                    }

                    if (cloth_selected==&coat)
                    {

                        x = event.button.x;
                        y = event.button.y;
                        length=forcoat.offset.x + forcoat.offset.w;
                        height=forcoat.offset.y + forcoat.offset.h;

                        if (x>forcoat.offset.x && x<(length) && y>forcoat.offset.y && y<(height))
                            score=score+10;
                        coat.flag=0;
                        cloth_selected=NULL;
                    }
                    x = event.button.x;
                    y = event.button.y;
                    length=shoes.offset.x + shoes.offset.w;
                    height=shoes.offset.y + shoes.offset.h;
                    if (x>shoes.offset.x && x<(length) && y>shoes.offset.y && y<(height))
                    {
                        cloth_selected=&shoes;
                        continue;
                    }

                    if (cloth_selected==&shoes)
                    {

                        x = event.button.x;
                        y = event.button.y;
                        length=forshoes.offset.x + forshoes.offset.w;
                        height=forshoes.offset.y + forshoes.offset.h;

                        if (x>forshoes.offset.x && x<(length) && y>forshoes.offset.y && y<(height))
                            score=score+10;
                        shoes.flag=0;
                        cloth_selected=NULL;
                    }
                    x= event.button.x;
                    y = event.button.y;
                    length=dress.offset.x + dress.offset.w;
                    height=dress.offset.y + dress.offset.h;
                    if (x>dress.offset.x && x<(length) && y>dress.offset.y && y<(height))
                    {
                        cloth_selected=&dress;
                        continue;
                    }
                    if (cloth_selected==&dress)
                    {

                        x = event.button.x;
                        y = event.button.y;
                        length=fordress.offset.x + fordress.offset.w;
                        height=fordress.offset.y + fordress.offset.h;

                        if (x>fordress.offset.x && x<(length) && y>fordress.offset.y && y<(height))
                            score=score+10;
                        dress.flag=0;
                        cloth_selected=NULL;
                    }

                }

                if ( event.type == SDL_QUIT )
                    quite = 1;


                SDL_BlitSurface( background, NULL, screen, NULL );

                blitcloth (&girl, screen);
                blitcloth (&dress, screen);
                blitcloth (&shoes,screen);
                blitcloth (&coat, screen);
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
                snprintf(b, sizeof (b), "score: %d", score);
                message = TTF_RenderText_Solid( font, b, textColor );
                text.x= 900/2;
                text.y=700/10;
                text.w=message->w;
                text.h=message->h;

                SDL_BlitSurface( message, NULL,screen, &text );
                SDL_Flip( screen );
                if (score<40 && dress.flag==0 && bag.flag==0 && coat.flag==0 && shoes.flag==0 )
                {
                    dress.flag=1;
                    bag.flag=1;
                    coat.flag=1;
                    shoes.flag=1;
                    score=0;
                    continue;
                }
                else if (score==40)
                    level=2;
            }
        }


        if (level==2)
        {
            screen = SDL_SetVideoMode( 1250, 998, 16, SDL_SWSURFACE );
            nenuzhnaya=1;
            SDL_AddTimer(7000,callback, &nenuzhnaya);
            background = IMG_Load("background2.png");
            girl.picture = Load_Image("audrey.png");
            girl.flag=1;
            dress.picture = Load_Image ("audreydress.png");
            dress.flag=1;
            shoes.picture = Load_Image ("audreyboots.png");
            shoes.flag=1;
            jewelry.picture = Load_Image("audreybracelet.png");
            jewelry.flag=1;
            bag.picture= Load_Image("bag2.png");
            bag.flag=1;
            trousers.picture= Load_Image("audreytrousers.png");
            trousers.flag=1;
            fortrousers.picture= IMG_Load ("fortrousers.png");
            forcoat.flag=1;
            fordress.picture= IMG_Load ("fordress2.png");
            fordress.flag=1;
            forshoes.picture= IMG_Load ("forshoes2.png");
            forshoes.flag=1;
            forbags.picture= IMG_Load ("forbags2.png");
            forbags.flag=1;
            forjewelry.picture= IMG_Load ("forjew.png");
            forjewelry.flag=1;
            fortrouserstxt.picture= Load_Image("fortrouserstxt.png");
            fortrouserstxt.flag=1;
            fordressestxt.picture= Load_Image("fordressestxt2.png");
            fordressestxt.flag=1;
            forbagstxt.picture= Load_Image("forbagstxt2.png");
            forbagstxt.flag=1;
            forjewelrytxt.picture= Load_Image("forjewtxt2.png");
            forjewelrytxt.flag=1;
            forshoestxt.picture= Load_Image("forshoestxt2.png");
            forshoestxt.flag=1;

            girl.offset.x = 1024/2-girl.picture->w/2;
            girl.offset.y = 700/2-girl.picture->h/2;
            dress.offset.x = (1024/2-girl.picture->w/2)+ 22;
            dress.offset.y = (700/2-girl.picture->h/2)+57;
            shoes.offset.x = 1024/2-shoes.picture->w/2-19;
            shoes.offset.y = 1024/2-73;
            trousers.offset.x = (1024/2-girl.picture->w/2)+18;
            trousers.offset.y = (700/2-girl.picture->h/2)+150;
            bag.offset.x = (1024/2-girl.picture->w/2)-3;
            bag.offset.y = (700/2-girl.picture->h/2)+230;
            jewelry.offset.x = (1024/2-girl.picture->w/2)+130;
            jewelry.offset.y = (700/2-girl.picture->h/2)+ 215;
            fortrousers.offset.x = 1024/20-70;
            fortrousers.offset.y = 700/20-50;
            fordress.offset.x = 1100;
            fordress.offset.y = 700/20-30;
            forshoes.offset.x= 1024/20-30;
            forshoes.offset.y=800/1.6;
            forbags.offset.x=1040;
            forbags.offset.y= 700/1.5+23;
            forjewelry.offset.x= 3000/4;
            forjewelry.offset.y= 0.3;
            forshoestxt.offset.x=100;
            forshoestxt.offset.y=500;
            fortrouserstxt.offset.x=1024/26-200;
            fortrouserstxt.offset.y=700/18;
            fordressestxt.offset.x=3000/6;
            fordressestxt.offset.y= 22;
            forbagstxt.offset.x= 3000/4;
            forbagstxt.offset.y=800/2;
            forjewelrytxt.offset.x= 3000/4-50;
            forjewelrytxt.offset.y=800/10;
        }




        while ( SDL_PollEvent( &event ) )
        {

            if ( event.type == SDL_QUIT )
                quite = 1;




            SDL_BlitSurface( background, NULL, screen, NULL );
            blitcloth (&girl, screen);
            blitcloth (&trousers, screen);
            blitcloth (&dress, screen);
            blitcloth (&shoes,screen);
            blitcloth (&bag, screen);
            blitcloth (&jewelry, screen);
            blitcloth (&fortrousers,screen);
            blitcloth (&fordress,screen);
            blitcloth (&forshoes, screen);
            blitcloth (&forbags, screen);
            blitcloth (&forjewelry, screen);
            if (nenuzhnaya)
            {
                blitcloth (&forshoestxt,screen);
                blitcloth (&fortrouserstxt,screen);
                blitcloth (&fordressestxt,screen);
                blitcloth (&forbagstxt,screen);
                blitcloth (&forjewelrytxt,screen);
            }
            SDL_Flip( screen );

        }

    }
    return 0;
}
