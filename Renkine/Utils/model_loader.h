#ifndef RENKINE_MATH_MODEL_LOADER_H
#define RENKINE_MATH_MODEL_LOADER_H

#include <Renkine\Types\graphics_types.h>
#include <Renkine\Graphics\mesh_creator.h>
namespace renkine
{
	class ModelLoader 
	{
	public:
		static Mesh *LoadOBJ (char filepath[]);
	};
}

#endif  // RENKINE_MATH_MODEL_LOADER_H
