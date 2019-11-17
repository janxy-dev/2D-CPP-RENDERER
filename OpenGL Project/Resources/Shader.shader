#shader vertex
#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 aColor;
layout(location = 2) in vec2 aTexCoords;

out vec3 _color;
out vec2 _texcoord;

uniform mat4 transform;

void main(){
	gl_Position = transform * vec4(pos, 1.0);
   _color = aColor;
   _texcoord = aTexCoords;
}


#shader fragment
#version 330 core

out vec4 color;

in vec3 _color;
in vec2 _texcoord;

uniform sampler2D _texture;
uniform sampler2D _texture2;

void main(){
	color = mix(texture(_texture, _texcoord), texture(_texture2, _texcoord), 0.5) * vec4(_color, 0.1);
}
