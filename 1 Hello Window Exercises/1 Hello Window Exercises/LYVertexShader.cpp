//
//  LYVertexShader.cpp
//  1 Hello Window Exercises
//
//  Created by 001s on 2018/6/3.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#include "LYVertexShader.hpp"
#include <iostream>

LYVertexShader::LYVertexShader() {
    _shaderType = (LYShaderType)GL_VERTEX_SHADER;
    _shaderSource = "\
    #version 330 core\n\
    layout (location = 0) in vec3 aPos;\n\
    void main() {\n\
        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n\
    }";
    LYShader::compileShader();
}
