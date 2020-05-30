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
        for(shared_ptr<Box> &tmp : boxes)
        {
            if(tmp->collision(*drones[X]))
            {
                Stop=true;
                break;
            }
        }
        for(shared_ptr<Surface> &tmp : surface)
        {
            if(tmp->collision(*drones[X]))
            {
                Stop=true;
                break;
            }
        }
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
        for(shared_ptr<Box> &tmp : boxes)
            {
                if(tmp->collision(*drones[X]))
                {
                    Stop=true;
                    break;
                }
            }
        for(shared_ptr<Surface> &tmp : surface)
        {
            if(tmp->collision(*drones[X]))
            {
                Stop=true;
                break;
            }
        }
        if(Stop==true)
            break;
    }
}
void Scene::Draw()
{
    for(shared_ptr<Drone> &tmp : drones)
        tmp->draw();
    for(shared_ptr<Box> &tmp : boxes)
        tmp->draw();
    for(shared_ptr<Surface> &tmp : surface)
        tmp->draw();
}