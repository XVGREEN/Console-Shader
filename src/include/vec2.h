struct vec2{
	float x,y;
};
vec2  fract (vec2 v){
	vec2 r   {fract(v.x),fract(v.y)};
	return r;
}

vec2 step (vec2 v1,vec2 v2){
	vec2 r;
	r.x= step(v1.x,v2.x);
	r.y= step(v1.y,v2.y);
}

vec2 cos(vec2 v){
	return (vec2){cos(v.x),cos(v.y)};
}

vec2 sin(vec2 v){
	return (vec2){sin(v.x),sin(v.x)};
}
vec2 abs(vec2 v){
	v.x=fabs(v.x);
	v.y= fabs(v.y);
	return v;
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
vec2 scale (vec2  v, float s){

	v.x*=s;
	v.y*=s;
	return v;   	
}
vec2 add(vec2 v1, vec2 v2){
	v1.x+=v2.x;
	v1.y+=v2.y;
	return v1;
}
vec2 sub(vec2 v1, vec2 v2){
    v1.x-=v2.x;
    v1.y-=v2.y;
    return v1;
}
float dot(vec2 v1, vec2 v2){

	return v1.x*v2.x+v1.y*v2.y;
}

float length(vec2 v){
     return v.x*v.x+v.y*v.y;
}

vec2 normalize(vec2 v){
	float r= length(v);
	v.x/=r;
	v.y/=r;
	return v;
}



