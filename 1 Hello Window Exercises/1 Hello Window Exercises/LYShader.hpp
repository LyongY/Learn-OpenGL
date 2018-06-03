//
//  LYShader.hpp
//  1 Hello Window Exercises
//
//  Created by 001s on 2018/6/3.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#ifndef LYShader_hpp
#define LYShader_hpp

#include <stdio.h>
#include <glad/glad.h>

typedef enum : int {
    LYShaderType_Vertex = GL_VERTEX_SHADER,
    LYShaderType_Fragment = GL_FRAGMENT_SHADER,
} LYShaderType;

class LYShader {
    
protected:
    unsigned int _shader;
    const char* _shaderSource;
    LYShaderType _shaderType;
public:
    void compileShader();
    unsigned int shader();
    
    
    friend bool operator == (const LYShader& one, const LYShader& two)
    {
        return (one._shader == two._shader) ? true : false;
    }   

};

#endif /* LYShader_hpp */
