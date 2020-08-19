#include <stdio.h>
#include <stdlib.h>
void draw_triangle(void);
void draw_rectangle(void);
int main()
{
    draw_triangle();
    draw_rectangle();
    printf("\n\n");
    draw_triangle();
    draw_rectangle();
    return 0;
}
void draw_triangle(void)
{
    printf("\t  #\n");
    printf("\t # #\n");
    printf("\t#   #\n");
    printf("\t_____\n");
}
void draw_rectangle(void)
{
    printf("\t*****\n");
    printf("\t*   *\n");
    printf("\t*****\n");
}
