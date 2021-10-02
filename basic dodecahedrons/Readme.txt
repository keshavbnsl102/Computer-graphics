Name: Keshav Bansal
Roll number: 2019101019

Keys:

 Camera translation on its three axes, i.e cameraup, cameradirection and camera right axes:
 
d key: The camera moves along the camera direction axis away from the object, which is the vector between the 
       object and the camera.
a key: The camera moves along the camera direction axis towards the object.
w key: camera moves along the camera right axis, on the positive side. 
s key: Camera moves along the camera right axis, on the negative side.
r key: camera moves along camera up axis, on the positive side.
e key:  camera moves along the camera down axis, on the negative side.

Camera teleportation: 

u key: the camera will be teleported to (4,4,4)
i key: The camera will be directly teleported to (0,0,4)
o key: The camera will be teleported to (-4,0,0)

Object movement on three world coordinate axes:

up arrow key: Move the object along positive y axis 
down arrow key: move the object along negative y axis
left arrow key: move the object along positive z axis
right arrow key: move the object along negative z axis
m arrow key: move the object along positive x axis
n arrow key: move the object along negative x axis

Camera rotation about the object:

h key: Camera will start rotating about the object in a fixed radius as long as the key is pressed.


Camera rotation on its axis:

g key: The object will start rotating about the y axis.

How to Run:

1. Run cmake .. in build
2. run make
3. now an exeutable called  'Hello-world' can be run using ./Hello-world <solid_number>

e.g. to render first dodecahedron, run './Hello-world 1'
