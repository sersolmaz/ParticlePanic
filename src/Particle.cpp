#include "include/Particle.h"

void Particle::drawParticle()
{
  glBegin(GL_POINTS);
  if(!wall)
  {
    float fast=velocity.length()*5;
    if(fast>1.0f) fast=1.0f;
    //glColor3f((float)(rand() &100) /100.0f,(float)(rand() &100) /100.0f,(float)(rand() &100) /100.0f); //funky
    if(m_properties->getColourEffect())
      glColor3f(m_properties->getRed()+fast,m_properties->getGreen()+fast,m_properties->getBlue()+fast);
    else
      glColor3f(m_properties->getRed(),m_properties->getGreen(),m_properties->getBlue());


    //glColor3f(0.8f,0.5f,0.2f);
  }
  else
  {
    glColor3f(1.0f,0.0f,0.0f);
  }
  glVertex3f(position[0],position[1],-2.0f);
  glEnd();
}

void Particle::updatePosition(double elapsedtime)
{
  position+=velocity*elapsedtime;
}

Vec3 Particle::getPosition() const
{
  return position;
}

void Particle::setPosition(Vec3 pos)
{
  position=pos;
}

void Particle::setVelocity(Vec3 newvel)
{
  velocity = newvel;
}

Vec3 Particle::getVelocity() const
{
  return velocity;
}

void Particle::clearForces()
{
  force=Vec3();
}

void Particle::applyGravity(float m_timestep)
{
  velocity+=Vec3(0.0f,-0.008*m_timestep);
}

void Particle::setForce(Vec3 newforce)
{
  force=newforce;
}

void Particle::addForce(Vec3 addedforce)
{
  force+=addedforce;
}

Vec3 Particle::getForce() const
{
  return force;
}

bool Particle::collision(Particle p) const
{
  Vec3 difference = position - p.getPosition();

  if(std::abs(difference[0])<0.5f && std::abs(difference[1])<0.5f)
    return true;
  else return false;
}

void Particle::addVelocity(Vec3 addedvel)
{
  velocity+=addedvel;
}


void Particle::addPosition(Vec3 pos)
{
  position+=pos;
}

void Particle::updatePrevPosition()
{
  prevPosition=Vec3(position[0],position[1]);
}

Vec3 Particle::getPrevPosition() const
{
  return prevPosition;
}

bool Particle::operator ==(const Particle &_rhs) const
{
  if(position==_rhs.position && velocity==_rhs.velocity) return true;
  else return false;
}

void Particle::setGridPosition(int p)
{
  gridPosition=p;
}

int Particle::getGridPosition() const
{
  return gridPosition;
}

void Particle::setDrag(bool drag)
{
  dragged=drag;
}

bool Particle::getDrag() const
{
  return dragged;
}

bool Particle::getWall() const
{
  return wall;
}

void Particle::setWall(bool newwall)
{
  wall=newwall;
}

ParticleProperties *Particle::getProperties() const
{
  return m_properties;
}

void Particle::setIsObject()
{
  m_isPartOfObject=true;
}

void Particle::setInit()
{
  m_init=true;
}

bool Particle::isInit()
{
  return m_init;
}

bool Particle::isObject()
{
  return m_isPartOfObject;
}
