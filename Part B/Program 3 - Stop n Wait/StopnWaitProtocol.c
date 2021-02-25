#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define TIMEOUT 5

typedef enum{frame_s,frame_r,ack,timeout} event;
event event_type;

int noframes =5,frame_id=0;

int DISCONNECT=0;
int timer=0;

void delay()
{ 
    int i=0;
    for(i=0;i<10000; i++);
    
}

//wait_for_event()
void sender()
{
    if(event_type == frame_s)
    {
            frame_id += 1 ;
            timer =0;
            printf("\n sending frames %d",frame_id);
            timer++;
            event_type = frame_r;
            
    
     }
    
    if(event_type == ack)
    { 
            
        if (timer>TIMEOUT)
        {   printf("\n timeout %d ",timer);
            printf("\n Re -sending frames %d",frame_id);
            timer = 0;
            event_type = frame_r; 
        }
                 
            event_type = frame_s;    
        }
        
        
}

void reciever()
{  int i=0,x;
    timer++;
    
    
    x=rand()%10;  // add some random delay
        for (i=0;i<x;i++)
     { delay();
       timer++;
      }
      
      if(event_type == frame_r)
      {
   printf("\n ACKNOWLEDGEMENT for frame %d ",frame_id);
   event_type = ack;
     }   
    
}

int main()
{  event_type = frame_s;
    while(!DISCONNECT)
    {   
        sender();
        delay();
        
        reciever();
        if (frame_id == noframes) 
            { DISCONNECT =1; printf("\n Disconnected ");}
    
    }
    
    return 0;
}
