#include"Scene.hh"


Scene::~Scene()
{
}

void Scene::MoveDrone(double length, int X)
{
    double length1=length/Speed;
    bool Stop=false;
    for (int i=0; i<Speed; i++)
    {
        drones[X]->moveUpDown(length1,0);
        usleep(25000);
        for(shared_ptr<Obstacle> &tmp : obstacles)
        {
            if(tmp!=drones[X])
            {
                if(tmp->collision(*drones[X]))
                {
                    drones[X]->moveUpDown(-length1,0);
                    Stop=true;
                    break;
                }
            }
        }
        if(Stop==true)
            break;
    }
}

void Scene::MoveDroneUpDown(double length, double angle, int X)
{
    double length1=length/Speed, angle1=angle/Speed;
    bool Stop=false;

    for (int i=0; i<Speed; i++)
    {
        drones[X]->rotateY(-angle1);
        usleep(25000);
        for(shared_ptr<Obstacle> &tmp : obstacles)
        {
            if(tmp!=drones[X])
            {
                if(tmp->collision(*drones[X]))
                {
                    drones[X]->rotateY(angle1);
                    Stop=true;
                    break;
                }
            }
        }
        if(Stop==true)
            break;
    }

    for (int i=0; i<Speed; i++)
    {
        drones[X]->moveUpDown(length1,0);
        usleep(25000);
        for(shared_ptr<Obstacle> &tmp : obstacles)
        {
            if(tmp!=drones[X])
            {
                if(tmp->collision(*drones[X]))
                {
                    drones[X]->moveUpDown(-length1,0);
                    Stop=true;
                    break;
                }
            }
        }
        if(Stop==true)
            break;
    }

    for (int i=0; i<Speed; i++)
    {
        drones[X]->rotateY(angle1);
        usleep(25000);
        for(shared_ptr<Obstacle> &tmp : obstacles)
        {
            if(tmp!=drones[X])
            {
                if(tmp->collision(*drones[X]))
                {
                    drones[X]->rotateY(-angle1);
                    Stop=true;
                    break;
                }
            }
        }
        if(Stop==true)
            break;
    }
}

void Scene::RotateDrone(double angle, int X, char axis)
{
    double angle1=angle/Speed;
    bool Stop=false;
    if(axis=='z')
    {
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
    if(axis=='y')
    {
        for (int i=0; i<Speed; i++)
        {
            drones[X]->rotateY(-angle1);
            usleep(25000);
            for(shared_ptr<Obstacle> &tmp : obstacles)
                {
                    if(tmp!=drones[X])
                    {
                        if(tmp->collision(*drones[X]))
                        {
                            drones[X]->rotateY(angle1);
                            Stop=true;
                            break;
                        }
                    }
                }
            if(Stop==true)
                break;
        }
    }
    if(axis=='x')
    {
        for (int i=0; i<Speed; i++)
        {
            drones[X]->rotateX(angle1);
            usleep(25000);
            for(shared_ptr<Obstacle> &tmp : obstacles)
                {
                    if(tmp!=drones[X])
                    {
                        if(tmp->collision(*drones[X]))
                        {
                            drones[X]->rotateX(-angle1);
                            Stop=true;
                            break;
                        }
                    }
                }
            if(Stop==true)
                break;
        }
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