/*************************************************************************
The main program.
This class provides the functionality of the main program. The program
starts after calling the "run" method. This method initializes the GLUT
system for rendering (using OpenGL) and user interaction. During the
initialization process different methods are connected to certain events
such as "display the window content", "act on mouse motion and buttons"
or "act on key events". Furthermore the main context menu is initialized
by calling the method "setup_context_menu".
Whenever one of the events described above occurs the appropriate functions
are called (They are however not called directly but via static functions
that forward the event. Read the included PDF if you are interested why
this is done and how it works). 
The class maintains an instance of an abstract_tool which is initialized
to a concrete tool in the "context_menu_select" method. 
The rendering of the canvas is done by an instance of "canvas_renderer" 
while the data storage and modification operations are part of the class
"canvas_store".
**************************************************************************/

#pragma once


// Needed for openGL rendering and GLUT commands
#include "GL/glut.h"
// Needed for displaying text in the main window
#include "GL/freeglut_ext.h"

// Provides the storage for the pixels
#include "canvas_store.h"
// Renders the canvas_store
#include "canvas_renderer.h"

// An abstract tool that needs to be concretized
#include "abstract_tool.h"
// A helper class responsible for rendering the tool previews
#include "preview_renderer.h"


// An enumeration of menu actions. Whenever something
// from the context menu is selected the method "context_menu_select"
// is invoked with an element of this enumeration as a parameter
enum MenuActions 
{
	MA_TOOL_PEN = 1,				// use pen tool
	MA_TOOL_DDA_LINE,				// use dda-line tool
	MA_TOOL_BRESENHAM_LINE,			// use bresenham-line tool
	MA_TOOL_CIRCLE,					// use bresenham-circle tool
	MA_TOOL_RECTANGLE,				// use box tool
	MA_FILL_RECURSIVE,				// use recursive fill tool
	MA_FILL_NONRECURSIVE,			// use non-recursive fill tool
	MA_FILL_LINE,					// use line-fill tool
	MA_CLEAR_CANVAS,				// clear the canvas
	MA_TEST_SHAPE,					// draw the test shape
	MA_RESET_VIEW					// reset translation and zoom
};



class application
{
public:
	// Initialize all non-GLUT related variables
	application();

	// Destroy allocated objects
	~application();

	// Run the program using the command line arguments
	int run(int argc, char* argv[]);

private:
	// The storage for the pixels
	canvas_store *canvas;
	// The renderer for the pixels
	canvas_renderer *renderer;
	// A preview helper class
	preview_renderer preview;
	// The current tool
	abstract_tool *tool;

	// When drag operations are used (lines, circles...) then
	// start_gx and start_gy store the start coordinates in grid units
	int start_gx, start_gy;
	// This flag indicates whether drag operations are running
	bool is_dragging;
	// Last seen mouse position
	int last_mouse_x, last_mouse_y;
	// True if the canvas is translated when the mouse is moved
	bool is_scroll_mode;


	// The static instance of this program. Read the PDF for more details
	static application *instance;

	// Set the current tool
	void set_tool(abstract_tool *new_tool);

	// The event method on key presses
	void key_down(unsigned char key, int x, int y);

	// The event method on mouse button presses
	void mouse_button(int button, int state, int x, int y);

	// The event method on mouse motions
	void mouse_move(int x, int y);

	// The event method on mouse wheel rotations
	void mouse_wheel(int button, int dir, int x, int y);

	// The event method on context menu selections
	void context_menu_select(int item);

	// The event method on window content rendering
	void display();

	// Initialize the context menu
	void setup_context_menu();

	// Static callbacks...
	static void key_down_callback(unsigned char key, int x, int y);
	static void mouse_button_callback(int button, int state, int x, int y);
	static void mouse_move_callback(int x, int y);
	static void mouse_wheel_callback(int button, int dir, int x, int y);
	static void context_menu_callback(int item);
	static void display_callback();

};