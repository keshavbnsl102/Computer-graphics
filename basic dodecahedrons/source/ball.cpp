#include "ball.h"
#include "main.h"

Ball::Ball(float x, float y, color_t color,int a) {
    this->position = glm::vec3(x, y, 0);
    this->rotation = 0;
    speed = 1;
    // Our vertices. Three consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
    // A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
    if(a==1)
    {static const GLfloat vertex_buffer_data[] = {
        -1.0f,-1.0f,1.0f, // triangle 1 : begin
        1.0f,-1.0f, 1.0f,
        0.0f, 0.0f, 2.0f, // triangle 1 : end
        1.0f, -1.0f,1.0f, // triangle 2 : begin
        1.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 2.0f, // triangle 2 : end
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        0.0f, 0.0f, 2.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f,-1.0f, 1.0f,
        0.0f, 0.0f, 2.0f,
        -1.0f,-1.0f,1.0f,
        -1.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f,-1.0f, 1.0f,
        -1.0f,-1.0f, -1.0f,
        1.0f,1.0f,-1.0f,
        1.0f, -1.0f, 1.0f,
        1.0f,-1.0f, -1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        1.0f,-1.0f,-1.0f,
        1.0f, 1.0f,-1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f,
        1.0f, 1.0f, -1.0f,
        -1.0f, 1.0f, 1.0f,
        1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f, 1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f, -1.0f, 1.0f,
        -1.0f, -1.0f, 1.0f,
        -1.0f, 1.0f, -1.0f,
        -1.0f,-1.0f, -1.0f,
        -1.0f,-1.0f,-1.0f, 
         1.0f,-1.0f, -1.0f,
         0.0f, 0.0f, -2.0f, 
        1.0f, -1.0f,-1.0f, 
        1.0f,1.0f,-1.0f,
        0.0f, 0.0f,-2.0f, 
        -1.0f,1.0f, -1.0f,
         1.0f, 1.0f, -1.0f,
        0.0f,0.0f,-2.0f,
        -1.0f, 1.0f,-1.0f,
        -1.0f,-1.0f,-1.0f,
        0.0f,0.0f,-2.0f,
    };
    this->object = create3DObject(GL_TRIANGLES, 16*3, vertex_buffer_data, color, GL_FILL);
  }
  else if(a==2)
  {
    static const GLfloat vertex_buffer_data[] = {
        1.73f,1.0f,0.0f, // triangle 1 : begin
        1.73f,-1.0f, 0.0f,
        0.0f, 0.0f, 2.0f, // triangle 1 : end
        1.73f, 1.0f,0.0f, // triangle 2 : begin
        0.0f, 0.0f, 2.0f,
        0.0f, 2.0f, 0.0f, // triangle 2 : end
        -1.73f, 1.0f, 0.0f,
        0.0f, 2.0f, 0.0f,
        0.0f, 0.0f, 2.0f,
        -1.73f, 1.0f, 0.0f,
        -1.73f,-1.0f, 0.0f,
        0.0f, 0.0f, 2.0f,
        -1.73f,-1.0f,0.0f,
        0.0f, -2.0f, 0.0f,
        0.0f, 0.0f, 2.0f,
        0.0f,0.0f, 2.0f,
        0.0f,-2.0f, 0.0f,
        1.73f,-1.0f,0.0f,
        1.73f,1.0f,0.0f, // triangle 1 : begin
        1.73f,-1.0f, 0.0f,
        0.0f, 0.0f, -2.0f, // triangle 1 : end
        1.73f, 1.0f,0.0f, // triangle 2 : begin
        0.0f, 0.0f, -2.0f,
        0.0f, 2.0f, 0.0f, // triangle 2 : end
        -1.73f, 1.0f, 0.0f,
        0.0f, 2.0f, 0.0f,
        0.0f, 0.0f, -2.0f,
        -1.73f, 1.0f, 0.0f,
        -1.73f,-1.0f, 0.0f,
        0.0f, 0.0f, -2.0f,
        -1.73f,-1.0f,0.0f,
        0.0f, -2.0f, 0.0f,
        0.0f, 0.0f, -2.0f,
        0.0f,0.0f, -2.0f,
        0.0f,-2.0f, 0.0f,
        1.73f,-1.0f,0.0f,
        
    };
    this->object = create3DObject(GL_TRIANGLES, 12*3, vertex_buffer_data, color, GL_FILL);




  }

  else if(a==3)
  {
  //  cos36=0.81
  //     sin36=0.59
  //     cos72=0.31
  //     sin72=0.95


    static const GLfloat vertex_buffer_data[] = {
        2.0f,0.0f,1.0f,
        0.0f,0.0f,1.0f,
        1.62f,1.18f,1.0f,
        1.62f,1.18f,1.0f,
        0.0f,0.0f,1.0f,
        0.62f,1.90f,1.0f,
        0.62f,1.90f,1.0f,
        0.0f,0.0f,1.0f,
        -0.62f,1.90f,1.0f,
        -0.62f,1.90f,1.0f,
         0.0f,0.0f,1.0f,
         -1.62f,1.18f,1.0f,
         -1.62f,1.18f,1.0f,
         0.0f,0.0f,1.0f,
         -2.0f,0.0f,1.0f,
         -2.0f,0.0f,1.0f,
         0.0f,0.0f,1.0f,
         -1.62f,-1.18f,1.0f,
         -1.62f,-1.18f,1.0f,
         0.0f,0.0f,1.0f,
         -0.62f,-1.90f,1.0f,
         -0.62f,-1.90f,1.0f,
         0.0f,0.0f,1.0f,
         0.62f,-1.90f,1.0f,
         0.62f,-1.90f,1.0f,
         0.0f,0.0f,1.0f,
         1.62f,-1.18f,1.0f,
         1.62f,-1.18f,1.0f,
         0.0f,0.0f,1.0f,
         2.0f,0.0f,1.0f,

         2.0f,0.0f,-1.0f,
        0.0f,0.0f,-1.0f,
        1.62f,1.18f,-1.0f,
        1.62f,1.18f,-1.0f,
        0.0f,0.0f,-1.0f,
        0.62f,1.90f,-1.0f,
        0.62f,1.90f,-1.0f,
        0.0f,0.0f,-1.0f,
        -0.62f,1.90f,-1.0f,
        -0.62f,1.90f,-1.0f,
         0.0f,0.0f,-1.0f,
         -1.62f,1.18f,-1.0f,
         -1.62f,1.18f,-1.0f,
         0.0f,0.0f,-1.0f,
         -2.0f,0.0f,-1.0f,
         -2.0f,0.0f,-1.0f,
         0.0f,0.0f,-1.0f,
         -1.62f,-1.18f,-1.0f,
         -1.62f,-1.18f,-1.0f,
         0.0f,0.0f,-1.0f,
         -0.62f,-1.90f,-1.0f,
         -0.62f,-1.90f,-1.0f,
         0.0f,0.0f,-1.0f,
         0.62f,-1.90f,-1.0f,
         0.62f,-1.90f,-1.0f,
         0.0f,0.0f,-1.0f,
         1.62f,-1.18f,-1.0f,
         1.62f,-1.18f,-1.0f,
         0.0f,0.0f,-1.0f,
         2.0f,0.0f,-1.0f,

         2.0f,0.0f,1.0f,
          1.62f,1.18f,1.0f,
          2.0f,0.0f,-1.0f,

          2.0f,0.0f,-1.0f,
          1.62f,1.18f,-1.0f,
          1.62f,1.18f,1.0f,

          1.62f,1.18f,1.0f,
          0.62f,1.90f,1.0f,
          1.62f,1.18f,-1.0f,

          1.62f,1.18f,-1.0f,
          0.62f,1.90f,-1.0f,
          0.62f,1.90f,1.0f,

          0.62f,1.90f,1.0f,
          -0.62f,1.90f,1.0f,
          0.62f,1.90f,-1.0f,

          0.62f,1.90f,-1.0f,
          -0.62f,1.90f,-1.0f,
          -0.62f,1.90f,1.0f,

          -0.62f,1.90f,1.0f,
          -1.62f,1.18f,1.0f,
          -0.62f,1.90f,-1.0f,

          -0.62f,1.90f,-1.0f,
          -1.62f,1.18f,-1.0f,
          -1.62f,1.18f,1.0f,

          -1.62f,1.18f,1.0f,
          -2.00f,0.0f,1.0f,
          -1.62f,1.18f,-1.0f,

          -1.62f,1.18f,-1.0f,
          -2.0f,0.0f,-1.0f,
          -2.0f,0.0f,1.0f,

          -2.0f,0.0f,1.0f,
          -1.62f,-1.18f,1.0f,
          -2.0f,0.0f,-1.0f,

          -2.0f,0.0f,-1.0f,
          -1.62f,-1.18f,-1.0f,
          -1.62f,-1.18f,1.0f,

          -1.62f,-1.18f,1.0f,
          -0.62f,-1.90f,1.0f,
          -1.62f,-1.18f,-1.0f,

          -1.62f,-1.18f,-1.0f,
          -0.62f,-1.90f,-1.0f,
          -0.62f,-1.90f,1.0f,

          -0.62f,-1.90f,1.0f,
          0.62f,-1.90f,1.0f,
          -0.62f,-1.90f,-1.0f,

          -0.62f,-1.90f,-1.0f,
          0.62f,-1.90f,-1.0f,
          0.62f,-1.90f,1.0f,

          0.62f,-1.90f,1.0f,
          1.62f,-1.18f,1.0f,
          0.62f,-1.90f,-1.0f,

          0.62f,-1.90f,-1.0f,
          1.62f,-1.18f,-1.0f,
          1.62f,-1.18f,1.0f,

          1.62f,-1.18f,1.0f,
          2.0f,0.0f,1.0f,
          1.62f,-1.18f,-1.0f,

          1.62f,-1.18f,-1.0f,
          2.0f,0.0f,-1.0f,
          2.0f,0.0f,1.0f,
       };

      
    this->object = create3DObject(GL_TRIANGLES, 40*3, vertex_buffer_data, color, GL_FILL);
     




  }

    
}

void Ball::draw(glm::mat4 VP) {
    Matrices.model = glm::mat4(1.0f);
    glm::mat4 translate = glm::translate (this->position);    // glTranslatef
    glm::mat4 rotate    = glm::rotate((float) (this->rotation * M_PI / 180.0f), glm::vec3(0, 1, 0));
    // No need as coords centered at 0, 0, 0 of cube arouund which we waant to rotate
    // rotate          = rotate * glm::translate(glm::vec3(0, -0.6, 0));
    Matrices.model *= (translate * rotate);
    glm::mat4 MVP = VP * Matrices.model;
    glUniformMatrix4fv(Matrices.MatrixID, 1, GL_FALSE, &MVP[0][0]);
    draw3DObject(this->object);
}

void Ball::set_position(float x, float y,float z) {
    this->position = glm::vec3(x, y, z);
}

void Ball::tick() {
    
    // this->position.x -= speed;
    // this->position.y -= speed;

}

