#include<iostream>
#include<SDL.h>
#include<stdio.h>
#include<cmath>
#include<SDL_image.h>
#include<string>
#include<ctime>
#include<SDL_mixer.h>
SDL_Window* gwindo=NULL;
SDL_Renderer* grender=NULL;
Mix_Music* music=NULL;
Mix_Chunk* CHANK=NULL;
int first=2;
bool shot=false,shot1=false;
int H=0;

int xshot=10;


class dot{
   SDL_Texture* mtexture;
   SDL_Rect rect;
   int mv,mvm;
   public:
      dot()
      {
          mtexture=NULL;
          rect={0,0,50,50};
      }
      void render(int &x,int &y,float &r,int bx,int by,int by1)
      {     
            rect={x,y,40,40};
            SDL_RenderCopyEx(grender,mtexture,NULL,&rect,r,NULL,SDL_FLIP_NONE) ;
            r+=4; 
            if(r==360)
            r=0;
            if(H==3)
            {
                if(y>=by-10&&y<=by+20){
                mv=1;
                shot=false;}
                else if(y>=by+20&&y<=by+20+70)
                {
                                mv=2;
                                shot=false;
                               
                }
                else if(y>=by+20+70&&y<=by+20+70+70)
                {
                                mv=5;
                                shot=false;
                                
                }
                 else if(y>=by+20+70+70&&y<=by+20+70+70+70)
                {
                                mv=3;
                                shot=false;
                               
                }
                  else if(y>=by+20+70+70&&y<=by+250+10)
                {
                                mv=4;
                                shot=false;
                                
                }

            } 
             if(H==4)
            {
                if(y>=by1-30&&y<=by1+20){
                mv=11;
                shot1=false;}
                else if(y>=by1+20&&y<=by1+20+70)
                {
                                mv=12;
                                shot1=false;
                               
                }
                else if(y>=by1+20+70&&y<=by1+20+70+70)
                {
                                mv=15;
                                shot1=false;
                              
                }
                else if(y>=by1+70+70+20&&y<=by1+20+70+70+70)
                {
                    mv=13;
                    shot1=false;
                   
                }
                 else if(y>=by1+20+70+70+70&&y<=by1+250+30)
                {
                                mv=14;
                                shot1=false;
                                
                }
            }
    
            if(y<=0)
               {
                   if(mv==1 || mv==2)
                   {
                      if(mvm==1)
                      {
                          mv=33;
                          mvm=2;
                      }
                      else if(mvm==2)
                      {
                          mv=34;
                          mvm=3;
                      }
                      else if(mvm=3)
                      {
                          mv=35;
                          mvm=1;
                      }
                   }
                   else if(mv==11 || mv==12)
                   {
                       if(mvm==1)
                      {
                          mv=133;
                          mvm=2;
                      }
                      else if(mvm==2)
                      {
                          mv=134;
                          mvm=3;
                      }
                      else if(mvm=3)
                      {
                          mv=135;
                          mvm=1;
                      }
                   }
               }
            else if(y>=720-40)
            {
                if(mv==3||mv==4)
                {
                    mv=1;
                }
                else if(mv==13 || mv ==14)
                {
                    mv=11;
                }
            }
            mouve(x,y);
             if(x>=1280-20-40-40 && H==0)
             {
                if(y>=by-30&&y<=by+20){
                mv=1;
                shot=false;}
                else if(y>=by+20&&y<=by+20+70)
                {
                                mv=2;
                              
                }
                else if(y>=by+20+70&&y<=by+20+70+70)
                {
                                mv=5;
                               
                }
                 else if(y>=by+20+70+70&&y<=by+20+70+70+70)
                {
                                mv=3;
                               
                }
                  else if(y>=by+20+70+70&&y<=by+250+30)
                {
                                mv=4;
                               
                }
                else if(x>=1280+40)
                {
                    first=0;
                    mv=0;
                }
             }
             else if(x<=0+35+20 && H==0)
             {
                if(y>=by1-30&&y<=by1+20)
                {
                    mv=11;
                }
                else if(y>=by1+20&&y<=by1+20+70)
                {
                                mv=12;
                                
                }
                else if(y>=by1+20+70&&y<=by1+20+70+70)
                {
                                mv=15;
                                
                }
                else if(y>=by1+70+70+20&&y<=by1+20+70+70+70)
                {
                                   mv=13;
                    
                }
                 else if(y>=by1+20+70+70+70&&y<=by1+250+30)
                {
                                mv=14;
                                
                }
                else if(x<=0-40)
                {
                    first=1;
                    mv=0;
                }
             }
                H=0;
               
        
            
      }
      void load(std::string path)
      {
          SDL_Surface *msurface=IMG_Load(path.c_str());
          mtexture=SDL_CreateTextureFromSurface(grender,msurface);
          SDL_FreeSurface(msurface);
      }
      void mouve(int &x,int &y)
      {
            if(mv==1)
            {
                x-=xshot;
                y-=15;
            }
           else if(mv==2)
            {
                x-=xshot;
                y-=5;
            }
           else if(mv==3)
            {
                x-=xshot;
                y+=5;
            }
           else if(mv==4)
            {
                x-=xshot;
                y+=15;
            }
            else if(mv==5)
            {
               x-=xshot;
            }else if (mv==33)
            {
                x-=xshot+xshot/2;
                y+=2;
            }
             else if (mv==35)
            {
                x-=xshot+xshot/2;
                y+=7;
            }
            else if (mv==34)
            {
                x-=xshot+xshot/2;
                y+=1;
            }



             if(mv==11)
            {
                x+=xshot;
                y-=5;
            }
           else if(mv==12)
            {
                x+=xshot;
                y-=5;
            }
           else if(mv==13)
            {
                x+=xshot;
                y+=5;
            }
           else if(mv==14)
            {
                x+=xshot;
                y+=5;
            }
            else if(mv==15)
            {
                x+=xshot;
            }
             else if(mv==133)
            {
                x+=xshot+xshot/2;
                y+=5+3;
            }
             else if(mv==134)
            {
                x+=xshot+xshot/2-5;
                y+=5;
            }
             else if(mv==135)
            {
                x+=xshot+xshot/2+3;
                y+=5;
            }
           
      }
      void free()
      {
          SDL_DestroyTexture(mtexture);
          mtexture=NULL;

      }
}n;

class bar{
    SDL_Rect rect;
    public:
    void render(int y,int x,int r,int g,int b)
    {    rect={x,y,20,250};
        SDL_SetRenderDrawColor(grender,r,g,b,255);
        SDL_RenderFillRect(grender,&rect);
        SDL_SetRenderDrawColor(grender,255,255,255,255);
        SDL_RenderDrawRect(grender,&rect);
    }
}b1,b2;

class menu{
    SDL_Texture* macht_1v1[4][2];
    SDL_Rect rect[4];
    int mv[3]={0,0,0},z=5,x=5;
       public:
       menu()
       {
           for(int i=0;i<4;i++)
            {   for(int j=0;j<2;j++){
                macht_1v1[i][j]=NULL;
            }
            }
            
       }
       void load()
       {    SDL_Surface* msurface=IMG_Load("GFX/sh ball.png");
          macht_1v1[0][0]=SDL_CreateTextureFromSurface(grender,msurface);
            SDL_FreeSurface(msurface);
         msurface=IMG_Load("GFX/1V1W.png");
            macht_1v1[1][0]=SDL_CreateTextureFromSurface(grender,msurface);
          SDL_FreeSurface(msurface);
        msurface=IMG_Load("GFX/1V1Y.png");
            macht_1v1[1][1]=SDL_CreateTextureFromSurface(grender,msurface);
           SDL_FreeSurface(msurface);
         msurface=IMG_Load("GFX/1VSBW.png");
            macht_1v1[2][0]=SDL_CreateTextureFromSurface(grender,msurface);
            SDL_FreeSurface(msurface);
         msurface=IMG_Load("GFX/1VBY.png");
            macht_1v1[2][1]=SDL_CreateTextureFromSurface(grender,msurface);
            SDL_FreeSurface(msurface);
         msurface=IMG_Load("GFX/quitw.png");
            macht_1v1[3][0]=SDL_CreateTextureFromSurface(grender,msurface);
            SDL_FreeSurface(msurface);
         msurface=IMG_Load("GFX/quity.png");
            macht_1v1[3][1]=SDL_CreateTextureFromSurface(grender,msurface);
            SDL_FreeSurface(msurface);
            rect[0]={426-20,-40,426+50,300};
            rect[1]={426+110,200,240,200};
            rect[2]={426+110,200+100,240,200};
            rect[3]={426+110+30,200+100+200,180,80};
            
       }
       void rebder(int x,int y,bool chek,bool &quit,bool &quitall,bool &quitai)
      {     
                      for(int i=0;i<3;i++)
                      {
                          mv[i]=0;
                      }
               
                    if(x>=426+110&&x<=426+110+240)
                    {
                        if(y>=270&&y<=200+200-63){
                               if(chek==true){
                                mv[0]=0;
                                quit=true;
                               } 
                                else
                                mv[0]=1;
                                z=0;  
                        
                         }
                        else if(y>=270+100&&y<=200+240){
                          if(chek==true){
                                mv[1]=0; 
                                        quit=true;
                                        quitai=true;
                                  }
                                else
                                mv[1]=1; 
                        
                                 z=1 ;}
                        else if(y>=200+240+70&&y<=200+240+100+30){
                         if(chek==true){
                                mv[2]=0; 
                                quit=true;
                                quitall=true;}
                                else
                                mv[2]=1;
                                
                        
                        
                        z=2;  }
                        
                        
            
                    }
                
                     playchunk();
                     if(x>=426+110&&x<=426+110+240&&y>=270&&y<=200+200-63 ||x>=426+110&&x<=426+110+240&&y>=270+100&&y<=200+240||x>=426+110&&x<=426+110+240&&y>=200+240+70&&y<=200+240+100+30);
                     else{
                     this->x=5;
                     this->z=5;
                     }
                 for(int j=0;j<4;j++){        
                if(j==0)
                 SDL_RenderCopy(grender,macht_1v1[j][0],NULL,&rect[j]);
                else
                SDL_RenderCopy(grender,macht_1v1[j][mv[j-1]],NULL,&rect[j]);
                
                  }  
                  playchunk();
       
       }
       void free()
       {
          for(int i=0;i<4;i++)
            {   for(int j=0;j<2;j++){
                SDL_DestroyTexture(macht_1v1[i][j]);
                macht_1v1[i][j]=NULL;
            }
            }
       }
       void playchunk()
       {   
         if(z==1||z==2||z==0)
         {
             if(x==5)
             {
                 Mix_PlayChannel(-1,CHANK,0);
                 x=0;
             }
         }
         
       }





}d;


bool init();
bool load();
void exit();


bool init()
{   
    bool suc= true;
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
         printf("could not init vedio %s\n",SDL_GetError());
         suc=false;
    }
    else
    {  // SDL_SetHint(SDL_HINT_RENDER_VSYNC,"1");
        gwindo=SDL_CreateWindow("calculator",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1280,720,SDL_WINDOW_SHOWN );
        if(gwindo==NULL)
        {
            printf("could not creat window %s\n",SDL_GetError());
                 suc=false;
        }
        else{
        grender=SDL_CreateRenderer(gwindo,-1,SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if(grender==NULL)
        {
            printf("could not creat renderer %s\n",SDL_GetError());
            suc=false;
        }
        else
        {
          if( !(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
            {
               printf("could not init img %s\n",IMG_GetError());
            suc=false;
            } 
            Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
        }
        }
    }
    return suc;
}
void exit()
{
    SDL_DestroyWindow(gwindo);
    gwindo=NULL;
    n.free();
    d.free();
    SDL_DestroyRenderer(grender);
    Mix_FreeChunk(CHANK);
    Mix_FreeMusic(music);
    grender=NULL;
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
}
bool load()
{   bool suc=true;
    n.load("GFX/—Pngtree—modren ball icon vector_5048397.png");
    d.load();
    music=Mix_LoadMUS("GFX/Van Halen - Jump (Resfield Remix) (320 kbps).mp3");
    CHANK=Mix_LoadWAV("GFX/button-23.wav");
    return suc;
}
void controll(int &y,int &y1,bool ai,int by)
{   if(!ai){
    const Uint8* currentkeystate = SDL_GetKeyboardState(NULL);
    if(currentkeystate[SDL_SCANCODE_UP])
    {
            y-=5;
            if(y<=5)
            y=5;
    }
    else if(currentkeystate[SDL_SCANCODE_DOWN])
    {
         y+=5;
         if(y>=720-5-250)
         y=720-5-250;
    }
   else if(currentkeystate[SDL_SCANCODE_LEFT])
    {
             if(shot==true){
              H=3;
              }
    }
     if(currentkeystate[SDL_SCANCODE_W])
    {
              
            y1-=5;
            if(y1<=5)
            y1=5; 
    }
    else if(currentkeystate[SDL_SCANCODE_S])
    {
         y1+=5;
         if(y1>=720-5-250)
         y1=720-5-250;
    }
    else if(currentkeystate[SDL_SCANCODE_D])
    {
        if(shot1==true){
              H=4;
              }
    }
    }
    else
    {  const Uint8* currentkeystate = SDL_GetKeyboardState(NULL);
     if(currentkeystate[SDL_SCANCODE_W])
    {
              
            y1-=5;
            if(y1<=5)
            y1=5; 
    }
    else if(currentkeystate[SDL_SCANCODE_S])
    {
         y1+=5;
         if(y1>=720-5-250)
         y1=720-5-250;
    }
    else if(currentkeystate[SDL_SCANCODE_D])
    {
        if(shot1==true){
              H=4;
              }
    }
    if(shot==true){
              H=3;
              }
    else if(y>=by)
    {
            y-=5;
            if(y<=5)
            y=5;
    }
    else if (y+250<=by)
    {
         y+=5;
         if(y>=720-5-250)
         y=720-5-250;
    }

       

    }

}
void game(int &xb,int &yb ,int &y1 ,int &y)
{   
    if(first==2)
    {
    srand(time(NULL));
    first=rand()%(1-0+1)+0;
    }
    if(first==1)
    {
        y1=235;
        y=235;
        xb=1280-40-20-50;
        yb=y1+250/2;
        first=3;
        shot=true;
    }
    else if (first==0){

        y=235;
        y1=235;
        xb=35+30;
        yb=y+250/2;
        first=3;
        shot1=true;
       
    }


}


int main(int argc,char* args[])
{

   if(!init())
   {
       printf("could not init()\n");
   }
   else
   {    if(!load())
   {

   }
       else
       {  bool quit=false,quitmenu=false, quitai=false,mousedown=false;
         SDL_Event e;
         float c=0;
         int x=1280-40-20,y=235,x1=35,y1=235,xb=1280/2-20,yb=720/2-20,XM=0,YM=0;
         SDL_Surface * msurface=IMG_Load("GFX/imgbin_football-field-png.png");
         SDL_Texture* mtextur=SDL_CreateTextureFromSurface(grender,msurface);
         SDL_Rect   w={0,0,1280,720};
         SDL_FreeSurface(msurface);
         msurface=NULL;
         Mix_PlayMusic(music,-1);
         while(!quit)
         {   while(SDL_PollEvent(&e)!=0)
             {
                  if(e.type==SDL_QUIT)
                  {
                      quit=true;

                  }
             }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////         
             while(!quitmenu)
                {    
                     SDL_RenderCopy(grender,mtextur,NULL,&w);
                     n.render(xb,yb,c,x,y,y1);
                     b1.render(y,x,0,255,255);
                     b2.render(y1,x1,255,43,122);
                     while(SDL_PollEvent(&e)!=0)
                      { 
                        if(e.type==SDL_QUIT)
                        {
                           
                          quitmenu=true;

                        }
                         else if(e.type==SDL_MOUSEMOTION )
                        {
                           SDL_GetMouseState(&XM,&YM);
                        } 
                        else if(e.type==SDL_MOUSEBUTTONDOWN)
                        {
                            mousedown=true;
                        } 
                        else if(e.type==SDL_MOUSEBUTTONUP)
                        {
                            mousedown=false;
                        }
                    }
                    d.rebder(XM,YM,mousedown,quitmenu,quit,quitai);
                     SDL_RenderPresent(grender);
                }               
              SDL_SetRenderDrawColor(grender,0,0,0,255);
              SDL_RenderClear(grender);
              SDL_RenderCopy(grender,mtextur,NULL,&w);
              n.render(xb,yb,c,x,y,y1);
              b1.render(y,x,0,255,255);
              b2.render(y1,x1,255,43,122);
              controll(y,y1,quitai,yb);
              game(xb,yb,y1,y);

             SDL_RenderPresent(grender);
         }
       }
   }


    exit();


    return 0;
}