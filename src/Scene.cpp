#include"Scene.hh"


Scene::~Scene()
{
}

void Scene::MoveDrone(double length, double angle, int X)
{
    double length1=length/100;
    bool Stop=false;
    for (int i=0; i<100; i++)
    {
        drones[X]->moveUpDown(length1, angle);
        usleep(25000);
        /*
        for(shared_ptr<Drone> &tmp : drones)
        {
            if(tmp!=drones[X])
            {
                if(tmp->collision(*drones[X]))
                    {
                        Stop=true;
                        break;
                    }
            }
        }
        */
        for(shared_ptr<Obstacle> &tmp : boxes)
        {
            if(tmp!=drones[X])
            {
                if(tmp->collision(*drones[X]))
                {
                    Stop=true;
                    break;
                }
            }
        }
        /*
        for(shared_ptr<Surface> &tmp : surface)
        {
            if(tmp->collision(*drones[X]))
            {
                Stop=true;
                break;
            }
        }
        */
        if(Stop==true)
            break;
    }
}

void Scene::RotateDrone(double angle, int X)
{
    double angle1=angle/100;
    bool Stop=false;
    for (int i=0; i<100; i++)
    {
        drones[X]->rotate(angle1);
        usleep(25000);
        /*
        for(shared_ptr<Drone> &tmp : drones)
        {
            if(tmp!=drones[X])
            {
                if(tmp->collision(*drones[X]))
                    {
                        Stop=true;
                        break;
                    }
            }
        }
        */
        for(shared_ptr<Obstacle> &tmp : boxes)
            {
                if(tmp!=drones[X])
                {
                    if(tmp->collision(*drones[X]))
                    {
                        Stop=true;
                        break;
                    }
                }
            }
            /*
        for(shared_ptr<Surface> &tmp : surface)
        {
            if(tmp->collision(*drones[X]))
            {
                Stop=true;
                break;
            }
        }
        */
        if(Stop==true)
            break;
    }
}
void Scene::Draw()
{
    for(shared_ptr<Obstacle> &tmp : boxes)
    {
        tmp->draw();
    }
        
}
/*
{
if(dynamic_pointer_cast<Drone>(tmp)==Drone)
    dynamic_pointer_cast<Drone>(tmp)->draw();
else if(dynamic_pointer_cast<Box>(tmp)==Box)
    dynamic_pointer_cast<Box>(tmp)->draw();
else if(dynamic_pointer_cast<Surface>(tmp)==Surface)
    dynamic_pointer_cast<Surface>(tmp)->draw();
}
*/