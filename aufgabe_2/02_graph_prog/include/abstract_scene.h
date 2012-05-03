/*************************************************************************
Abstract scene.
This class provides the basic super class for all scenes. To render a
frame of the implemented scene the method "render" must be called. If
the scene is animated the method "advance_frame" can be overwritten. It
is called every 1/30sec (from the application-class).
For debugging purpose a method "set_text" is provided which modifies a
text stream that will be displayed in the main window.
*************************************************************************/
#pragma once

#include <sstream>
#include <iostream>
#include "GL/glut.h"

using namespace std;

class abstract_scene
{
public:
	// Render the scene
	virtual void render() = 0;

	// Advance one frame
	virtual void advance_frame();

	// Put a text into the stream "stream" which will be displayed
	// in the main window
	virtual void set_text(stringstream &stream);
};