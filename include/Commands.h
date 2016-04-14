#ifndef COMMANDS_H_
#define COMMANDS_H_

#include "include/World.h"

class Command
{
public:
  ~Command() {}
  virtual void execute() = 0;
  void setWorld(World *_world);
protected:
  World *m_world;
};

class ClearWorld : public Command
{
public:
  ClearWorld(){}
  ~ClearWorld(){}
  void execute();
};

class MouseErase : public Command
{
public:
  MouseErase(){}
  ~MouseErase(){}
  void execute();
  void setxy(int x, int y);
private:
  int m_x, m_y;
};

class MouseDraw : public Command
{
public:
  MouseDraw(){}
  ~MouseDraw(){}
  void execute();
  void setxy(int _x, int _y);
private:
  int m_x, m_y;
};

class MouseDrag : public Command
{
public:
  MouseDrag(){}
  ~MouseDrag(){}
  void execute();
  void setxy(int _x, int _y);
private:
  int m_x, m_y;
};

class SelectDraggedParticles : public Command
{
public:
  SelectDraggedParticles(){}
  ~SelectDraggedParticles(){}
  void execute();
  void setxy(int _x, int _y);
private:
  int m_x, m_y;
};

class MouseDragEnd : public Command
{
public:
  MouseDragEnd(){}
  ~MouseDragEnd(){}
  void execute();
  void setxy(int _x, int _y);
private:
  int m_x, m_y;
};

class ResizeWorld : public Command
{
public:
  ResizeWorld(){}
  ~ResizeWorld(){}
  void execute();
  void setwh(int _w, int _h);
private:
  int m_w, m_h;
};

#endif // COMMAND
