struct vec2{
	float x,y;
};

float fract(float x){ 
	return x- floor(x);
	return x- floor(x);
}

vec2  fract (vec2 v){
	vec2 r   {fract(v.x),fract(v.y)};
	return r;
}

float length(vec2 v){ 
	return sqrt(v.x*v.x+v.y*v.y);
}

float sdCircle(vec2 v,float r){ 
	return length(v)-r;
}


vec2 polar(vec2 v){
    vec2 r;
	return r;
}


vec2 rot(vec2 v,float a){
    float c = cos(a);
    float s= sin(a);
	vec2 r;
	r.x = c*v.x-s*v.y;
	r.y= s*v.x+c*v.y;
	return r;
}
