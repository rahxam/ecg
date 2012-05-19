#include "recursive_fill_tool.h"
#include <iostream>
#include <windows.h>


// Initialize the tool and store a reference of a canvas_store
recursive_fill_tool::recursive_fill_tool(canvas_store& canvas): abstract_tool(canvas)
{
	// This tool has no shape and is not draggable
	shape = TS_NONE;
	is_draggable = false;
}

// Fill the shape that contains the point (x, y)
void recursive_fill_tool::draw(int x, int y)
{
	/************
	Task 3.2.1.    Implement the recursive fill algorithm by checking the
	               state of the neighbouring pixels (via "canvas.get_pixel(x, y)"
				   where "x" and "y" defines the position to check) and recursively
				   call "draw" if the pixel is not set. A pixel can be set with
				   "canvas.set_pixel(x, y)".
				   This method will make the application crash if the area which shall 
				   be filled is too big.
    Aufgabe 3.2.1. Implementieren Sie den rekursiven Füllalgorithmus, indem Sie den
	               Zustand der Nachbarpixel überprüfen (mittels "canvas.get_pixel(x, y)"
				   wobei "x" und "y" die Position des zu überprüfenden Pixels definieren)
				   und rufen Sie rekursiv die "draw"-Methode auf, wenn die Pixel nicht 
				   gesetzt sind. Ein Pixel kann durch "canvas.set_pixel(x, y)" gesetzt
				   werden.
	*************/
	depth = 1;
	draw(x,y,1);
	std::cout << "Rekursionstiefe: " << depth << std::endl;
}

// Fill the shape that contains the point (x, y)
void recursive_fill_tool::draw(int x, int y, int d)
{

	if(!canvas.get_pixel(x, y)) {
		canvas.set_pixel(x, y);
		if(x+1 < canvas.get_width()) draw(x+1,y,d+1);
		if(x > 1) draw(x-1,y,d+1);
		if(y+1 < canvas.get_height()) draw(x,y+1,d+1);
		if(y > 1) draw(x,y-1,d+1);
	} else {
		if(depth < d) depth = d;
		return;
	}
}



// Put debug output into the stream "stream" to be displayed in the
// main window
void recursive_fill_tool::set_text(stringstream& stream)
{
	stream<<"Tool: Recursive Fill (click to fill)";
}