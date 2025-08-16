struct vec3 {
    float x, y, z;

    
    vec2 xx() const { return {x, x}; }
    vec2 xy() const { return {x, y}; }
    vec2 xz() const { return {x, z}; }
    vec2 yx() const { return {y, x}; }
    vec2 yy() const { return {y, y}; }
    vec2 yz() const { return {y, z}; }
    vec2 zx() const { return {z, x}; }
    vec2 zy() const { return {z, y}; }
    vec2 zz() const { return {z, z}; }

    
    vec3 xyz() const { return {x, y, z}; }
    vec3 xzy() const { return {x, z, y}; }
    vec3 yxz() const { return {y, x, z}; }
    vec3 yzx() const { return {y, z, x}; }
    vec3 zxy() const { return {z, x, y}; }
    vec3 zyx() const { return {z, y, x}; }

   
    vec3 operator+(const vec3& other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

   
    vec3 operator-(const vec3& other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    
    vec3 operator*(float scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }

   
    vec3 operator/(float scalar) const {
        return {x / scalar, y / scalar, z / scalar};
    }

    
    vec3 operator-() const {
        return {-x, -y, -z};
    }

    
    vec3& operator+=(const vec3& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    
    vec3& operator-=(const vec3& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

   
    vec3& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    
    vec3& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }
};

vec3 operator*(float scalar, const vec3& v);

