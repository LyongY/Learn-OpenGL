//
//  main.cpp
//  1 Hello Window Exercises
//
//  Created by Raysharp666 on 2018/6/1.
//  Copyright © 2018年 LyongY. All rights reserved.
//

#include <iostream>
#include <vector>

#include "LYWindow.hpp"
#include "LYTriangle.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    LYWindow window = LYWindow(300, 300, "Hello Window Exercises");
    
    vector<float> verticesRed = {
        -0.5f, 0.0f, 0.0f,
         0.5f, 0.0f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
    vector<float> colorRed = {1.0, 0, 0, 1};
    LYTriangle triangleRed = LYTriangle(verticesRed, colorRed);
    
    vector<float> verticesBlue = {
        -0.5f, 0.0f, 0.0f,
        0.5f, 0.0f, 0.0f,
        0.0f, -0.5f, 0.0f
    };
    vector<float> colorBlue = {0, 0, 1, 1};
    LYTriangle triangleBlue = LYTriangle(verticesBlue, colorBlue);
    
    window.render([&](){
        triangleRed.render();
        triangleBlue.render();
    });
    
    return 0;
}
