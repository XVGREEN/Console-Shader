 struct vec2 {
     float x, y;
     vec2 (float X,float Y){
     	x=X;
     	y=Y;
     }
     vec2 (float X){
     	x=X;
     	y=X;
     } 
     vec2 (){
     	x=y=0.0;
     }   
     vec2 xx() const { return {x, x}; }
     vec2 xy() const { return {x, y}; }
     vec2 yx() const { return {y, x}; }
     vec2 yy() const { return {y, y}; }
 
   
     vec2 operator+(const vec2& other) const {
         return {x + other.x, y + other.y};
     }
 
     
     vec2 operator-(const vec2& other) const {
         return {x - other.x, y - other.y};
     }
 
    
     vec2 operator*(float scalar) const {
         return {x * scalar, y * scalar};
     }
 
    
     vec2 operator/(float scalar) const {
         return {x / scalar, y / scalar};
     }
 
     
     vec2 operator-() const {
         return {-x, -y};
     }
 
     
     vec2& operator+=(const vec2& other) {
         x += other.x;
         y += other.y;
         return *this;
     }
 
    
     vec2& operator-=(const vec2& other) {
         x -= other.x;
         y -= other.y;
         return *this;
     }
 
    
     vec2& operator*=(float scalar) {
         x *= scalar;
         y *= scalar;
         return *this;
     }
 
   
     vec2& operator/=(float scalar) {
         x /= scalar;
         y /= scalar;
         return *this;
     }
    
      
 };
 
 
 vec2 operator*(float scalar, const vec2& v) {
     return v * scalar;
 }

float length(const vec2  &v){
	return sqrt(v.x*v.x+v.y*v.y);
}

float dot (vec2 a,vec2 b){
	return a.x*b.x+ a.y*b.y;
}
vec2 normalize(const vec2 & v){
	float r= length(v);
	return v/r;
}

vec2 rot(vec2 v, float angle) {
    float c = cos(angle);
    float s = sin(angle);
    return vec2(c * v.x - s * v.y,
                s * v.x + c * v.y);
}
