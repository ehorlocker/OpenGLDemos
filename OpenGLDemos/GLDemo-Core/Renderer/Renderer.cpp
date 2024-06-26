#include "Renderer.h"
#include "glad/glad.h"

namespace GLCore {
	void Renderer::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
}