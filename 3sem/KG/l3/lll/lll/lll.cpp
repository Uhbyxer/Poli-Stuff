/* FERN.C   -- Generates fractal fern leaf.  Initial coding by John Watne
 *             1/20/92.
 */

#include <stdio.h>
#include <graph.h>
#include <stdlib.h>
#include <conio.h>

#define MAXIT 20
/* maximum number of iterations */
#define TRUE 1

main()
{
   struct videoconfig vc;      /* video configuration -- is it VGA? */
   double      x, y, newx, newy;
   unsigned i; /* counter variable */
   int   rand_num;
   
   _getvideoconfig (&vc);
   if (vc.adapter != _VGA)
   {
      printf ("No VGA adapter.  Program halted.\n");
      exit (1);
   }
   _setvideomode (_VRES16COLOR); /* 640x480, 16-color */
   _remappalette (0, _BLACK);
   _remappalette (1, _LIGHTGREEN);
   _setcolor (1);
   /* Set up viewport */
   _setviewport (0, 0, 640, 640);
   /* Set up window coordinate system */
   _setwindow (TRUE, -5, 0, 5, 10);
   srand (0);
   while (!kbhit())
   {
      x = (double) rand() / 50000.0;
      y = (double) rand() / 50000.0;
      for (i = 0; i < MAXIT; i++)
      {
         rand_num = rand();
         if (rand_num < 0.01 * RAND_MAX)
         {
            newx = 0;
            newy = 0.16 * y;
            x = newx;
            y = newy;
         }
         else
            if (rand_num < 0.86 * RAND_MAX)
            {
               newx = (0.85 * x) + (0.04 * y);
               newy = (-0.04 * x) + (0.85 * y) + 1.6;
               x = newx;
               y = newy;
            }
            else
               if (rand_num < 0.93 * RAND_MAX)
               {
                  newx = (0.2 * x) - (0.26 * y);
                  newy = (0.23 * x) + (0.22 * y) + 1.6;
                  x = newx;
                  y = newy;
               }
               else
                  {
                     newx = (-0.15 * x) + (0.28 * y);
                     newy = (0.26 * x) + (0.24 * y) + 0.44;
                     x = newx;
                     y = newy;
                  }
      }  /* for loop */
      if ((x >= -5.0) && (x <= 5.0) && (y >= 0.0) && (y <= 10.0))
         _setpixel_w (x, y);
   }  /* while (!kbhit()) */
   if (getch() == 0)
      getch();
   _setvideomode (_TEXTC80);
}