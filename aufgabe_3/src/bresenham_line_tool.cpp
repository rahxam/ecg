#include "bresenham_line_tool.h"
#include <algorithm>
#include <math.h>

// Initialize the tool and store a reference of a canvas_store
bresenham_line_tool::bresenham_line_tool(canvas_store& canvas): abstract_tool(canvas)
{
	// This tool draws lines!
	shape = TS_LINE;
}


/* signum function */
int sgn(int x){
  return (x > 0) ? 1 : (x < 0) ? -1 : 0;
}
 

// Draw a line from (x0, y0) to (x1, y1)
void bresenham_line_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Task 3.1.2.    Implement the Bresenham algorithm to raster a line from (x0, y0)
	               to (x1, y1). To set a pixel use "canvas.set_pixel(x, y)" where
				   "x" and "y" is the desired pixel position. This method 
				   handles border violations. Establish the standard case in the
				   first step. If you need to swap the value of two variables you
				   can use the method "std::swap(a, b)".
	Aufgabe 3.1.2. Implementieren Sie den Bresenham-Algorithmus um eine Linie von
	               (x0, y0) nach (x1, y1) zu rastern. Verwenden Sie
				   "canvas.set_pixel(x, y)" um einen Pixel zu setzen, wobei
				   "x" und "y" den gewünschten Pixelpositionen entsprechen.
				   Diese Methode behandelt auch Randverletzungen. Stellen Sie zunaechst
				   den Standardfall her. Falls Sie den Wert zweier Variablen vertauschen
				   muessen koennen Sie dafür die Methode "std::swap(a, b)" verwenden.
   *************/

int x, y, t, dx, dy, incx, incy, pdx, pdy, ddx, ddy, es, el, err;
 
/* Entfernung in beiden Dimensionen berechnen */
   dx = x1 - x0;
   dy = y1 - y0;
 
/* Vorzeichen des Inkrements bestimmen */
   incx = sgn(dx);
   incy = sgn(dy);
   if(dx<0) dx = -dx;
   if(dy<0) dy = -dy;
 
/* feststellen, welche Entfernung größer ist */
   if (dx>dy)
   {
      /* x ist schnelle Richtung */
      pdx=incx; pdy=0;    /* pd. ist Parallelschritt */
      ddx=incx; ddy=incy; /* dd. ist Diagonalschritt */
      es =dy;   el =dx;   /* Fehlerschritte schnell, langsam */
   } else
   {
      /* y ist schnelle Richtung */
      pdx=0;    pdy=incy; /* pd. ist Parallelschritt */
      ddx=incx; ddy=incy; /* dd. ist Diagonalschritt */
      es =dx;   el =dy;   /* Fehlerschritte schnell, langsam */
   }
 
/* Initialisierungen vor Schleifenbeginn */
   x = x0;
   y = y0;
   err = el/2;
   canvas.set_pixel(x, y);
 
/* Pixel berechnen */
   for(t=0; t<el; ++t) /* t zaehlt die Pixel, el ist auch Anzahl */
   {
      /* Aktualisierung Fehlerterm */
      err -= es; 
      if(err<0)
      {
          /* Fehlerterm wieder positiv (>=0) machen */
          err += el;
          /* Schritt in langsame Richtung, Diagonalschritt */
          x += ddx;
          y += ddy;
      } else
      {
          /* Schritt in schnelle Richtung, Parallelschritt */
          x += pdx;
          y += pdy;
      }
      canvas.set_pixel(x, y);
   }
}




// Put debug output into the stream "stream" to be displayed in the
// main window
void bresenham_line_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Bresenham-Line (click and drag mouse to draw)";
}