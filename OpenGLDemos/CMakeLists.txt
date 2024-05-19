# CMakeList.txt : CMake project for OpenGLDemos, include source and define
# project specific logic here.
#

set(SOURCES
	OpenGLDemos.cpp)
set(GLCORE_SOURCES
	GLDemo-Core/src/Core.cpp)
set(GLUTIL_SOURCES)
add_executable (OpenGLDemos ${SOURCES} ${GLCORE_SOURCES} ${GLUTIL_SOURCES})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET OpenGLDemos PROPERTY CXX_STANDARD 20)
endif()

add_subdirectory("GLDemo-Core/vendor/glfw")
add_subdirectory("GLDemo-Core/vendor/glm")

target_include_directories(${PROJECT_NAME}
	${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/include
	${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Util/include
	${CMAKE_CURRENT_SOURCE_DIR}/GLDemo-Core/vendor/imgui
	glm
	glfw
)

target_link_libraries(${PROJECT_NAME} 
	glm
	glfw
)
