//
//  LYShaderProgram.cpp
//  1 Hello Window Exercises
//
//  Created by 001s on 2018/6/3.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#include "LYShaderProgram.hpp"
#include <iostream>

LYShaderProgram::LYShaderProgram(std::vector<LYShader*> shaderArr) {
    _shaderProgram = glCreateProgram();
    
    std::vector<LYShader*>::iterator v = shaderArr.begin();
    while (v != shaderArr.end()) {
        glAttachShader(_shaderProgram, (*v)->shader());
        v++;
    }
    glLinkProgram(_shaderProgram);
    
    int success;
    char infoLog[512];
    glGetProgramiv(_shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(_shaderProgram, 512, NULL, infoLog);
        std::cout << "LINK PROGRAM ERROR: " << infoLog << std::endl;
        exit(-1);
    }
    
    v = shaderArr.begin();
    while (v != shaderArr.end()) {
        glDeleteShader((*v)->shader());
        v++;
    }
}

void LYShaderProgram::use() {
    glUseProgram(_shaderProgram);
}
