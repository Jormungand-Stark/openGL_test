////
////  main.cpp
////  OpenGL
////
////  Created by Jormungand on 2022/7/15.
////
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <iostream>
//#include <cmath>
//#include <glm/glm.hpp>
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
//    std::cout << "是否点击ESC?" << std::endl;
//    std::cout << glfwGetKey(window, GLFW_KEY_ESCAPE) << std::endl;
//    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        // 被按下则将 WindowShouldClose 属性置为 true
//        // 以便于在关闭 渲染循环
//        glfwSetWindowShouldClose(window, true);
//}
//
//const unsigned int SCR_WIDTH = 800; // 创建窗口的宽
//const unsigned int SCR_HEIGHT = 600; // 创建窗口的高
//
///* 用着色器语言GLSL编写顶点着色器，方便后续动态编译 */
//// gl_Position是一个vec4类型变量，是后续处理顶点着色器输出的关键
//// 初始化：将location赋给gl_Position，
//const char *vertexShaderSource = "#version 330 core\n"
//    "layout (location = 0) in vec3 point;\n"
//    "void main()\n"
//    "{\n"
//    "   gl_Position = vec4(point.x, point.y, point.z, 1.0);\n"
//    "}\0";
///* 片段着色器 */
//const char *fragmentShaderSource = "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "uniform vec4 ourColor;\n"
//    "void main()\n"
//    "{\n"
//    "   FragColor = ourColor;\n"
//    "}\n\0";
//const char *fragmentShader2Source = "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "void main()\n"
//    "{\n"
//    "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//    "}\n\0";
//
//int main(){
//    cout << "Loading" << endl;
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
////    float vertices[] = {
////         0.5f,  0.5f, 0.0f,  // top right
////         0.5f, -0.5f, 0.0f,  // bottom right
////        -0.5f, -0.5f, 0.0f,  // bottom left
////        -0.5f,  0.5f, 0.0f   // top left
////    };
//    float firstTriangle[] = {
//        -0.9f, -0.5f, 0.0f,  // left
//        -0.0f, -0.5f, 0.0f,  // right
//        -0.45f, 0.5f, 0.0f,  // top
//    };
//    float secondTriangle[] = {
//        0.0f, -0.5f, 0.0f,  // left
//        0.9f, -0.5f, 0.0f,  // right
//        0.45f, 0.5f, 0.0f   // top
//    };
//
//
////    unsigned int indices[] = {  // note that we start from 0!
////        0, 1, 2,  // first Triangle
////        1, 3, 4   // second Triangle
////    };
//
//    unsigned int VBOs[2], VAOs[2], EBO[2];
//    glGenVertexArrays(2, VAOs);
//    glGenBuffers(2, VBOs); // 生成一个 VBO 对象
////    glGenBuffers(1, EBO);
//
//    /* 首先绑定顶点数组对象，然后绑定并设置顶点缓冲区，然后配置顶点属性。 */
//    glBindVertexArray(VAOs[0]);
//
//    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]); // 确定生成的缓冲对象的类型
//    // 把顶点数据复制到缓冲的内存中
//    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//
//    // layout(location=0), 每个顶点的pos属性（vec*）由3个组件构成,
//    //（vec*）中的值的类型为GL_FLOAT, 转换为固定点值, 第一个组件的偏移量为0
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // glBindVertexArray(0); // 不需要解绑，因为接下来直接绑定了不同的VAO
//
//    /*  second triangle */
//    glBindVertexArray(VAOs[1]);
//    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//    glEnableVertexAttribArray(0);
//    // glBindVertexArray(0);
//
////    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO); // 确定生成的缓冲对象类型
////    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); // 数据复制到缓冲中
//
//    /* 着色器 */
//    // VERTEX_SHADER 顶点着色器
//    // glCreateShader函数参数：要创建的着色器类型
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//
//    // 检查着色器编译错误
//    int success; // 定义一个整型变量来表示是否成功编译
//    char infoLog[512]; // 储存错误消息
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    // glGetShaderiv 检查是否编译成功。
//    // 如果编译失败则调用 glGetShaderInfoLog 获取错误消息，并且打印。
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    // FRAGMENT_SHADER 片段着色器
//    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//    glCompileShader(fragmentShader);
//
//    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//    if (!success) {
//        glGetProgramInfoLog(fragmentShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//
//    // 着色器程序对象
//    unsigned int shaderProgram = glCreateProgram();
//    glAttachShader(shaderProgram, vertexShader);
//    glAttachShader(shaderProgram, fragmentShader);
//    glLinkProgram(shaderProgram);
//
//    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//    if(!success) {
//        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//    }
//
//    glDeleteShader(vertexShader);
//    glDeleteShader(fragmentShader);
//
//    /*  把顶点数据链接到顶点着色器的顶点属性上 */
//
//
//    // 对glVertexAttribPointer的调用将VBO注册为顶点属性的绑定顶点缓冲区对象，因此之后我们可以安全地解除绑定
////    glBindBuffer(GL_ARRAY_BUFFER, 0); // 确定生成的缓冲对象类型
//
//    // 当VAO处于活动状态时，不要解除EBO的绑定，因为绑定的元素缓冲区对象存储在VAO中，会导致渲染失败。
//    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
//
//    /* 绑定VAO（它已经绑定，这里只是为了演示有多个VAO时，在渲染相应的三角形之前预先绑定对应VAO） */
////    glBindVertexArray(VAO);
//
////    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
////    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
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
//
////        glBindVertexArray(VAOs[0]);
////        glDrawArrays(GL_TRIANGLES, 0, 3);
//        glBindVertexArray(VAOs[1]);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//
//        // 更新着色器统一
//        double timeVaule = glfwGetTime();
//        float greenValue = static_cast<float>(sin(timeVaule) / 2.0 + 0.5);
//        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
//        // 确保在调用glUniform之前激活着色器
//        glUseProgram(shaderProgram);
//        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
//
//
//        // 渲染三角形/多边形
////        glDrawArrays(GL_TRIANGLES, 0, 6);
//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
////    glDeleteBuffers(1, &EBO);
//    glDeleteProgram(shaderProgram);
//
//    glfwTerminate();
//
//    return 0;
//}
