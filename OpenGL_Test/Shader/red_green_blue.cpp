////
////  red_green_blue.cpp
////  OpenGL_Test
////
////  Created by Jormungand on 2022/9/8.
////
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <cmath>
//#include "Shader.h"
//
//using namespace std;
//
//// 对窗口注册一个回调函数(Callback Function)，它会在每次窗口大小被调整的时候被调用。
//// 参数：window - 被改变大小的窗口，width、height-窗口的新维度。
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // 告诉OpenGL渲染窗口的尺寸大小，即视口(Viewport)
//    // 这样OpenGL才只能知道怎样根据窗口大小显示数据和坐标
//    // 调用glViewport函数来设置窗口的维度(Dimension)
//    // 前两个参数控制窗口左下角的位置。第三个和第四个参数控制渲染窗口的宽度和高度（像素）
//    glViewport(0, 0, width, height);
//}
//
//// 实现输入控制的函数：查询GLFW是否在此帧中按下/释放相关键，并做出相应反应
//void processInput(GLFWwindow *window)
//{
//    // glfwGetKey两个参数：窗口，按键
//    // 没有被按下返回 GLFW_PRESS
//    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        // 被按下则将 WindowShouldClose 属性置为 true
//        // 以便于在关闭 渲染循环
//        glfwSetWindowShouldClose(window, true);
//}
//
//const unsigned int SCR_WIDTH = 800; // 创建窗口的宽
//const unsigned int SCR_HEIGHT = 600; // 创建窗口的高
//
//int main(){
//    glfwInit(); // 初始化GLFW
//
//    // glfwWindowHint函数的第一个参数代表选项的名称
//    // 第二个参数接受一个整型，用来设置这个选项的值
//    // 将主版本号(Major)和次版本号(Minor)都设为3
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    // 使用的是核心模式(Core-profile)
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    // macOS需要本语句生效 glfwWindow 的相关配置
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // 参数依次为：宽、高、窗口的名称,显示器用于全屏模式，设为NULL是为窗口
//    // 窗口的上下文为共享资源，NULL为不共享资源
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "FirstWindow", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        // 释放空间，防止内存溢出
//        glfwTerminate();
//        return -1;
//    }
//
//    // 创建完毕之后，需要让window的context成为当前线程的current context
//    glfwMakeContextCurrent(window);
//    // 窗口大小改变时视口也要随之改变，这通过对窗口注册 framebuffer_size_callback 实现。
//    // 它会在每次窗口大小被调整时调用
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glfwGetProcAddress是glfw提供的用来 加载系统相关的OpenGL函数指针地址 的函数
//    // gladLoadGLLoader函数根据使用者的系统定义了正确的函数
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//    /* 设置顶点数据（和缓冲区）并配置顶点属性 */
//    float vertices[] = {
//        // 位置              // 颜色
//         0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下 红色
//         -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下 绿色
//         0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部 蓝色
//    };
//
//    // build and compile our shader program
//    Shader ourShader("3.3.shader.vs", "3.3.shader.fs"); // you can name your shader files however you like
//
//    unsigned int VBOs[2], VAOs[2];
//    glGenVertexArrays(2, VAOs);
//    glGenBuffers(2, VBOs); // 生成2个 VBO 对象
//
//    /* 首先绑定顶点数组对象，然后绑定并设置顶点缓冲区，然后配置顶点属性。 */
//    glBindVertexArray(VAOs[0]);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]); // 确定生成的缓冲对象的类型
//    // 把顶点数据复制到缓冲的内存中
//    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//    // layout(location=0), 每个顶点的pos属性（vec*）由3个组件构成,
//    //（vec*）中的值的类型为GL_FLOAT, 转换为固定点值, 第一个组件的偏移量为0
//    // 位置
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0); // 启用layout 0
//
//    // 颜色
//    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
//    glEnableVertexAttribArray(1); // 启用layout 1
//
//    /* 渲染循环(Render Loop) */
//    // glfwWindowShouldClose 检查一次GLFW是否被要求退出
//    // 为true时渲染循环结束
//    while(!glfwWindowShouldClose(window))
//    {
//        // 监测键盘输入
//        processInput(window);
//
//        /* 渲染 */
//        // 状态设置函数，设置清空屏幕所用的颜色
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        // 状态使用函数，使用设定好的颜色来清除旧的颜色缓冲
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        // 上面两种函数起到的作用也可以用 glClearBufferfv 来现实
//        /*GLfloat color[] = {0.2, 0.3, 0.3, 1.0};
//        glClearBufferfv(GL_COLOR, 0, color);*/
//        float offset = -1.0f;
//        ourShader.setFloat("x_offset", offset);
//        ourShader.use();
//        glBindVertexArray(VAOs[0]);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        // glfwSwapBuffers 交换颜色缓冲，用来绘制并作为输出显示在屏幕
//        glfwSwapBuffers(window);
//        // glfwPollEvents 检查是否有触发事件
//        glfwPollEvents();
//    }
//
//    // 可选：一旦所有资源超出其用途，则取消分配：
//    glDeleteVertexArrays(2, VAOs);
//    glDeleteBuffers(2, VBOs);
//
//    glfwTerminate();
//
//    return 0;
//}
