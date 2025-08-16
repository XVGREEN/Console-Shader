namespace shaders{
    #define MAX_STEPS 60
    #define MAX_DIST 20.0
    #define MIN_DIST 0.01
    
    float scene(vec3 p){
       float ground = p.y;
       vec3 c (0,0,-0.5);
       float sphere = sdCircle(p+c,1.0);
    	return fmin(ground,sphere);
    //	return sphere;
    }
    

    float march(vec3 ro, vec3 rd){
		float dist =0.0;
		for(int i= 0;i<MAX_STEPS;i++){
			vec3 p = ro+rd*dist;
			float d = scene(p);
			dist+=d;
			if(abs(d)<=MIN_DIST || dist>=MAX_DIST){
				break;
			}			
		}
		return (dist >= MAX_DIST) ? -1.0 : dist;
 	
	}

    vec3 getNormal(vec3 p){
    	vec3 e(MIN_DIST,0.0,0.0);
    	float x = scene(p+e)-scene(p-e);
    	float y = scene(p+e.yxz())- scene(p-e.yxz());
    	float z = scene(p+e.zyx())- scene(p-e.zyx());
    	return normalize(vec3 (x,y,z));    
    }

    float blinPhong(vec3 n, vec3 l,vec3 v){
    	 vec3 h = normalize(l+v);
    	 float dif = dot(n,-l);
    	 float spec = fmax(dot(n,h),0.0);
    	 spec*=spec*spec*spec*spec;
    	 return (dif+spec)*1.0;
    } 
    

    // shader main function
	float  box_world(vec2 fc ,double t) {
		auto rows = (double) ROWS;
 	    auto colls= (double) COLLS;
	    vec2 uv;   
	    uv = (fc*2.0-vec2(colls,rows))/rows; 	    
        uv.y = -uv.y;
        uv.y*=2.0;
        vec3 light = normalize(vec3(0.4,0.5,0.4));
        vec2 l_rot = rot(light.xz(),t);
        light = vec3 (l_rot.x,light.y,l_rot.y);
        vec3 ro= vec3(0.0,1.7,-1.3);
        vec3 rd = normalize(vec3(uv.x,uv.y,1.0));
        float dist = march(ro,rd);
        vec3 p = ro+rd*dist;
        vec3 n= getNormal(p);
        float l =0.0;    
        if(dist>0) {
             l= blinPhong(n,-light,rd);   
        } 
           
        return l;       
	}

}
