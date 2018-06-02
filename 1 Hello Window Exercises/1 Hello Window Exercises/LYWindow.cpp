//
//  LYWindow.cpp
//  1 Hello Window Exercises
//
//  Created by Raysharp666 on 2018/6/2.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#include "LYWindow.hpp"
#include <iostream>

using namespace std;

GLFWwindow* initGLFWWindow(int width, int height, const char *title);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

LYWindow::LYWindow(float width, float height, const char *title) {
    _window = initGLFWWindow(width, height, title);
    
}

void LYWindow::render() {
    while (!glfwWindowShouldClose(_window)) {
        processInput(_window);
        
        glClearColor(0.2, 0.3, 0.3, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        iterator<<#class _Category#>, <#class _Tp#>> v = _VAOArr.begin();
        
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
}





GLFWwindow* initGLFWWindow(int width, int height, const char *title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        cout << "Failed to create GLFW window" << endl;
        exit(-1);
    }
    
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        cout << "Failed to initialize GLAD" << endl;
        exit(-1);
    }
    
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
