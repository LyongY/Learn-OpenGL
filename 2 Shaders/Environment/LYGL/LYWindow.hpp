//
//  LYWindow.hpp
//  1 Hello Window Exercises
//
//  Created by Raysharp666 on 2018/6/2.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#ifndef LYWindow_hpp
#define LYWindow_hpp

#include <stdio.h>
#include <vector>
#include <functional>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


class LYWindow {

    GLFWwindow *_window;
    std::vector<unsigned int> _VAOArr;
    
public:
    LYWindow(float width, float height, const char *title);
    
    void addVAO(unsigned int VAO);
    void render(const std::function<void ()>& VAO_render);
};

#endif /* LYWindow_hpp */
