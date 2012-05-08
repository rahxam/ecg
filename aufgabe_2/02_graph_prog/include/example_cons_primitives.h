#pragma once

#include "abstract_scene.h"

class example_consecutive_primitives: public abstract_scene 
{
public:
	void render();
	void set_text(stringstream &stream);
};