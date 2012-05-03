#pragma once

#include "abstract_scene.h"

class example_3d_primitives: public abstract_scene
{
public:
	example_3d_primitives();
	void render();
	void set_text(stringstream &stream);
	void advance_frame();

private:
	int angle;

	void render_tetrahedron();
	void render_cylinder();
	void render_cube();
	void render_sphere();

	void setup_projection();
	void setup_light();
};