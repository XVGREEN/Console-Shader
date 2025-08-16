//inigo quilez heart distance function
/*float sdHeart(vec2 p) {
    if (p.x < 0.0f) 
        p.x = -p.x;
    if (p.y + p.x > 1.0f) {
        vec2 a = sub(p, (vec2){0.25f, 0.75f});
        return sqrt(dot(a, a)) - sqrt(2.0f) / 4.0f;
    }
    vec2 a1 = sub(p, (vec2){0.00f, 1.00f});
    vec2 a2 = sub(p, scale((vec2){0.5f, 0.5f}, 1.0f));
    float d = fmin(dot(a1, a1), dot(a2, a2));
    return sqrt(d) * ((p.x - p.y) >= 0.0f ? 1.0f : -1.0f);
}*/

float sdCircle(vec2 v,float r){
	return length(v)-r;
}
