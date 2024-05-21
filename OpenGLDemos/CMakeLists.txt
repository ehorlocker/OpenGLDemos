set(SOURCES
	OpenGLDemos.cpp)

set(GLCORE_SOURCES
	GLDemo-Core/src/Core.cpp)

set(GLUTIL_SOURCES)

set(IMGUI_SOURCES
	GLDemo-Core/vendor/imgui/imgui.cpp
	GLDemo-Core/vendor/imgui/imgui_draw.cpp
	GLDemo-Core/vendor/imgui/imgui_demo.cpp
	GLDemo-Core/vendor/imgui/imgui_tables.cpp
	GLDemo-Core/vendor/imgui/imgui_widgets.cpp)

set(STB_IMAGE_SOURCES
	GLDemo-Core/vendor/stb_image/stb_image.cpp)

set (GLAD_SOURCES
	GLDemo-Core/vendor/glad/src/glad.c)

add_executable(OpenGLDemos 
	${SOURCES} 
	${GLCORE_SOURCES} 
	${GLUTIL_SOURCES} 
	${IMGUI_SOURCES}
	${STB_IMAGE_SOURCES}
	${GLAD_SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OpenGLDemos PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory("GLDemo-Core/vendor/glfw")
add_subdirectory("GLDemo-Core/vendor/glm")

target_include_directories(${PROJECT_NAME}
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/include
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Util/include
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/vendor/imgui
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/vendor/glad/include
		glm
		glfw
)

target_link_libraries(${PROJECT_NAME} 
	glm
	glfw
)
