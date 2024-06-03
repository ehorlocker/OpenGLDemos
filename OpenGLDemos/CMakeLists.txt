set(SOURCES
	OpenGLDemos.cpp)

set(GLCORE_LOG_SOURCES
	GLDemo-Core/Logger/Log.cpp
	GLDemo-Core/Logger/OpenGLDebug.cpp)

set(GLCORE_VB_SOURCES
	GLDemo-Core/VertexBuffer/VertexBuffer.cpp
	GLDemo-Core/VertexBuffer/StaticVertexBuffer.cpp
	GLDemo-Core/VertexBuffer/DynamicVertexBuffer.cpp)

set(GLCORE_VA_SOURCES
	GLDemo-Core/VertexArray/VertexArray.cpp)

set(GLCORE_IB_SOURCES
	GLDemo-Core/IndexBuffer/IndexBuffer.cpp
	GLDemo-Core/IndexBuffer/StaticIndexBuffer.cpp
	GLDemo-Core/IndexBuffer/DynamicIndexBuffer.cpp)

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
	Scenes/ClearColor/ClearColor.cpp
	Scenes/BatchRendering/BatchRendering.cpp)

add_executable(OpenGLDemos 
	${SOURCES} 
	${GLCORE_LOG_SOURCES} 
	${GLCORE_VB_LAYOUT_SOURCES}
	${GLCORE_VA_SOURCES}
	${GLCORE_IB_SOURCES}
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
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/Logger
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/VertexBuffer
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/VertexBufferLayout
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/VertexArray
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/IndexBuffer
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Util/include
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/vendor/imgui
		${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/vendor/glad/include
		${CMAKE_CURRENT_SOURCE_DIR}/Scenes/MainMenu
		${CMAKE_CURRENT_SOURCE_DIR}/Scenes/ClearColor
		${CMAKE_CURRENT_SOURCE_DIR}/Scenes/BatchRendering
		glm
		glfw
		spdlog
)

target_link_libraries(${PROJECT_NAME} 
	glm
	glfw
	spdlog
)
