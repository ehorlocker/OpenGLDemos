set(SOURCES
	OpenGLDemos.cpp)

set(GLCORE_SOURCES
	GLDemo-Core/src/Core.cpp
	GLDemo-Core/src/Log.cpp)

set(GLUTIL_SOURCES)

set(IMGUI_SOURCES
	GLDemo-Core/vendor/imgui/imgui.cpp
	GLDemo-Core/vendor/imgui/imgui_draw.cpp
	GLDemo-Core/vendor/imgui/imgui_demo.cpp
	GLDemo-Core/vendor/imgui/imgui_tables.cpp
	GLDemo-Core/vendor/imgui/imgui_widgets.cpp
	GLDemo-Core/vendor/imgui/imgui_impl_glfw.cpp
	GLDemo-Core/vendor/imgui/imgui_impl_opengl3.cpp)

set(STB_IMAGE_SOURCES
	GLDemo-Core/vendor/stb_image/stb_image.cpp)

set (GLAD_SOURCES
	GLDemo-Core/vendor/glad/src/glad.c)

set (SCENE_SOURCES
	Scenes/MainMenu/MainMenu.cpp
	Scenes/ClearColor/ClearColor.cpp)

add_executable(OpenGLDemos 
	${SOURCES} 
	${GLCORE_SOURCES} 
	${GLUTIL_SOURCES} 
	${IMGUI_SOURCES}
	${STB_IMAGE_SOURCES}
	${GLAD_SOURCES}
	${SCENE_SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OpenGLDemos PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory("GLDemo-Core/vendor/glfw")
add_subdirectory("GLDemo-Core/vendor/glm")
add_subdirectory("GLDemo-Core/vendor/spdlog")

target_include_directories(${PROJECT_NAME}
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/include
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Util/include
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/vendor/imgui
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/vendor/glad/include
		${CMAKE_CURRENT_SOURCE_DIR}/Scenes/MainMenu
		${CMAKE_CURRENT_SOURCE_DIR}/Scenes/ClearColor
		glm
		glfw
		spdlog
)

target_link_libraries(${PROJECT_NAME} 
	glm
	glfw
	spdlog
)
