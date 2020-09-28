#version 400 core

layout ( location = 0 ) in vec3 vPosition;
layout ( location = 1 ) in vec3 normCoord;
layout ( location = 2 ) in vec2 texCoord;

out vec2 TexCoord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

void main()
{
	gl_Position = proj * view * model * vec4(vPosition, 1.0);
	
	TexCoord = vec2( texCoord.x, 1.0 - texCoord.y );
}
