#pragma once

#include "abstract_scene.h"

class example_trans_order: public abstract_scene
{
public:
	example_trans_order();
	void render();
	void set_text(stringstream &stream);
	void advance_frame();

private:
	int angle;
	void render_quad();
};