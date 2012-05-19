#include "dda_line_tool.h"
#include <algorithm>


// Initialize the tool and store a reference of a canvas_store
dda_line_tool::dda_line_tool(canvas_store& canvas): abstract_tool(canvas)
{
	shape = TS_LINE;
}


// Draw a line from (x0, y0) to (x1, y1)
void dda_line_tool::draw(int x0, int y0, int x1, int y1)
{
	/************
	Task 3.1.1.    Implement the DDA algorithm to raster a line from (x0, y0)
	               to (x1, y1). To set a pixel use "canvas.set_pixel(x, y)" where
				   "x" and "y" is the desired pixel position. This method 
				   handles border violations. Establish the standard case in the
				   first step. If you need to swap the value of two variables you
				   can use the method "std::swap(a, b)".
	Aufgabe 3.1.1. Implementieren Sie den DDA-Algorithmus um eine Linie von
	               (x0, y0) nach (x1, y1) zu rastern. Verwenden Sie
				   "canvas.set_pixel(x, y)" um einen Pixel zu setzen, wobei
				   "x" und "y" den gewünschten Pixelpositionen entsprechen.
				   Diese Methode behandelt auch Randverletzungen. Stellen Sie zunaechst
				   den Standardfall her. Falls Sie den Wert zweier Variablen vertauschen
				   muessen koennen Sie dafür die Methode "std::swap(a, b)" verwenden.
   *************/

	//Keine senkrechte Linie
	if(x0 != x1) {
		//Steigung berechnen
		float m = (float)(y0-y1)/(x0-x1);

		//Steigung zwischen -1 und 1
		if(m <= 1 && m>= -1) {
			//vertausche die Werte, damit die for-Schleifenbedingung stimmt
			if(x0 > x1) {
				int hilf = y1;
				y1 = y0;
				y0 = hilf;
				hilf = x1;
				x1 = x0;
				x0 = hilf;
			}

			float y = y0;

			for(int x = x0; x<=x1; x++) {
				canvas.set_pixel(x, (int)(y+ 0.5));
				y += m;
			}
		} else {
			//vertausche die Werte, damit die for-Schleifenbedingung stimmt
			if(y0 > y1) {
				int hilf = y1;
				y1 = y0;
				y0 = hilf;
				hilf = x1;
				x1 = x0;
				x0 = hilf;
			}

			float x = x0;

			for(int y = y0; y<=y1; y++) {
				canvas.set_pixel((int)(x+ 0.5), y);
				x = x + (1 / m);
			}
		}

		
	//Senkrechte Linie
	} else {
		//vertausche die Werte, damit die for-Schleifenbedingung stimmt
		if(y0 > y1) {
			int hilf = y1;
			y1 = y0;
			y0 = hilf;
		}
		for(int y = y0; y<=y1; y++) {
			canvas.set_pixel(x0, y);
		}
	}

}




// Put debug output into the stream "stream" to be displayed in the
// main window
void dda_line_tool::set_text(stringstream& stream)
{
	stream<<"Tool: DDA-Line (click and drag mouse to draw)";
}