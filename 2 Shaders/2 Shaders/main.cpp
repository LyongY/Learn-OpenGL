//
//  main.cpp
//  2 Shaders
//
//  Created by Raysharp666 on 2018/6/4.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#include <iostream>
#include "LYWindow.hpp"
#include "LYTriangle.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    LYWindow window = LYWindow(400, 300, "Shaders");
    
    vector<float> vertex = {
        -1,0.0,0,
        -1,1,0,
        -0.5,1,0,
    };
    vector<float> color = {1,0,0,1};
    LYTriangle triangle = LYTriangle(vertex, color);
    
    
    float colorVertex[] {
        // 位置              // 颜色
        0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
        -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
        0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
    };
    
    const char* vertexShaderSource = "\
    #version 330 core\n\
    layout (location = 0) in vec3 aPos;\n\
    layout (location = 1) in vec3 aColor;\n\
    out vec3 ourColor;\n\
    void main() {\n\
    gl_Position = vec4(aPos, 1.0);\n\
    ourColor = aColor;\n\
    }";
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    const char* fragmentShaderSource = "\
    #version 330 core\n\
    in vec3 ourColor;\n\
    out vec4 aColor;\n\
    void main() {\n\
    aColor = vec4(ourColor, 1.0);\n\
    }";
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(colorVertex), colorVertex, GL_STATIC_DRAW);
    
    //位置
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    //颜色
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    window.render([&](){
        triangle.render();
        
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    });
    return 0;
}
