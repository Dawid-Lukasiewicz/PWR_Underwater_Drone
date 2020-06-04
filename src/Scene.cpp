#include"Scene.hh"


Scene::~Scene()
{
}

void Scene::MoveDrone(double length, double angle, int X)
{
    double length1=length/Speed;
    bool Stop=false;
    for (int i=0; i<Speed; i++)
    {
        drones[X]->moveUpDown(length1, angle);
        usleep(25000);
        for(shared_ptr<Obstacle> &tmp : obstacles)
        {
            if(tmp!=drones[X])
            {
                if(tmp->collision(*drones[X]))
                {
                    drones[X]->moveUpDown(-length1, angle);
                    Stop=true;
                    break;
                }
            }
        }
        if(Stop==true)
            break;
    }
}

void Scene::RotateDrone(double angle, int X)
{
    double angle1=angle/Speed;
    bool Stop=false;
    for (int i=0; i<Speed; i++)
    {
        drones[X]->rotate(angle1);
        usleep(25000);
        for(shared_ptr<Obstacle> &tmp : obstacles)
            {
                if(tmp!=drones[X])
                {
                    if(tmp->collision(*drones[X]))
                    {
                        drones[X]->rotate(-angle1);
                        Stop=true;
                        break;
                    }
                }
            }
        if(Stop==true)
            break;
    }
}
void Scene::Draw()
{
    for(shared_ptr<Obstacle> &tmp : obstacles)
    {
        tmp->draw();
    }       
}

void Scene::ChangeSpeed(int speed)
{
    std::cout<<"Podaj prędkość: ";
    Speed=speed;
}