#ifndef SCENE_HPP
#define SCENE_HPP

#include "vp.hpp"
#include "px.hpp"
#include "viewport.hpp"
#include "canvas.hpp"
#include "sphere.hpp"
#include "light.hpp"

class scene{
    private:
        vp O;                           //camera/observer's position
        viewport vw;                    //viewport
        canvas c;                       //canvas
        std::vector<sphere> spheres;    //spheres who are in the scene
        std::vector<light*> lights;     //lights whoa are in the scene
        double dx, dy;                  //width and heigth of each pixel of canvas in real world
    
        double compute_lighting(vp P, vp N, vp V, int s); //calculate all the light in an specific point

        px trace_ray_spheres(vp O, vp D, double t_min, double t_max); //trace rays of from observer to direction D
        
        vp xy(int i, int j); //direction of the ray from the observer to the real world passing through the pixel i,j of the canvas

    public:
        scene(vp O, viewport vw, canvas c);        
    
        void add_sphere(sphere s);
        void add_light(light *l);
        
        void draw_scenario();

        void save_scenario(const char* image_name);
};

#endif
