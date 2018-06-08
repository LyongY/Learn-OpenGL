//
//  LYShaderProgram.hpp
//  1 Hello Window Exercises
//
//  Created by 001s on 2018/6/3.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#ifndef LYShaderProgram_hpp
#define LYShaderProgram_hpp

#include <stdio.h>
#include <vector>
#include "LYShader.hpp"

class LYShaderProgram {
    unsigned int _shaderProgram;
    
public:
    LYShaderProgram(){}
    LYShaderProgram(std::vector<LYShader*> shaderArr);
    void use();
    unsigned int shaderProgram();
};

#endif /* LYShaderProgram_hpp */
