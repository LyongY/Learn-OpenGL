//
//  LYFragmentShader.cpp
//  1 Hello Window Exercises
//
//  Created by 001s on 2018/6/3.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#include "LYFragmentShader.hpp"
#include <string>
using namespace std;

LYFragmentShader::LYFragmentShader(float r, float g, float b, float a) {
    _shaderType = (LYShaderType)GL_FRAGMENT_SHADER;
    string vec = string("\
                        #version 330 core\n"
                        "out vec4 FragColor;\n"
                        "void main() {\n") + string("FragColor = vec4(") + to_string(r) + string(", ") + to_string(g) + string(", ") + to_string(b) + string(", ") + to_string(a) + string(");\n") + string("}");
    _shaderSource = vec.c_str();
    
    _shaderSource = "\
    #version 330 core\n\
    out vec4 FragColor;\n\
    uniform vec4 ourColor;\n\
    void main() {\n\
        FragColor = ourColor;\n\
    }";
    
    LYShader::compileShader();
}
