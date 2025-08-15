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
vec2 abs(vec2 v){
	v.x=fabs(v.x);
	v.y= fabs(v.y);
	return v;
}
float length(vec2 v){ 
	return sqrt(v.x*v.x+v.y*v.y);
}

float jump(float x){
	return -4.0*x*x+4.0*x;
}
float invLerp(float edge0, float edge1, float x){

	return  (x - edge0) / (edge1 - edge0);
}

float smoothstep(float edge0, float edge1, float x) {      
      float t = (x - edge0) / (edge1 - edge0);
      if (t < 0.0f) t = 0.0f;
      if (t > 1.0f) t = 1.0f;
      return t * t * (3.0f - 2.0f * t);
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
vec2 normalize(vec2 v){
	float r= length(v);
	v.x/=r;
	v.y/=r;
	return v;
}

float hash(vec2 p) {
    float h = dot(p, (vec2){127.1f, 311.7f});
    h = sin(h) * 43758.5453f;
    return h - floor(h);
}

// inigo quilez heart sdf c version
float sdHeart(vec2 p) {
    if (p.x < 0.0f) p.x = -p.x;
    if (p.y + p.x > 1.0f) {
        vec2 a = sub(p, (vec2){0.25f, 0.75f});
        return sqrt(dot(a, a)) - sqrt(2.0f) / 4.0f;
    }
    vec2 a1 = sub(p, (vec2){0.00f, 1.00f});
    vec2 a2 = sub(p, scale((vec2){0.5f, 0.5f}, fmax(p.x + p.y, 0.0f)));
    float d = fmin(dot(a1, a1), dot(a2, a2));
    return sqrt(d) * ((p.x - p.y) >= 0.0f ? 1.0f : -1.0f);
}


