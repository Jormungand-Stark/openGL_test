//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow *window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//const char *vertexShaderSource = "#version 330 core\n"
//    "layout (location = 0) in vec3 aPos;\n"
//    "out vec4 vertexColor;\n"
//    "void main()\n"
//    "{\n"
//    "   gl_Position = vec4(aPos, 1.0);\n"
//    "   vertexColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
//    "}\n\0";
//
//const char *fragmentShader1Source = "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "in vec4 vertexColor;\n"
//    "void main()\n"
//    "{\n"
//    "   FragColor = vertexColor;\n"
//    "}\n\0";
//const char *fragmentShader2Source = "#version 330 core\n"
//    "out vec4 FragColor;\n"
//    "void main()\n"
//    "{\n"
//    "   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//    "}\n\0";
//
//int main()
//{
//    // glfw: initialize and configure
//    // ------------------------------
//    glfwInit();
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//    // glfw window creation
//    // --------------------
//    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//    if (window == NULL)
//    {
//        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
//        return -1;
//    }
//    glfwMakeContextCurrent(window);
//    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//    // glad: load all OpenGL function pointers
//    // ---------------------------------------
//    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//    {
//        std::cout << "Failed to initialize GLAD" << std::endl;
//        return -1;
//    }
//
//
//    // build and compile our shader program
//    // ------------------------------------
//    // vertex shader
//    int success; // 定义一个整型变量来表示是否成功编译
//    char infoLog[512]; // 储存错误消息
//    
//    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//    unsigned int fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
//    unsigned int fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
//    unsigned int shaderProgramOrange = glCreateProgram();
//    unsigned int shaderProgramYellow = glCreateProgram();
//    
//    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//    glCompileShader(vertexShader);
//    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    
//    glShaderSource(fragmentShaderOrange, 1, &fragmentShader1Source, NULL);
//    glCompileShader(fragmentShaderOrange);
//    glGetShaderiv(fragmentShaderOrange, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShaderOrange, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRANGMENT1::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    
//    glShaderSource(fragmentShaderYellow, 1, &fragmentShader2Source, NULL);
//    glCompileShader(fragmentShaderYellow);
//    glGetShaderiv(fragmentShaderYellow, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(fragmentShaderYellow, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::FRANGMENT2::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    
//    glAttachShader(shaderProgramOrange, vertexShader);
//    glAttachShader(shaderProgramOrange, fragmentShaderOrange);
//    glLinkProgram(shaderProgramOrange);
//    glGetShaderiv(shaderProgramOrange, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(shaderProgramOrange, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM1::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//    
//    glAttachShader(shaderProgramYellow, vertexShader);
//    glAttachShader(shaderProgramYellow, fragmentShaderYellow);
//    glLinkProgram(shaderProgramYellow);
//    glGetShaderiv(shaderProgramYellow, GL_COMPILE_STATUS, &success);
//    if (!success)
//    {
//        glGetShaderInfoLog(shaderProgramOrange, 512, NULL, infoLog);
//        std::cout << "ERROR::SHADER::PROGRAM2::COMPILATION_FAILED\n" << infoLog << std::endl;
//    }
//                   
//    // 设置顶点数据（和缓冲区）并配置顶点属性
//    // ------------------------------------------------------------------
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
//    unsigned int VBOs[2], VAOs[2];
//    glGenVertexArrays(2, VAOs); // we can also generate multiple VAOs or buffers at the same time
//    glGenBuffers(2, VBOs);
//    // first triangle setup
//    // --------------------
//    glBindVertexArray(VAOs[0]);
//    glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//    glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);    // Vertex attributes stay the same
//    glEnableVertexAttribArray(0);
//    // glBindVertexArray(0); // no need to unbind at all as we directly bind a different VAO the next few lines
//    // second triangle setup
//    // ---------------------
//    glBindVertexArray(VAOs[1]);    // note that we bind to a different VAO now
//    glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);    // and a different VBO
//    glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0); // because the vertex data is tightly packed we can also specify 0 as the vertex attribute's stride to let OpenGL figure it out
//    glEnableVertexAttribArray(0);
//    // glBindVertexArray(0); // not really necessary as well, but beware of calls that could affect VAOs while this one is bound (like binding element buffer objects, or enabling/disabling vertex attributes)
//
//
//    // uncomment this call to draw in wireframe polygons.
//    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//    // render loop
//    // -----------
//    while (!glfwWindowShouldClose(window))
//    {
//        // input
//        // -----
//        processInput(window);
//
//        // render
//        // ------
//        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT);
//
//        glUseProgram(shaderProgramOrange);
//        // draw first triangle using the data from the first VAO
//        glBindVertexArray(VAOs[0]);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
//        // then we draw the second triangle using the data from the second VAO
//        glUseProgram(shaderProgramYellow);
//        glBindVertexArray(VAOs[1]);
//        glDrawArrays(GL_TRIANGLES, 0, 3);
// 
//        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//        // -------------------------------------------------------------------------------
//        glfwSwapBuffers(window);
//        glfwPollEvents();
//    }
//
//    // optional: de-allocate all resources once they've outlived their purpose:
//    // ------------------------------------------------------------------------
//    glDeleteVertexArrays(2, VAOs);
//    glDeleteBuffers(2, VBOs);
//    glDeleteProgram(shaderProgramOrange);
//    glDeleteProgram(shaderProgramYellow);
//
//    // glfw: terminate, clearing all previously allocated GLFW resources.
//    // ------------------------------------------------------------------
//    glfwTerminate();
//    return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow *window)
//{
//    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//        glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//    // make sure the viewport matches the new window dimensions; note that width and
//    // height will be significantly larger than specified on retina displays.
//    glViewport(0, 0, width, height);
//}
