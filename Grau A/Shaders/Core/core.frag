#version 400 core

in vec2 TexCoord;
in vec4 frag_pos;
in vec3 normal;

out vec4 color;

uniform sampler2D mapKd;
uniform sampler2D mapKs;
uniform int idMapKs;

uniform vec3 cameraPos;

uniform int lightNum;
uniform mat3 lightPos;

uniform float la;
uniform float ld;
uniform float ls;

uniform vec3 ka;
uniform vec3 kd;
uniform vec3 ks;

uniform float ns;

uniform int idFog;
uniform vec3 fog;

vec3 ambient(){
	return la * ka;
}

vec3 diffuse(vec3 lightPosV){	
	vec3 V = lightPosV - vec3(frag_pos.x, frag_pos.y, frag_pos.z);
		
	float Ad = max(0, dot(normal, normalize(V)));
	vec3 d = ld * kd * Ad; 
	
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

	if(s.x < 0 || s.y < 0 || s.z < 0){
		s = vec3(0, 0, 0);
	}

	return s;
}

float fatt (vec3 VL){
	float d = length(VL);
	return 1 / (d * d);
}

	//aplicar fog depos do calc do fog percentual do fog peso 
	//pela distancia do fragmento pelo da camera observador
	//tipo fatt, mas troca os pontos e distância sobre 1
	//depois de calcular percentual, chamar função mix ()
	//passa rgb e rgb e VALOR DO MIX, função da opengl peso do 
	//segindo árâmetro colr da iluna~çaõ e do fog e resultado da atuanação, 1/distância

float fatm (){
	float distance = distance(frag_pos, vec4(cameraPos, 1));
	return 1 / distance;
}

void main(){
	vec4 map_kd = texture (mapKd, TexCoord);
	vec4 map_ks = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	if(idMapKs != 0){
		map_ks = texture (mapKs, TexCoord);
	}
	vec4 a = vec4(ambient(), 1); 
	vec3 diff, spec;

	for (int i = 0; i < lightNum; i++){
		diff += fatt(diffuse(lightPos[i]));
		spec += fatt(specular(lightPos[i]));
	}

	vec3 Id = diff * map_kd;
	vec3 Is = spec * map_ks;
	vec4 I = a * map_kd + Id + Is;

	color = I;

	if(idFog == 1){
		color = mix(I, vec4(fog, 1), fatm());
	}
}
