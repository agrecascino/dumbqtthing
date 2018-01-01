#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stack>
#include "player.h"
#include <thread>

using namespace std;

const GLfloat g_vertex_buffer_data[108] = {
        -1.0f,-1.0f,-1.0f, // triangle 1 : begin
        -1.0f,-1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f, // triangle 1 : end
        1.0f, 1.0f,-1.0f, // triangle 2 : begin
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f, // triangle 2 : end
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f,-1.0f, 1.0f
};

struct TextItem {
    TextItem(double s, std::string t) {
        seconds = s;
        text = t;
    }

    double seconds = 0.0;
    std::string text;
};

float vectorstringoffset(std::string s) {
    float size = s.size()/2.0;
    return size*(9.0/1280.0);
}

void playmodule() {
    std::fstream f("styggtro.mod", std::ios_base::in | std::ios_base::binary);
    ModulePlayer player(f);
    player.playModule();
}

int main(int argc, char **argv)
{
    std::cout << "it's not even written using qt" << std::endl;
    std::thread t(&playmodule);
    t.detach();
    GLFWwindow *window;
    glfwInit();
    glutInit(&argc, argv);
    window = glfwCreateWindow(1280, 720, "merry whatever", NULL, NULL);
    glewInit();
    glfwSwapInterval(1);
    float rot = 0.0;
    uint64_t frame = 0;
    glfwMakeContextCurrent(window);
    std::stack<TextItem> s;
    s.push(TextItem(5.0, "see ya."));
    s.push(TextItem(5.0, "anyway, i'm probably going to leave now."));
    s.push(TextItem(5.0, "slap me with a large trout."));
    s.push(TextItem(10.0, "i'll probably forget this lesson tomorrow, and inflict my unhappiness on you"));
    s.push(TextItem(6.0, "'yknow, you have to look beyond yourself"));
    s.push(TextItem(7.0, "because as long as everyone is happy, it's mostly okay"));
    s.push(TextItem(5.0, "but that's okay"));
    s.push(TextItem(3.0, "i didn't :\\"));
    s.push(TextItem(6.0, "i hope you have a good new year or whatever"));
    s.push(TextItem(3.0, "it's cool though"));
    s.push(TextItem(5.0, "i'm surprised this worked"));
    s.push(TextItem(2.0, "never"));
    s.push(TextItem(5.0, "you can never trust those shaders man"));
    s.push(TextItem(7.0, "which i absolutely love compared to that modern garbage"));
    s.push(TextItem(6.0, "all the graphics is really basic opengl 1.1"));
    s.push(TextItem(6.0, "styggtro had a far better gimmick than this"));
    s.push(TextItem(3.0, "that's fine though"));
    s.push(TextItem(7.0, "i hope you aren't too drunk to read this :<"));
    s.push(TextItem(3.0, "oh well."));
    s.push(TextItem(6.0, "which also happens to be my own engine :^)"));
    s.push(TextItem(9.0, "the module playback is from modplay2, which isn't the most accurate"));
    s.push(TextItem(4.0, "i personally think it looks pretty"));
    s.push(TextItem(5.0, "i completed the entirety of this in probably about 3 hours"));
    s.push(TextItem(5.0, "for the new years thing"));
    s.push(TextItem(5.0, "inspired by andromeda's styggtro"));
    s.push(TextItem(3.0, "a tiny intro"));
    s.push(TextItem(5.0, "agrecascino presents"));
    TextItem citem(0, "");
    double start = 0.0;
    start = glfwGetTime();
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluOrtho2D(0.0, (GLfloat) 1.0, 0.0, (GLfloat) 1.0);
        if((glfwGetTime() - start) < (citem.seconds/10.0)) {
            float i = (glfwGetTime() - start)/(citem.seconds/10.0);
            glColor4f(i, i, i, 1.0);
        }
        if((glfwGetTime() - start) > (citem.seconds - (citem.seconds/10.0))) {
            float i = (citem.seconds/10.0) - ((glfwGetTime() - start) - (citem.seconds - (citem.seconds/10.0)));
            glColor4f(i, i, i, 1.0);
        }
        glRasterPos2f(0.5 - vectorstringoffset(citem.text), 0.05);
        glutBitmapString(GLUT_BITMAP_9_BY_15, (unsigned char*)citem.text.c_str());
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45, (16.0/9.0), 0.1, 100.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(0, 0, -6.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glTranslatef(0.0, 0.5, 0.0);
        glTranslatef(2.0*sin(frame/32.0), 0, 0);
        glRotatef(rot, 1.0, 0.2 , 0.5);
        glBegin(GL_TRIANGLES);
        glColor3f(1.0, 1.0, 1.0);
        for(int i = 0; i < 108; i += 3) {
            glVertex3f(g_vertex_buffer_data[i], g_vertex_buffer_data[i+1], g_vertex_buffer_data[i+2]);
        }
        glEnd();
        glFlush();
        glfwPollEvents();
        glfwSwapBuffers(window);
        rot += 3.0;
        if((glfwGetTime() - start) > citem.seconds)
            if(s.size() > 0){
                start = glfwGetTime();
                citem = s.top();
                s.pop();
            }
        frame++;
    }
    return 0;
}
