#version 400 core

in vec2 TexCoord;
in vec4 frag_pos;
in vec3 normal;

out vec4 color;

uniform sampler2D texture1;
uniform float la;
uniform vec3 ka;

vec3 ambient(){
	return la * ka;
}

void main(){
vec4 a = vec4(ambient(), 1); 
	vec4 tex1 = texture (texture1, TexCoord);
	color = a * tex1;
}