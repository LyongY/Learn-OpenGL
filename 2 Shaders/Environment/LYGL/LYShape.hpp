//
//  LYShape.hpp
//  1 Hello Window Exercises
//
//  Created by 001s on 2018/6/3.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#ifndef LYShape_hpp
#define LYShape_hpp

#include <stdio.h>
#include <vector>
#include "LYShaderProgram.hpp"

class LYShape {
protected:
    unsigned int _VAO;
    std::vector<float> _vertices;
    std::vector<float> _color;
    
    LYShaderProgram _shaderProgram;
public:
    
    LYShape(std::vector<float> vertices, std::vector<float> color);
    
    void render();
};

#endif /* LYShape_hpp */
