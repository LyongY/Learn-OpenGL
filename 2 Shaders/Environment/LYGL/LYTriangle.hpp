//
//  LYTriangle.hpp
//  1 Hello Window Exercises
//
//  Created by 001s on 2018/6/3.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#ifndef LYTriangle_hpp
#define LYTriangle_hpp

#include <stdio.h>
#include "LYShape.hpp"


class LYTriangle : public LYShape {
    
    
public:
    LYTriangle(std::vector<float> vertices, std::vector<float> color);
};

#endif /* LYTriangle_hpp */
