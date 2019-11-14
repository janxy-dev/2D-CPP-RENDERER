#shader vertex
#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 aColor;

void main(){
   gl_Position = position;
}


#shader fragment
#version 330 core

layout(location = 0) out vec4 color;
uniform vec4 _color;
uniform vec3 asd;

void main(){
   color = _color;
}
