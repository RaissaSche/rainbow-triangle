#version 400 core

in vec2 TexCoord;
in vec4 frag_pos;
in vec3 normal;

out vec4 color;

uniform sampler2D texture1;

uniform int lightNum;
uniform mat3 lightPos;

uniform float la;
uniform float ld;

uniform vec3 ka;
uniform float kd;

vec3 ambient(){
	return la * ka;
}

float diffuse(vec3 lightPos){	
	vec3 V = lightPos - vec3(frag_pos.x, frag_pos.y, frag_pos.z);
		
	float Ad = max(0, dot(normal, normalize(V)));
	float d = ld * kd * Ad;
	//* texture(mapKd, TexCoord); 
	
	if(d < 0){
		d = 0;
	}

	return d;
}

void main(){
	vec4 tex1 = texture (texture1, TexCoord);
	vec4 a = vec4(ambient(), 1); 
	float diff = 0;

	for (int i = 0; i < lightNum; i++){
		diff += diffuse(lightPos[i]);
	}

	vec4 I = a + diff;
	color = I * tex1;
}