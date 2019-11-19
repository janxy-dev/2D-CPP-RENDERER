#shader vertex
#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec2 aTexCoords;

out vec2 _texcoord;

uniform mat4 transform;

void main(){
	gl_Position = transform * vec4(pos, 1.0);
   _texcoord = aTexCoords;
}


#shader fragment
#version 330 core

out vec4 color;

in vec2 _texcoord;

uniform sampler2D _texture;

void main(){
	color = texture(_texture, _texcoord);
}
