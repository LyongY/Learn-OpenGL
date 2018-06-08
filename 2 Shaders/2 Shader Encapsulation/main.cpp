//
//  main.cpp
//  2 Shader Encapsulation
//
//  Created by Raysharp666 on 2018/6/4.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#include <iostream>
#include "LYWindow.hpp"
#include "Shader.hpp"
#include <unistd.h>

int main(int argc, const char * argv[]) {

    LYWindow window = LYWindow(400, 300, "Shader Encapsulation");
    
    Shader shader = Shader("/Users/yly/Documents/Space/Learn OpenGL/2 Shaders/2 Shader Encapsulation/Shader.vs", "/Users/yly/Documents/Space/Learn OpenGL/2 Shaders/2 Shader Encapsulation/Shader.fs");
    
    
    float vertex[] = {
        -0.5, -0.5, 0,  0, 0, 1,
         0.5, -0.5, 0,  0, 0, 1,
         0.0,  0.5, 0,  0, 0, 1,
    };
    
    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    unsigned int VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertex), vertex, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    
    window.render([&](){
        shader.use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    });
    
    return 0;
}
