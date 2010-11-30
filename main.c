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
    char b[20];

    int shoulderx=36/2, shouldery=65,x,y,length,height,score=0,quite = 0,nenuzhnaya=1,level,n=700/4+100;
    double i=0;
    TTF_Init();
    SDL_Surface* screen = NULL;
    SDL_Surface *message = NULL;
    SDL_Surface *message2 = NULL;
    SDL_Surface *message3 = NULL;
    SDL_Surface *message4 = NULL;
    SDL_Surface *message5 = NULL;
    SDL_Surface *message6 = NULL;
    SDL_Surface *message7 = NULL;
    SDL_Surface *message8 = NULL;
    SDL_Surface *message9 = NULL;
    SDL_Surface *message10 = NULL;
    SDL_Surface *message11 = NULL;
    SDL_Surface *message12 = NULL;
    SDL_Surface *message13 = NULL;
    SDL_Surface *message14 = NULL;
    SDL_Surface *message15= NULL;
    SDL_Surface *message16 = NULL;
    TTF_Font *font = NULL;
    SDL_Surface* background = NULL;
    SDL_Rect text,text2,text3,text4,text5,text6,text7,text8,text9,text10,text11,text12,text13,text14,text15,text16;
    struct cloth girl,girl1, girl2,girl3,girl4, dress,shoes,coat,bag,jewelry,trousers,forjewelry,fortrousers,forcoat,fordress,forshoes,forbags,forshoestxt,forovercoatstxt,fordressestxt,forbagstxt,fortrouserstxt,forjewelrytxt;
    struct cloth *cloth_selected=NULL;
    font = TTF_OpenFont( "lazy.ttf", 28 );
    SDL_Color textColor = { 153, 51, 51 };
    SDL_Color textColor2 = { 244, 164, 94 };

    SDL_Init( SDL_INIT_EVERYTHING );

    screen = SDL_SetVideoMode( 1024, 700, 16, SDL_SWSURFACE );


    SDL_AddTimer(3000,callback, &nenuzhnaya);
    level=1;
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
            if ( event.type == SDL_QUIT )
                quite = 1;

            if (level==1)
            {

                if ( !nenuzhnaya && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
                {

                    x = event.button.x;
                    y = event.button.y;
                    length=bag.offset.x + bag.offset.w;
                    height=bag.offset.y + bag.offset.h;
                    if (x>bag.offset.x && x<(length) && y>bag.offset.y && y<(height)&& bag.flag==1)
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
                    if (x>coat.offset.x && x<(length) && y>coat.offset.y && y<(height)&&coat.flag==1)
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
                    if (x>shoes.offset.x && x<(length) && y>shoes.offset.y && y<(height)&& shoes.flag==1)
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
                    if (x>dress.offset.x && x<(length) && y>dress.offset.y && y<(height)&& dress.flag==1)
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
                {
                    nenuzhnaya=1;
                    level=2;
                    SDL_AddTimer(2000,callback, &nenuzhnaya);
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
                    fortrouserstxt.picture= Load_Image("fortrouserstxt2.png");
                    fortrouserstxt.flag=1;
                    fordressestxt.picture= Load_Image("fordresstxt2.png");
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
                    jewelry.offset.x = (1024/2-girl.picture->w/2)+137;
                    jewelry.offset.y = (700/2-girl.picture->h/2)+ 215;
                    fortrousers.offset.x = 1024/20-70;
                    fortrousers.offset.y = 700/20-50;
                    fordress.offset.x = 810;
                    fordress.offset.y = 700/20-30;
                    forshoes.offset.x= 1024/20-30;
                    forshoes.offset.y=800/1.6;
                    forbags.offset.x=810;
                    forbags.offset.y= 700/1.5+23;
                    forjewelry.offset.x= 600;
                    forjewelry.offset.y= 0.3;
                    forshoestxt.offset.x=100;
                    forshoestxt.offset.y=500;
                    fortrouserstxt.offset.x=1024/26+50;
                    fortrouserstxt.offset.y=700/18;
                    fordressestxt.offset.x=790;
                    fordressestxt.offset.y= 230;
                    forbagstxt.offset.x= 700;
                    forbagstxt.offset.y=800/2;
                    forjewelrytxt.offset.x= 3000/5.5;
                    forjewelrytxt.offset.y=800/10;
                }
            }




            if (level==2)
            {


                if ( !nenuzhnaya && event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)

                {


                    x = event.button.x;
                    y = event.button.y;
                    length=bag.offset.x + bag.offset.w;
                    height=bag.offset.y + bag.offset.h;
                    if (x>bag.offset.x && x<(length) && y>bag.offset.y && y<(height)&&bag.flag==1)
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
                    x= event.button.x;
                    y = event.button.y;
                    length=dress.offset.x + dress.offset.w;
                    height=dress.offset.y + dress.offset.h;
                    if (x>dress.offset.x && x<(length) && y>dress.offset.y && y<(height)&&dress.flag==1)
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
                    length=trousers.offset.x + trousers.offset.w;
                    height=trousers.offset.y + trousers.offset.h;
                    if (x>trousers.offset.x && x<(length) && y>trousers.offset.y && y<(height)&&trousers.flag==1)
                    {
                        cloth_selected=&trousers;
                        continue;
                    }

                    if (cloth_selected==&trousers)
                    {

                        x = event.button.x;
                        y = event.button.y;
                        length=fortrousers.offset.x + fortrousers.offset.w;
                        height=fortrousers.offset.y + fortrousers.offset.h;

                        if (x>fortrousers.offset.x && x<(length) && y>fortrousers.offset.y && y<(height))
                            score=score+10;
                        trousers.flag=0;
                        cloth_selected=NULL;
                    }
                    length=jewelry.offset.x + jewelry.offset.w;
                    height=jewelry.offset.y + jewelry.offset.h;
                    if (x>jewelry.offset.x && x<(length) && y>jewelry.offset.y && y<(height)&&jewelry.flag==1)
                    {
                        cloth_selected=&jewelry;
                        continue;
                    }

                    if (cloth_selected==&jewelry)
                    {

                        x = event.button.x;
                        y = event.button.y;
                        length=forjewelry.offset.x + forjewelry.offset.w;
                        height=forjewelry.offset.y + forjewelry.offset.h;

                        if (x>forjewelry.offset.x && x<(length) && y>forjewelry.offset.y && y<(height))
                            score=score+10;
                        jewelry.flag=0;
                        cloth_selected=NULL;
                    }

                    x = event.button.x;
                    y = event.button.y;
                    length=shoes.offset.x + shoes.offset.w;
                    height=shoes.offset.y + shoes.offset.h;
                    if (x>shoes.offset.x && x<(length) && y>shoes.offset.y && y<(height)&&shoes.flag==1)
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
                }


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
                snprintf(b, sizeof (b), "score: %d", score);
                SDL_Color textColor = { 50, 205, 50 };
                message = TTF_RenderText_Solid( font, b, textColor );
                text.x= 900/2;
                text.y=700/18;
                text.w=message->w;
                text.h=message->h;
                SDL_BlitSurface( message, NULL,screen, &text );
                SDL_Flip( screen );

                if (score<90 && dress.flag==0 && bag.flag==0 && trousers.flag==0 && shoes.flag==0 && jewelry.flag==0)
                {
                    dress.flag=1;
                    bag.flag=1;
                    trousers.flag=1;
                    shoes.flag=1;
                    jewelry.flag=1;
                    score=40;
                    continue;
                }
                else if (score==90)
                {
                    level=3;
                    background = IMG_Load("background3.png");
                    girl.picture=IMG_Load("lilcasual.png");
                    girl.flag=1;
                    girl1.picture=IMG_Load("lilengaged.png");
                    girl1.flag=1;
                    girl2.picture=IMG_Load("lilevent.png");
                    girl2.flag=1;
                    girl.offset.x = 10;
                    girl.offset.y = 700/3;
                    girl1.offset.x = 450;
                    girl1.offset.y = 700/3;
                    girl2.offset.x = 800;
                    girl2.offset.y = 700/3;
                    SDL_Color textColor = { 178, 34, 34 };
                    message3 = TTF_RenderText_Solid( font, "choose the appropriate look for this occasion:", textColor );
                    text3.x= 1024/2-((message3->w)/2);
                    text3.y=700/18;
                    text3.w=message3->w;
                    text3.h=message3->h;

                    message2=TTF_RenderText_Solid( font, "your friend's engagement", textColor2 );
                    text2.x= 1024/2-((message2->w)/2);
                    text2.y=700/9;
                    text2.w=message->w;
                    text2.h=message->h;
                    event.type=0;
                }
            }
            if (level==3)
            {


                if (  event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
                {

                    x= event.button.x;
                    y = event.button.y;


                    if (i==0)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            score=score+10;
                            girl1.flag=0;


                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {

                            girl2.flag=0;


                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;

                        }
                        message2=TTF_RenderText_Solid( font, "film premiere", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;
                    }
                    else if (i==1)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {

                            girl1.flag=0;


                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                            score=score+10;


                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;

                        }
                        message2=TTF_RenderText_Solid( font, "meeting with friends", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;

                    }
                    else if (i==2)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {

                            girl1.flag=0;


                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;

                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                            score=score+10;

                        }

                        i++;
                    }

                }
                SDL_BlitSurface( background, NULL, screen, NULL );
                SDL_BlitSurface( message3, NULL,screen, &text3 );
                SDL_BlitSurface( message2, NULL,screen, &text2 );
                blitcloth (&girl, screen);
                blitcloth (&girl1, screen);
                blitcloth (&girl2, screen);
                snprintf(b, sizeof (b), "score: %d", score);
                message = TTF_RenderText_Solid( font, b, textColor );
                text.x= 880;
                text.y=700/18;
                text.w=message->w;
                text.h=message->h;
                SDL_BlitSurface( message, NULL,screen, &text );
                SDL_Flip( screen );
                if (score<120 && girl.flag==0 && girl1.flag==0 && girl2.flag==0)
                {
                    girl.flag=1;
                    girl1.flag=1;
                    girl2.flag=1;
                    score=90;
                    i=0;
                    message2=TTF_RenderText_Solid( font, "your friend's engagement", textColor2 );
                    text2.x= 1024/2-((message2->w)/2);
                    text2.y=700/9;
                    text2.w=message->w;
                    text2.h=message->h;
                    continue;
                }
                else if (score==120)
                {
                    level=4;
                    i=0;
                    background = IMG_Load("background4.png");
                    girl.picture=IMG_Load("emstyle.png");
                    girl.flag=1;
                    girl1.picture=Load_Image("glossy.png");
                    girl1.flag=1;
                    girl2.picture=Load_Image("lesbian.png");
                    girl2.flag=1;
                    girl3.picture=IMG_Load("Zhmerinka.png");
                    girl3.flag=1;
                    girl.offset.x = 10;
                    girl.offset.y = 600/3;
                    girl1.offset.x = 250;
                    girl1.offset.y = 600/3;
                    girl2.offset.x = 530;
                    girl2.offset.y = 600/3;
                    girl3.offset.x = 800;
                    girl3.offset.y = 600/3;
                    message3 = TTF_RenderText_Solid( font, "choose the appropriate look for graduation party, if you:", textColor );
                    text3.x= 1024/2-((message3->w)/2);
                    text3.y=700/18;
                    text3.w=message3->w;
                    text3.h=message3->h;
                    SDL_Color textColor2 = {205,112,84};
                    message2=TTF_RenderText_Solid( font, "always dress tastefully", textColor2 );
                    text2.x= 1024/2-((message2->w)/2);
                    text2.y=700/9;
                    text2.w=message->w;
                    text2.h=message->h;
                    event.type=0;

                }
            }
            if (level==4)
            {


                SDL_Color textColor2 = {205,112,84};
                if (  event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
                {
                    x= event.button.x;
                    y = event.button.y;


                    if (i==0)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;
                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        message2=TTF_RenderText_Solid( font, "came from Zhmerinka-village", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;
                    }
                    else if (i==1)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;
                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                            score=score+10;
                        }
                        message2=TTF_RenderText_Solid( font, "are keen on glossy magazines", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;

                    }
                    else if (i==2)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        message2=TTF_RenderText_Solid( font, "are lesbian", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;
                    }
                    else if (i==3)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;

                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }

                        i++;
                    }
                }
                SDL_BlitSurface( background, NULL, screen, NULL );
                SDL_BlitSurface( message3, NULL,screen, &text3 );
                SDL_BlitSurface( message2, NULL,screen, &text2 );
                blitcloth (&girl, screen);
                blitcloth (&girl1, screen);
                blitcloth (&girl2, screen);
                blitcloth (&girl3, screen);
                snprintf(b, sizeof (b), "score: %d", score);
                message = TTF_RenderText_Solid( font, b, textColor );
                text.x= 880;
                text.y=700/18;
                text.w=message->w;
                text.h=message->h;
                SDL_BlitSurface( message, NULL,screen, &text );
                SDL_Flip( screen );
                if (score<160 && girl.flag==0 && girl1.flag==0 && girl2.flag==0 && girl3.flag==0)
                {
                    score=120;
                    girl.flag=1;
                    girl1.flag=1;
                    girl2.flag=1;
                    girl3.flag=1;
                    i=0;
                    SDL_Color textColor2 = {205,112,84};
                    message2=TTF_RenderText_Solid( font, "always dress tastefully", textColor2 );
                    text2.x= 1024/2-((message2->w)/2);
                    text2.y=700/9;
                    text2.w=message->w;
                    text2.h=message->h;
                    continue;
                }
                else if (score==160)
                {
                    level=5;
                    i=0;
                    background = IMG_Load("background5.png");
                    girl.picture=IMG_Load("18birthday.png");
                    girl.flag=1;
                    girl1.picture=IMG_Load("forboyfriend.png");
                    girl1.flag=1;
                    girl2.picture=Load_Image("cinema.png");
                    girl2.flag=1;
                    girl3.picture=IMG_Load("fordances.png");
                    girl3.flag=1;
                    girl4.picture=Load_Image("forwedding.png");
                    girl4.flag=1;
                    girl.offset.x = 8;
                    girl.offset.y = 600/5+20;
                    girl1.offset.x = 200;
                    girl1.offset.y = 600/5+20;
                    girl2.offset.x = 600;
                    girl2.offset.y = 600/5+20;
                    girl3.offset.x = 820;
                    girl3.offset.y = 600/5+20;
                    girl4.offset.x = 400;
                    girl4.offset.y = 600/5+20;
                    message3 = TTF_RenderText_Solid( font, "choose the appropriate look for this occasion", textColor );
                    text3.x= 1024/2-((message3->w)/2);
                    text3.y=700/18;
                    text3.w=message3->w;
                    text3.h=message3->h;
                    SDL_Color textColor2 = {205,51,51};
                    message2=TTF_RenderText_Solid( font, "you are going to dance", textColor2 );
                    text2.x= 1024/2-((message2->w)/2);
                    text2.y=700/9;
                    text2.w=message->w;
                    text2.h=message->h;
                    event.type=0;
                }
            }
            if (level==5)
            {


                SDL_Color textColor2 = {205,51,51};
                if (  event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
                {
                    x= event.button.x;
                    y = event.button.y;


                    if (i==0)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;
                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;
                        }
                        message2=TTF_RenderText_Solid( font, "you are celebrating yiur 18-th birthday", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;
                    }
                    else if (i==1)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;
                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;
                        }
                        message2=TTF_RenderText_Solid( font, "are looking for a boyfriend", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;

                    }
                    else if (i==2)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;
                        }
                        message2=TTF_RenderText_Solid( font, "you are going to the cinema", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;
                    }
                    else if (i==3)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;

                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;
                        }
                        message2=TTF_RenderText_Solid( font, "you are going to your daughter's wedding ceremony", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;
                    }
                    else if (i==4)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;

                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;
                            score=score+10;
                        }
                        i++;


                    }
                }
                text2.x= 1024/2-((message2->w)/2);
                text2.y=700/9;
                text2.w=message->w;
                text2.h=message->h;
                SDL_BlitSurface( background, NULL, screen, NULL );
                SDL_BlitSurface( message3, NULL,screen, &text3 );
                SDL_BlitSurface( message2, NULL,screen, &text2 );
                blitcloth (&girl, screen);
                blitcloth (&girl1, screen);
                blitcloth (&girl2, screen);
                blitcloth (&girl3, screen);
                blitcloth (&girl4, screen);
                snprintf(b, sizeof (b), "score: %d", score);
                message = TTF_RenderText_Solid( font, b, textColor );
                text.x= 880;
                text.y=700/18;
                text.w=message->w;
                text.h=message->h;
                SDL_BlitSurface( message, NULL,screen, &text );
                SDL_Flip( screen );
                if (score<210 && girl.flag==0 && girl1.flag==0 && girl2.flag==0 && girl3.flag==0 && girl4.flag==0)
                {
                    score=160;
                    girl.flag=1;
                    girl1.flag=1;
                    girl2.flag=1;
                    girl3.flag=1;
                    girl4.flag=1;
                    i=0;
                    SDL_Color textColor2 = {205,112,84};
                    message2=TTF_RenderText_Solid( font, "you are going to dance", textColor2 );
                    text2.x= 1024/2-((message2->w)/2);
                    text2.y=700/9;
                    text2.w=message->w;
                    text2.h=message->h;
                    continue;
                }
                else if (score==210)
                {
                    level=6;
                    i=0;
                    background = IMG_Load("background6.png");
                    girl.picture=IMG_Load("lawer.png");
                    girl.flag=1;
                    girl1.picture=IMG_Load("candies.png");
                    girl1.flag=1;
                    girl2.picture=Load_Image("danceteacher.png");
                    girl2.flag=1;
                    girl3.picture=IMG_Load("diplomat.png");
                    girl3.flag=1;
                    girl4.picture=IMG_Load("businesswoman.png");
                    girl4.flag=1;
                    girl.offset.x = 8;
                    girl.offset.y = 600/5;
                    girl1.offset.x = 200;
                    girl1.offset.y = 600/5+20;
                    girl2.offset.x = 620;
                    girl2.offset.y = 600/5+20;
                    girl3.offset.x = 820;
                    girl3.offset.y = 600/5;
                    girl4.offset.x = 400;
                    girl4.offset.y = 600/5+40;
                    message3 = TTF_RenderText_Solid( font, "choose the appropriate look for each occupation", textColor );
                    text3.x= 1024/2-((message3->w)/2);
                    text3.y=700/18;
                    text3.w=message3->w;
                    text3.h=message3->h;
                    SDL_Color textColor2 = {139,131,134};
                    message2=TTF_RenderText_Solid( font, "you are a shop assistant in candy shop", textColor2 );
                    text2.x= 1024/2-((message2->w)/2);
                    text2.y=700/9;
                    text2.w=message->w;
                    text2.h=message->h;
                    event.type=0;
                }
                SDL_Flip( screen );
            }
            if (level==6)
            {

                SDL_Color textColor2 = {139,131,134};
                if (  event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
                {
                    x= event.button.x;
                    y = event.button.y;


                    if (i==0)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;
                        }
                        message2=TTF_RenderText_Solid( font, "diplomat", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;
                    }
                    else if (i==1)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;
                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;

                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;
                        }
                        message2=TTF_RenderText_Solid( font, "businesswoman", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;

                    }
                    else if (i==2)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;

                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;
                            score=score+10;
                        }
                        message2=TTF_RenderText_Solid( font, "lawer", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;
                    }
                    else if (i==3)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;

                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;

                        }
                        message2=TTF_RenderText_Solid( font, "dance teacher", textColor2 );
                        SDL_BlitSurface( background, &text2, screen, &text2 );
                        i++;
                    }
                    else if (i==4)
                    {
                        if ((x>girl1.offset.x && x<(girl1.offset.x+girl1.offset.w)) && y>girl1.offset.y && y<(girl1.offset.y+girl1.offset.h))
                        {
                            girl1.flag=0;

                        }
                        else if ((x>girl2.offset.x && x<(girl2.offset.x+girl2.offset.w)) && (y>girl2.offset.y && y<(girl2.offset.y+girl2.offset.h)))
                        {
                            girl2.flag=0;
                            score=score+10;
                        }
                        else if ((x>girl.offset.x && x<(girl.offset.x+girl.offset.w)) && (y>girl.offset.y && y<(girl.offset.y+girl.offset.h)))
                        {
                            girl.flag=0;
                        }
                        else if ((x>girl3.offset.x && x<(girl3.offset.x+girl3.offset.w)) && (y>girl3.offset.y && y<(girl3.offset.y+girl3.offset.h)))
                        {
                            girl3.flag=0;
                        }
                        else if ((x>girl4.offset.x && x<(girl4.offset.x+girl4.offset.w)) && (y>girl4.offset.y && y<(girl4.offset.y+girl4.offset.h)))
                        {
                            girl4.flag=0;
                            score=score+10;
                        }
                        i++;
                    }
                }
                text2.x= 1024/2-((message2->w)/2);
                text2.y=700/9;
                text2.w=message->w;
                text2.h=message->h;
                SDL_BlitSurface( background, NULL, screen, NULL );
                SDL_BlitSurface( message3, NULL,screen, &text3 );
                SDL_BlitSurface( message2, NULL,screen, &text2 );
                blitcloth (&girl, screen);
                blitcloth (&girl1, screen);
                blitcloth (&girl2, screen);
                blitcloth (&girl3, screen);
                blitcloth (&girl4, screen);
                snprintf(b, sizeof (b), "score: %d", score);
                message = TTF_RenderText_Solid( font, b, textColor );
                text.x= 880;
                text.y=700/18;
                text.w=message->w;
                text.h=message->h;
                SDL_BlitSurface( message, NULL,screen, &text );
                SDL_Flip( screen );
                if (score<260 && girl.flag==0 && girl1.flag==0 && girl2.flag==0 && girl3.flag==0 && girl4.flag==0)
                {
                    score=210;
                    girl.flag=1;
                    girl1.flag=1;
                    girl2.flag=1;
                    girl3.flag=1;
                    girl4.flag=1;
                    i=0;
                    SDL_Color textColor2 = {139,131,134};
                    message2=TTF_RenderText_Solid( font, "you are a shop assistant in candy shop", textColor2 );
                    text2.x= 1024/2-((message2->w)/2);
                    text2.y=700/9;
                    text2.w=message->w;
                    text2.h=message->h;
                    continue;
                }
                else if (score==260)
                {
                    level=7;
                    event.type=0;
                    font = TTF_OpenFont( "lazy.ttf", 82 );
                }
            }
            if (level==7)
            {
                background = IMG_Load("background7.png");
                SDL_Color textColor2 = {205,51,51};
                message=TTF_RenderText_Solid( font, "C", textColor2 );
                message2=TTF_RenderText_Solid( font, "O", textColor2 );
                message3=TTF_RenderText_Solid( font, "N", textColor2 );
                message4=TTF_RenderText_Solid( font, "G", textColor2 );
                message5=TTF_RenderText_Solid( font, "R", textColor2 );
                message6=TTF_RenderText_Solid( font, "A", textColor2 );
                message7=TTF_RenderText_Solid( font, "T", textColor2 );
                message8=TTF_RenderText_Solid( font, "U", textColor2 );
                message9=TTF_RenderText_Solid( font, "L", textColor2 );
                message10=TTF_RenderText_Solid( font, "A", textColor2 );
                message11=TTF_RenderText_Solid( font, "T", textColor2 );
                message12=TTF_RenderText_Solid( font, "E", textColor2 );
                message13=TTF_RenderText_Solid( font, "!", textColor2 );
                girl.picture=Load_Image("marlen.png");
                girl.flag=1;
                girl1.picture=Load_Image("maria.png");
                girl1.flag=1;
                girl2.picture=Load_Image("mai.png");
                girl2.flag=1;
                girl3.picture=Load_Image("louise.png");
                girl3.flag=1;
                girl4.picture=Load_Image("natali.png");
                girl4.flag=1;
                dress.picture=Load_Image("malin.png");
                dress.flag=1;
                shoes.picture=Load_Image("maggie.png");
                shoes.flag=1;
                coat.picture=Load_Image("mary.png");
                coat.flag=1;
                bag.picture=Load_Image("mary-kate.png");
                bag.flag=1;
                jewelry.picture=Load_Image("miley.png");
                jewelry.flag=1;
                trousers.picture=Load_Image("nicole.png");
                trousers.flag=1;

                while (i<(700/4))
                {
                    text.y=i;
                    text2.y=i*0.75;
                    text3.y=i;
                    text4.y=i*0.75;
                    text5.y=i;
                    text6.y=i*0.75;
                    text7.y=i;
                    text8.y=i*0.75;
                    text9.y=i;
                    text10.y=i*0.75;
                    text11.y=i;
                    text12.y=i*0.75;
                    text13.y=i;
                    text14.y=i*0.75;
                    text15.y=i;
                    text16.y=i*0.75;
                    i=i+5;

                    text.x= 4;
                    text.w=message->w;
                    text.h=message->h;
                    text2.x= 80;
                    text2.w=message2->w;
                    text2.h=message2->h;
                    text3.x= 120;
                    text3.w=message3->w;
                    text3.h=message3->h;
                    text4.x= 250;
                    text4.w=message4->w;
                    text4.h=message4->h;
                    text5.x= 300;
                    text5.w=message5->w;
                    text5.h=message5->h;
                    text6.x= 380;
                    text6.w=message6->w;
                    text6.h=message6->h;
                    text7.x= 490;
                    text7.w=message7->w;
                    text7.h=message7->h;
                    text8.x= 570;
                    text8.w=message8->w;
                    text8.h=message8->h;
                    text9.x= 620;
                    text9.w=message9->w;
                    text9.h=message9->h;
                    text10.x= 720;
                    text10.w=message10->w;
                    text10.h=message10->h;
                    text11.x= 830;
                    text11.w=message11->w;
                    text11.h=message11->h;
                    text12.x= 910;
                    text12.w=message12->w;
                    text12.h=message12->h;
                    text13.x=990;
                    text13.w=message13->w;
                    text13.h=message13->h;

                    SDL_BlitSurface( background, NULL, screen, NULL );
                    SDL_BlitSurface( message, NULL,screen, &text );
                    SDL_BlitSurface( message2, NULL,screen, &text2 );
                    SDL_BlitSurface( message3, NULL,screen, &text3 );
                    SDL_BlitSurface( message4, NULL,screen, &text4 );
                    SDL_BlitSurface( message5, NULL,screen, &text5 );
                    SDL_BlitSurface( message6, NULL,screen, &text6 );
                    SDL_BlitSurface( message7, NULL,screen, &text7 );
                    SDL_BlitSurface( message8, NULL,screen, &text8 );
                    SDL_BlitSurface( message9, NULL,screen, &text9 );
                    SDL_BlitSurface( message10, NULL,screen, &text10 );
                    SDL_BlitSurface( message11, NULL,screen, &text11 );
                    SDL_BlitSurface( message12, NULL,screen, &text12 );
                    SDL_BlitSurface( message13, NULL,screen, &text13 );
                    SDL_Flip( screen );

                }
                if (i>=700/4)
                {
                    girl.offset.x = 8;
                    girl.offset.y = n;
                    girl1.offset.x = 100;
                    girl1.offset.y = n;
                    girl3.offset.x = 180;
                    girl3.offset.y = n;
                    girl2.offset.x=260;
                    girl2.offset.y=n;
                    girl4.offset.x=350;
                    girl4.offset.y=n;
                    dress.offset.x=440;
                    dress.offset.y=n;
                    shoes.offset.x=545;
                    shoes.offset.y=n;
                    coat.offset.x=610;
                    coat.offset.y=n;
                    bag.offset.x=710;
                    bag.offset.y=n;
                    jewelry.offset.x=810;
                    jewelry.offset.y=n;
                    trousers.offset.x=890;
                    trousers.offset.y=n;
                    blitcloth (&girl, screen);
                    blitcloth (&girl1, screen);
                    blitcloth (&girl2, screen);
                    blitcloth (&girl3, screen);
                    blitcloth (&girl4, screen);
                    blitcloth (&dress, screen);
                    blitcloth (&shoes, screen);
                    blitcloth (&coat, screen);
                    blitcloth (&bag, screen);
                    blitcloth (&jewelry, screen);
                    blitcloth (&trousers, screen);
                    SDL_Flip( screen );
                }


            }
        }
    }

    return 0;
}
