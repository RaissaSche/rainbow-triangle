#version 400 core

in vec2 TexCoord;
layout ( location = 3 ) in vec3 ka;

out vec4 color;

uniform sampler2D texture1;

float La = 0.8;
vec3 tempKa = vec3(0.5, 0.3, 0.7);
float Ld = 0.7;
vec3 kd = vec3 (0.9, 0.9, 0.9);
vec3 v1 = vec3 (0.5, 0.5, 0.5);
vec3 cam_pos = vec3(0.0, 0.0, 0.0);
vec3 frag_pos = vec3(0.15, 0.15, 0.15);
int n = 3;

float length (vec3 v1){
	return sqrt((v1.x * v1.x) + (v1.y * v1.y) + (v1.z * v1.z));
}

vec3 normal (vec3 v1){
	float l = length(v1);
	vec3 n;
	n.x = v1.x / l;
	n.y = v1.y / l;
	n.z = v1.z / l;
	return n;
}

float dot (vec3 v1, vec3 v2) {
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

void main(){
	vec4 tex1 = texture( texture1, TexCoord );
	
	float Ad = max(0, dot(normal(v1), v1));

	vec3 V = cam_pos - frag_pos;
	//R = N * (1 - Ad) - L
	vec3 R = normal(v1) * (1 - Ad) - v1;
	float As = dot (V, R);
	float s = pow (As, n);

	//          ambient          fatt        diffuse           specular
	float Ir = (La * tempKa.x) + fatt(v1) * ( (Ld* kd.x * Ad) + s );
	float Ig = (La * tempKa.y) + fatt(v1) * ( (Ld* kd.y * Ad) + s );
	float Ib = (La * tempKa.z) + fatt(v1) * ( (Ld* kd.z * Ad) + s );

	color.r = Ir * tex1.x;
	color.g = Ig * tex1.y;
	color.b = Ib * tex1.z;

	//color = tex1;
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
	//dot

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