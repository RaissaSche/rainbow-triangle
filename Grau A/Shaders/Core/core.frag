#version 400 core

in vec2 TexCoord;
in vec2 normCoord;
in vec4 frag_pos;

out vec4 color;


uniform sampler2D texture1;

uniform int lightNum;
uniform mat3 lightPos;
uniform vec3 cameraPosLight;

uniform float la;
uniform float ld;
uniform float ls;

uniform vec3 ka;
uniform vec3 kd;
uniform vec3 ks;

uniform float ns;

uniform float mapKd;
uniform float mapKs;

uniform vec3 v1;


float length (vec3 v1) {
	return sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z));
}

vec3 normal (vec3 v1) {
	float l = length(v1);
	vec3 n;
	n.x = v1.x / l;
	n.y = v1.y / l;
	n.z = v1.z / l;
	return n;
}

float dot (vec4 v1, vec3 v2) {
	return v1.x * v2.x
		 + v1.y * v2.y
		 + v1.z * v2.z;
}

float fatt (vec3 VL){
	float d = length(VL);
	return 1 / (d * d);
}

float pow (float toMultiply, int multiplier){	
	float result = 0;
	for (int i = 0; i < multiplier; i++){
		result *= toMultiply;
	} 
	return result;
}

float ambient(){
	return la * ka;
}

float diffuse(int numOfLigths){
	float d = 0;
	
	for (int i = 0; i < numOfLigths; i++){
		float Ad = max(0, dot(normal(v1), v1)); /*!!!!!!!!!!!!!!*/
		d += fatt(ld * kd * Ad) * mapKd; 
	}
	
	return d;
}

float specular(int numOfLigths){
	float s = 0;

	for (int i = 0; i < numOfLigths; i++){
		vec4 V = cameraPosLight - frag_pos;
		//R = N * (1 - Ad) - L
		float Ad = max(0, dot(normal(v1), v1)); /*!!!!!!!!!!!!!!!*/
		vec3 R = normal(v1) * (1 - Ad) - v1; /*!!!!!!!!!!!!!!*/
		float As = dot (V, R);
		float s = pow (As, ns);
		
		s += fatt(ls * ks * s) * mapKs;
	}
	
	return s;
}


void main() {
	vec4 tex1 = texture( texture1, TexCoord );

	float I = ambient() * mapKd + diffuse(lightNum) + specular(lightNum);
	color = I * tex1;
	
	color = tex1;
}










/*
I = ambiente + fatt * (difusa + especular)

Letras I, K e fontes de luz e posi��o da c�mera s�o par�metros!!!

//frag_color = I * texel

R G B ! ! ! 
//calcular parcela ambiente
Ia = La * Ka

//Calcular parcela difusa (produto escalar entre N e L)
	//para cada fonte de luz!

	//ambiente + objeto + ad
	//Ad = max(0, cos 0) -> max(0, dot(N,L))
	//o produto escalar n�o precisa repetir para cada cor!
Id = Ld * Kd * Ad

//Calcular atenua��o da fonte de luz:
fatt = 1/(magnitude(L))^2

//Calcular parcela especular, produto escalar R e V (pode utilizar simplifica��o Binn)

	v = cam_pos - frag_pos
	Ad = N.L
	R = N * (1 - Ad) - L
	As = dot (V, R)
	s = pow(As, n)

//Aplicar expoente (shinness == n)
	//powb
Is = Ls * Ks * As^n

//Somar as partes
I = A + fatt * (D + S)

//Misturar com textura
color = I * texture(textura, vt)
*/