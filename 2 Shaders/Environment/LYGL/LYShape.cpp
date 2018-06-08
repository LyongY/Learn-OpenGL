//
//  LYShape.cpp
//  1 Hello Window Exercises
//
//  Created by 001s on 2018/6/3.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#include "LYShape.hpp"
#include <iostream>
#include <glad/glad.h>
#include "LYVertexShader.hpp"
#include "LYFragmentShader.hpp"
#include <GLFW/glfw3.h>
#include <math.h>

LYShape::LYShape(std::vector<float> vertices, std::vector<float> color) {
    
    _vertices = vertices;
    _color = color;
    
    LYVertexShader vertextShader = LYVertexShader();
    LYFragmentShader fragmentShader = LYFragmentShader(color[0], color[1], color[2], color[3]);
    std::vector<LYShader *> shaderVec = {
        (LYShader *)&vertextShader,
        (LYShader *)&fragmentShader,
    };
    _shaderProgram = LYShaderProgram(shaderVec);
    
    glGenVertexArrays(1, &_VAO);
    glBindVertexArray(_VAO);
    
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(float), &vertices[0], GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
     
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void LYShape::render() {
    _shaderProgram.use();
    
    float timeValue = glfwGetTime();
    float alpha = sin(timeValue) / 2.0 + 0.5;
    int vertexColorLocation = glGetUniformLocation(_shaderProgram.shaderProgram(), "ourColor");
    glUniform4f(vertexColorLocation, _color[0]*alpha, _color[1]*alpha, _color[2]*alpha, _color[4]);
    glBindVertexArray(_VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
