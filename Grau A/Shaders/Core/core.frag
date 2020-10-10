#version 400 core

in vec2 TexCoord;

out vec4 color;

uniform sampler2D texture1;

void main(){
	vec4 tex1 = texture( texture1, TexCoord );
	color = tex1;
}
/*
//calcular parcela ambiente
Ia = La * Ka

//Calcular parcela difusa (produto escalar entre N e L)
	//dot
Id = Ld * Kd * Ad

//Calcular atenuação da fonte de luz:
fatt = 1/(magnitude(L))^2

//Calcular parcela especular, produto escalar R e V (pode utilizar simplificação Binn)
	//dot

//Aplicar expoente (shinness)
	//powb
Is = Ls * Ks * As^n

//Somar as partes
I = A + fatt * (D + S)

//Misturar com textura
color = I * texture(vt)
*/