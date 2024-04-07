#include<GLEW/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
using namespace std;

void initOpenGLWindow(GLFWwindow* glfwWindow) { }

void displayWindow(GLFWwindow* glfwWindow) {
	// 预先指定填充颜色
	glClearColor(1.0, 0.0, 0.0, 1.0);  
	// 清除颜色缓冲
	glClear(GL_COLOR_BUFFER_BIT);     
}

int main(void) {
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}

	// OpenGL 版本 4.3 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);  //主版本号
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);  //次版本号

	// 创建窗口极其上下文
	// 上下文的含义是：OpenGL实例及其状态的信息，其中包括诸如颜色缓冲区之类的项
	GLFWwindow* OpenglWindow = glfwCreateWindow(600, 600, "Chapter2-Program1", NULL, NULL);
	// 关联窗口与其上下文
	glfwMakeContextCurrent(OpenglWindow);  

	if (glewInit() != GLEW_OK) {
		exit(EXIT_FAILURE);
	}

	// 开启垂直同步
	glfwSwapInterval(1); 
	initOpenGLWindow(OpenglWindow);

	while (!glfwWindowShouldClose(OpenglWindow))
	{
		displayWindow(OpenglWindow);
		// 双缓冲机制下交换缓冲
		glfwSwapBuffers(OpenglWindow); 
		// 处理窗口相关事件例如按键
		glfwPollEvents();				
	}

	// 销毁当前窗口和上下文
	glfwDestroyWindow(OpenglWindow);
	// 销毁剩余的全部部分
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
