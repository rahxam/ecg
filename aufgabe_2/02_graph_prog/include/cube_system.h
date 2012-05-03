/*************************************************************************
Cube system.
This class represent a simple system of cubes which rotate around each
other. It demonstrates the use of glPushMatrix and glPopMatrix to 
describe transformation trees. 
The actual rendering happens in the "render" method first calls
"setup_projection" to enable a perspective projection and suitable
viewer position. It then clears the screen and renders the cube system
by calling "render_system". For the rendering of one cube this method calls
"render_cube".
See "abstract_scene" for more information on scenes.
*************************************************************************/
#pragma once

#include "abstract_scene.h"

class cube_system: public abstract_scene
{
public:
	// Initialize variables
	cube_system();

	// Setup the scene and render cube system
	virtual void render();

	// Advance one frame by increasing the rotation angle
	void advance_frame();

	// Set debug text
	virtual void set_text(stringstream &stream);

protected:
	// The current rotation angle
	int angle;

	// Set the projection and the view
	void setup_projection();

	// Render the cube system
	void render_system();

	// Render one single cube
	void render_cube();
};