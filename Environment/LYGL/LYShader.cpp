//
//  LYShader.cpp
//  1 Hello Window Exercises
//
//  Created by 001s on 2018/6/3.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#include "LYShader.hpp"
#include <iostream>
#include <glad/glad.h>

void LYShader::compileShader() {
    _shader = glCreateShader(_shaderType);
    glShaderSource(_shader, 1, &_shaderSource, NULL);
    glCompileShader(_shader);
    
    int success;
    char infoLog[512];
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(_shader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
        exit(-1);
    }
}

unsigned int LYShader::shader() {
    return _shader;
}
