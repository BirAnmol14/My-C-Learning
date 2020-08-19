#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Point Analyzer\n");
    float x,y;
    {
    printf("Enter co-ordinates of point (x y)-> ");scanf("%f %f",&x,&y);
    if(x==0&&y!=0){printf("Point (%.2f , %.2f) on y-axis\n",x,y);}
    else if(x!=0&&y==0){printf("Point (%.2f , %.2f) on x-axis\n",x,y);}
    else if(x==0&&y==0){printf("Point (%.2f , %.2f) is origin\n",x,y);}
    else if(x>0&&y>0){printf("Point (%.2f , %.2f) in quadrant I\n",x,y);}
    else if(x>0&&y<0){printf("Point (%.2f , %.2f) in quadrant IV\n",x,y);}
    else if(x<0&&y>0){printf("Point (%.2f , %.2f) in quadrant II\n",x,y);}
    else if(x<0&&y<0){printf("Point (%.2f , %.2f) in quadrant III\n",x,y);}
    }
    return 0;
}
