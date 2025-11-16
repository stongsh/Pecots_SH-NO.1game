#pragma execution_character_set("utf-8")//将字符集设置为utf-8
#include<gl/glew.h>
#include<GLFW/glfw3.h>
#include<iostream>
void init(GLFWwindow* window) {}//初始化窗口函数
void display(GLFWwindow* window, double currentTime)//绘制函数
{
	glClearColor(0.0f, 0.0f, 0.0, 0.0f);//调整背景颜色(红色,绿色,蓝色,透明度)
	glClear(GL_COLOR_BUFFER_BIT);//清除颜色缓冲区
}
int main(void) {
	glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 4);//设置Opengl的主版本号
	glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 6);//设置Opengl的次版本号
	if (!glfwInit()) { std::exit(EXIT_FAILURE); }//初始化GLFW库失败则退出程序
	GLFWwindow* window = glfwCreateWindow(800, 800, "乒乓球大招版", NULL, NULL);//创建一个窗口（宽度，高度，名称,主播不知道，主播不知道）
	glfwMakeContextCurrent(window);//联系上下文
	if (glewInit() != GLEW_OK) { std::exit(EXIT_FAILURE); }//初始化GLEW库失败则退出程序
	init(window);//调用初始化窗口函数
	while(!glfwWindowShouldClose(window))//当窗口没有关闭时循环绘制
	{
		display(window, glfwGetTime());//调用绘制函数
		glfwSwapBuffers(window);//交换前后缓冲区
		glfwPollEvents();//检查是否有触发事件
	}
	glfwDestroyWindow(window);//销毁窗口
	glfwTerminate();//终止GLFW库
	return 0;

}
