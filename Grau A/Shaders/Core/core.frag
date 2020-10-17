#version 400 core

in vec2 TexCoord;
in vec2 normCoord;
in vec4 frag_pos;

out vec4 color;

uniform sampler2D texture1;
uniform vec3 lightPos;
uniform vec3 cameraPosLight;
uniform vec3 ka;
//uniform vec3 kd;
uniform vec3 ks;
uniform float ns;
uniform float la;

/*float La = 0.9;
float Ld = 0.9;
vec3 kd = vec3 (0.9, 0.9, 0.9);
vec3 v1 = vec3 (0.9, 0.9, 0.9);
vec4 cam_pos = vec4(0.0, 0.0, 0.0, 0.0);

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

float ambient(float kaColorValue){
return kaColorValue;
}
*/

void main(){
	vec4 tex1 = texture( texture1, TexCoord );
	
	/*
	float Ad = max(0, dot(normal(v1), v1));

	vec4 V = cam_pos - frag_pos;
	//R = N * (1 - Ad) - L
	vec3 R = normal(v1) * (1 - Ad) - v1;
	float As = dot (V, R);
	float s = pow (As, ns);

	//          ambient      fatt         diffuse          specular
	//float Ir = (La * ka.x) + fatt(v1) * ( (Ld* kd.x * Ad) + s + ns );
	//float Ig = (La * ka.y) + fatt(v1) * ( (Ld* kd.y * Ad) + s );
	//float Ib = (La * ka.z) + fatt(v1) * ( (Ld* kd.z * Ad) + s );
	*/

	/*
	color.r = Ir * tex1.x;
	color.g = Ig * tex1.y;
	color.b = Ib * tex1.z;
	*/

	//color.r = ambient(la) * tex1.x;
	//color.g = ambient(la) * tex1.y;
	//color.b = ambient(la) * tex1.z;	
	
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