
float fract(float x){ 
	return x- floor(x);
}
float step(float x,float y){
	return (x>y)?1:0;
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

float pulse (float time,float bpm){
    float beatTime = 60.0 / bpm;
    float t = fmod(time, beatTime) / beatTime;
    return jump(t);
}


float clamp(float x, float minVal, float maxVal) {
    if (x < minVal) return minVal;
    if (x > maxVal) return maxVal;
    return x;
}
