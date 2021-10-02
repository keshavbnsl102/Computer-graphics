#include "main.h"
#include "timer.h"
#include "ball.h"

using namespace std;

GLMatrices Matrices;
GLuint     programID;
GLFWwindow *window;

/**************************
* Customizable functions *
**************************/

Ball ball1;

float screen_zoom = 1, screen_center_x = 0, screen_center_y = 0;
float camera_rotation_angle = 0;

Timer t60(1.0 / 60);
glm::vec3 eye ( 0, 0, 5 );
glm:: vec3 eye1(4,4,4);
glm:: vec3 eye2(0,0,4);
glm:: vec3 eye3(-4,0,0);

glm::vec3 target (0, 0, 0);
/* Render the scene with openGL */
/* Edit this function according to your assignment */
void draw() {
    // clear the color and depth in the frame buffer
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

     glm::vec3 cameraPos=eye;
    glm::vec3 cameraDirection = glm::normalize(cameraPos - target);
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f); 
    glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
    glm::vec3 cameraUp = glm::cross(cameraDirection, cameraRight);
    // use the loaded shader program
    // Don't change unless you know what you are doing
    glUseProgram (programID);
    camera_rotation_angle=glfwGetTime();

    int w  = glfwGetKey(window, GLFW_KEY_W);
    int s = glfwGetKey(window, GLFW_KEY_S);
    int a=glfwGetKey(window, GLFW_KEY_A);
    int d=glfwGetKey(window, GLFW_KEY_D);
    int r=glfwGetKey(window, GLFW_KEY_R);
    int e=glfwGetKey(window,GLFW_KEY_E);
     int u=glfwGetKey(window,GLFW_KEY_U);
      int i=glfwGetKey(window,GLFW_KEY_I);
      int o=glfwGetKey(window,GLFW_KEY_O);
      int g  = glfwGetKey(window, GLFW_KEY_G);
      int h  = glfwGetKey(window, GLFW_KEY_H);
    if(g)
    {ball1.rotation += 5;}

    if (d) {
        // Do something
        eye.x+=0.1*cameraDirection.x;
        eye.y+=0.1*cameraDirection.y;
        eye.z+=0.1*cameraDirection.z;
        
    }
    if(a)
    {
        eye.x-=0.1*cameraDirection.x;
        eye.y-=0.1*cameraDirection.y;
        eye.z-=0.1*cameraDirection.z;
    }
    if(w)
    {
        eye+=cameraRight;
    }
    if(s)
    {
        eye-=cameraRight;

    }
    if(r)
    {
       eye+=cameraUp;
    }
    if(e)
    {
       eye-=cameraUp;
    }
    if(u)
    {
        eye=eye1;
        target=ball1.position;
    }
    if(i)
    {eye=eye2;
      target=ball1.position;
    }
    if(o)
    {
        eye=eye3;
        target=ball1.position;
    }

    // Eye - Location of camera. Don't change unless you are sure!!
    
    // Target - Where is the camera looking at.  Don't change unless you are sure!!
   
    // Up - Up vector defines tilt of camera.  Don't change unless you are sure!!
    
     if(h)
    {
        const float radius = 10.0f;
        float camX = sin(glfwGetTime()) * radius;
         float camZ = cos(glfwGetTime()) * radius;
       glm::vec3 vect (camX,0.0,camZ);
        target=ball1.position;
        eye=ball1.position+vect;
        


        
    }

    // Compute Camera matrix (view)
    Matrices.view = glm::lookAt( eye, target, up ); // Rotating Camera for 3D

    // Don't change unless you are sure!!
    // Matrices.view = glm::lookAt(glm::vec3(0, 0, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0)); // Fixed camera for 2D (ortho) in XY plane

    // Compute ViewProject matrix as view/camera might not be changed for this frame (basic scenario)
    // Don't change unless you are sure!!
    glm::mat4 VP = Matrices.projection * Matrices.view;

    // Send our transformation to the currently bound shader, in the "MVP" uniform
    // For each model you render, since the MVP will be different (at least the M part)
    // Don't change unless you are sure!!
    glm::mat4 MVP;  // MVP = Projection * View * Model

    // Scene render
    ball1.draw(VP);
}

void tick_input(GLFWwindow *window) {
    int left  = glfwGetKey(window, GLFW_KEY_LEFT);
    int right = glfwGetKey(window, GLFW_KEY_RIGHT);
    int up=glfwGetKey(window, GLFW_KEY_UP);
    int down=glfwGetKey(window, GLFW_KEY_DOWN);
    int m=glfwGetKey(window, GLFW_KEY_M);
    int n=glfwGetKey(window,GLFW_KEY_N);

    if (left) {
        // Do something
        ball1.set_position(ball1.position.x,ball1.position.y,ball1.position.z+0.5);
        
    }
    if(right)
    {
        ball1.set_position(ball1.position.x,ball1.position.y,ball1.position.z-0.5);
    }
    if(up)
    {
        ball1.set_position(ball1.position.x,ball1.position.y+0.5,ball1.position.z);
    }
    if(down)
    {
        ball1.set_position(ball1.position.x,ball1.position.y-0.5,ball1.position.z);

    }
    if(m)
    {
     ball1.set_position(ball1.position.x+0.5,ball1.position.y,ball1.position.z);   
    }
    if(n)
    {
        ball1.set_position(ball1.position.x-0.5,ball1.position.y,ball1.position.z);
    }
}

void tick_elements() {
    ball1.tick();
    camera_rotation_angle += 0;
}

/* Initialize the OpenGL rendering properties */
/* Add all the models to be created here */
void initGL(GLFWwindow *window, int width, int height,int a) {
    /* Objects should be created before any other gl function and shaders */
    // Create the models

    ball1       = Ball(0, 0, COLOR_RED,a);

    // Create and compile our GLSL program from the shaders
    programID = LoadShaders("../source/shaders/shader.vert", "../source/shaders/shader.frag");
    // Get a handle for our "MVP" uniform
    Matrices.MatrixID = glGetUniformLocation(programID, "MVP");


    reshapeWindow (window, width, height);

    // Background color of the scene
    glClearColor (COLOR_BACKGROUND.r / 256.0, COLOR_BACKGROUND.g / 256.0, COLOR_BACKGROUND.b / 256.0, 0.0f); // R, G, B, A
    glClearDepth (1.0f);

    glEnable (GL_DEPTH_TEST);
    glDepthFunc (GL_LEQUAL);

    cout << "VENDOR: " << glGetString(GL_VENDOR) << endl;
    cout << "RENDERER: " << glGetString(GL_RENDERER) << endl;
    cout << "VERSION: " << glGetString(GL_VERSION) << endl;
    cout << "GLSL: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
}


int main(int argc, char **argv) {
    srand(time(0));
    int width  = 600;
    int height = 600;
    //printf("%lf",cos(45*M_PI/180.0f));

    window = initGLFW(width, height);

     if(argv[1][0]=='1')
      {initGL (window, width, height,1);
         
      }
     else if(argv[1][0]=='2')
     {
        initGL (window, width, height,2);
        
     }
     else if(argv[1][0]=='3')
     {
        initGL (window, width, height,3);
        
     }


    /* Draw in loop */
    while (!glfwWindowShouldClose(window)) {
        // Process timers

        if (t60.processTick()) {
            // 60 fps
            // OpenGL Draw commands
           draw();
            // Swap Frame Buffer in double buffering
            glfwSwapBuffers(window);

            tick_elements();
            tick_input(window);
        }

        // Poll for Keyboard and mouse events
        glfwPollEvents();
    }

    quit(window);
}

bool detect_collision(bounding_box_t a, bounding_box_t b) {
    return (abs(a.x - b.x) * 2 < (a.width + b.width)) &&
           (abs(a.y - b.y) * 2 < (a.height + b.height));
}

void reset_screen() {
    float top    = screen_center_y + 4 / screen_zoom;
    float bottom = screen_center_y - 4 / screen_zoom;
    float left   = screen_center_x - 4 / screen_zoom;
    float right  = screen_center_x + 4 / screen_zoom;
    Matrices.projection = glm::ortho(left, right, bottom, top, 0.1f, 500.0f);
}
