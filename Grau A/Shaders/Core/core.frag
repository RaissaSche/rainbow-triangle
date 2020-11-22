#version 400 core

in vec2 TexCoord;
in vec4 frag_pos;
in vec3 normal;

out vec4 color;

uniform sampler2D mapKd;

uniform int lightNum;
uniform mat3 lightPos;

uniform float la;
uniform float ld;
uniform float ls;

uniform vec3 ka;
uniform vec3 kd;
uniform vec3 ks;

uniform float ns;

vec3 ambient(){
	return la * ka;
}

vec3 diffuse(vec3 lightPosV){	
	vec3 V = lightPosV - vec3(frag_pos.x, frag_pos.y, frag_pos.z);
		
	float Ad = max(0, dot(normal, normalize(V)));
	vec3 d = ld * kd * Ad * texture(mapKd, TexCoord); 
	
	if(d.x < 0 || d.y < 0 || d.z < 0){
		d = vec3(0, 0, 0);
	}

	return d;
}

vec3 specular(vec3 lightPosV){
	vec3 V = lightPosV - vec3(frag_pos.x, frag_pos.y, frag_pos.z);

	vec3 R = reflect(normal, lightPosV);
	float As = dot (V, R);
	float sAux = pow (As, ns);
		
	vec3 s = ls * ks * sAux;
	//* mapKs;

	if(s.x < 0 || s.y < 0 || s.z < 0){
		s = vec3(0, 0, 0);
	}

	return s;
}

void main(){
	vec4 tex1 = texture (mapKd, TexCoord);
	vec4 a = vec4(ambient(), 1); 
	vec3 diff, spec;

	for (int i = 0; i < lightNum; i++){
		diff += diffuse(lightPos[i]);
		spec += specular(lightPos[i]);
	}

	vec4 I = a + diff + spec;
	color = I * tex1;
}
