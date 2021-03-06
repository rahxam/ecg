/*************************************************************************
Abstract tool.
This class provides the basic superclass for all tools (pen, lines, circle...)
The constructor of the class takes a reference of a canvas_store as parameter
on which the pixels are changed. 
The user of an instance of a derived class can use two different draw methods:
One version that operates only with the information of a single position
(e.g. the pen or the fill tools) and one that needs two pixel positions
(e.g. the line, circle or box). Also every tool maintains an element of
the enumerations of possible shapes (which are used for the preview tool).
For debugging purpose a method "set_text" is provided which modifies a
text stream that will be displayed in the main window.
*************************************************************************/
#pragma once

// needed for the set_text method
#include <sstream>
// declares the canvas_store
#include "canvas_store.h"


using namespace std;

// Enumeration of possible shapes
enum ToolShape
{
	TS_LINE,		// a line
	TS_BOX,			// a box
	TS_CIRCLE,		// a circle
	TS_NONE			// no shape
};




class abstract_tool
{
public:
	// Initialize the tool and store a reference of a canvas_store
	abstract_tool(canvas_store &canvas);

	// Draw with one point provided
	virtual void draw(int x, int y);
	// Draw with two points provided
	virtual void draw(int x0, int y0, int x1, int y1);

	// Get the shape that this tool will draw
	const ToolShape get_shape() const;

	// Put a text into the stream "stream" which will be displayed
	// in the main window
	virtual void set_text(stringstream& stream);

	// Return true if draw(x, y) is valid during dragging operations
	const bool is_tool_draggable() const;

protected:
	// The shape which is initialized in the constructor
	ToolShape shape;
	// A reference of the canvas store
	canvas_store &canvas;

	bool is_draggable;
};