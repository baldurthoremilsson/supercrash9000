// MapSide.cpp

#include "MapSide.h"
#include "MapPoint.h"
#include <GL/gl.h>
#include <GL/glut.h>

MapSide::MapSide(int x, int y) {
	X = x;
	Y = y;
	
	panelColor.setColor(0.0, 0.1, 0.5);
	gridColor.setColor(0.0, 1.0, 1.0);
	
	points = new MapPoint*[x+1];
	for (int row = 0; row < x+1; row++) {
		points[row] = new MapPoint[y+1];
	}
}

MapSide::MapSide(int x, int y, Color panel) {
	X = x;
	Y = y;
	
	//panelColor.setColor(0.0, 0.1, 0.5);
	panelColor = panel;
	gridColor.setColor(0.0, 1.0, 1.0);
	
	points = new MapPoint*[x+1];
	for (int row = 0; row < x+1; row++) {
		points[row] = new MapPoint[y+1];
	}
}

MapSide::~MapSide() {
}

void MapSide::setX(int x) {
	X = x;
}

void MapSide::setY(int y) {
	Y = y;
}

int MapSide::getX() {
	return X;
}

int MapSide::getY() {
	return Y;
}

void MapSide::setNorth(MapSide *s, Edge sn) {
	northSide = s;
	northEdge = sn;
}

void MapSide::setSouth(MapSide *s, Edge sn) {
	southSide = s;
	southEdge = sn;
}

void MapSide::setEast(MapSide *s, Edge sn) {
	eastSide = s;
	eastEdge = sn;
}

void MapSide::setWest(MapSide *s, Edge sn) {
	westSide = s;
	westEdge = sn;
}

MapSide* MapSide::getSide(Edge e) {
	if(e == NORTH)
		return northSide;
	if(e == SOUTH)
		return southSide;
	if(e == EAST)
		return eastSide;
	if(e == WEST)
		return westSide;
}

Edge MapSide::getEdge(Edge e) {
	if(e == NORTH)
		return northEdge;
	if(e == SOUTH)
		return southEdge;
	if(e == EAST)
		return eastEdge;
	if(e == WEST)
		return westEdge;
}

MapPoint* MapSide::getPoint(int x, int y) {
	return &points[x][y];
}

void MapSide::addObject(SuperObject *o) {
	objects.push_back(o);
}

void MapSide::removeObject(SuperObject *o) {
	objects.remove(o);
}

bool MapSide::wallOnPoint(int x, int y) {
	if(getPoint(x,y)->getHorizWall() || getPoint(x,y)->getVertWall() ||
	   getPoint(x,y-1)->getVertWall() || getPoint(x-1,y)->getHorizWall())
		return true;
	return false;
}

void MapSide::displayWall(float *a, float *b, float *c, float *d, float *e, float *f, float *g, float *h) {
	glVertex3fv(a); glVertex3fv(c); glVertex3fv(d); glVertex3fv(b);
	glVertex3fv(f); glVertex3fv(h); glVertex3fv(g); glVertex3fv(e);
	glVertex3fv(b); glVertex3fv(d); glVertex3fv(h); glVertex3fv(f);
	glVertex3fv(e); glVertex3fv(g); glVertex3fv(c); glVertex3fv(a);
	glVertex3fv(a); glVertex3fv(b); glVertex3fv(f); glVertex3fv(e);
}

void MapSide::display() {
	glColor3fv(gridColor.get3fv());
	float Xoff = X/2.0;
	float Yoff = Y/2.0;
	float gridHeight = 0.05;
	glBegin(GL_QUADS);
	for(int x = 0; x < X; x++) {
		glVertex3f(x-Xoff + 0.48,       0.00, -( Yoff));
		glVertex3f(x-Xoff + 0.50, gridHeight, -( Yoff+gridHeight));
		glVertex3f(x-Xoff + 0.50, gridHeight, -(-Yoff-gridHeight));
		glVertex3f(x-Xoff + 0.48,       0.00, -(-Yoff));
		glVertex3f(x-Xoff + 0.50, gridHeight, -( Yoff+gridHeight));
		glVertex3f(x-Xoff + 0.52,       0.00, -( Yoff));
		glVertex3f(x-Xoff + 0.52,       0.00, -(-Yoff));
		glVertex3f(x-Xoff + 0.50, gridHeight, -(-Yoff-gridHeight));
	}
	for(int y = 0; y < Y; y++) {
		glVertex3f( Xoff           ,       0.00, -(y-Yoff + 0.48));
		glVertex3f( Xoff+gridHeight, gridHeight, -(y-Yoff + 0.50));
		glVertex3f(-Xoff-gridHeight, gridHeight, -(y-Yoff + 0.50));
		glVertex3f(-Xoff           ,       0.00, -(y-Yoff + 0.48));
		glVertex3f( Xoff+gridHeight, gridHeight, -(y-Yoff + 0.50));
		glVertex3f( Xoff           ,       0.00, -(y-Yoff + 0.52));
		glVertex3f(-Xoff           ,       0.00, -(y-Yoff + 0.52));
		glVertex3f(-Xoff-gridHeight, gridHeight, -(y-Yoff + 0.50));
	}
	
	float leftdown, leftup, rightup, rightdown;
	float a[3], b[3], c[3], d[3], e[3], f[3], g[3], h[3];
	for(int x = 0; x <= X; x++) {
		for(int y = 0; y <= Y; y++) {
			if(getPoint(x,y)->getHorizWall()) {
				leftup = x-X/2.0-0.5;
				leftdown = leftup;
				rightup = x-X/2.0+0.5;
				rightdown = rightup;
				if(x==0)
					leftdown += 0.5;
				else if(x==X)
					rightdown -= 0.5;
				
				a[0] = e[0] = leftup;
				b[0] = f[0] = rightup;
				c[0] = g[0] = leftdown;
				d[0] = h[0] = rightdown;
				
				a[2] = b[2] = c[2] = d[2] = -(y-Y/2.0+WALLWIDTH/2.0-0.5);
				e[2] = f[2] = g[2] = h[2] = -(y-Y/2.0-WALLWIDTH/2.0-0.5);
				
				a[1] = b[1] = e[1] = f[1] = WALLHEIGHT;
				c[1] = d[1] = g[1] = h[1] = 0.0;
				
				glColor3fv(getPoint(x,y)->getHorizWall()->get3fv());
				this->displayWall(a,b,c,d,e,f,g,h);
			}
			if(getPoint(x,y)->getVertWall()) {
				leftup = y-Y/2.0-0.5;
				leftdown = leftup;
				rightup = y-Y/2.0+0.5;
				rightdown = rightup;
				if(y==0)
					leftdown += 0.5;
				else if(y==Y)
					rightdown -= 0.5;
				
				a[2] = e[2] = -leftup;
				b[2] = f[2] = -rightup;
				c[2] = g[2] = -leftdown;
				d[2] = h[2] = -rightdown;
				
				a[0] = b[0] = c[0] = d[0] = x-X/2.0+WALLWIDTH/2.0-0.5;
				e[0] = f[0] = g[0] = h[0] = x-X/2.0-WALLWIDTH/2.0-0.5;
				
				a[1] = b[1] = e[1] = f[1] = WALLHEIGHT;
				c[1] = d[1] = g[1] = h[1] = 0.0;
				
				glColor3fv(getPoint(x,y)->getVertWall()->get3fv());
				this->displayWall(a,b,c,d,e,f,g,h);
			}
		}
	}
	glEnd();
	
	glColor3fv(panelColor.get3fv());
	glBegin(GL_QUADS);
		glVertex3f(-X/2.0, 0.0, -Y/2.0);
		glVertex3f(-X/2.0, 0.0,  Y/2.0);
		glVertex3f( X/2.0, 0.0,  Y/2.0);
		glVertex3f( X/2.0, 0.0, -Y/2.0);
	glEnd();
	
	for(list<SuperObject*>::iterator it = objects.begin(); it != objects.end(); it++)
		(*it)->display();
}

void MapSide::update(int time) {
}

void MapSide::keyboardUp(unsigned char key) {
}

void MapSide::keyboardDown(unsigned char key) {
}

void MapSide::keyboardSpecialUp(int key) {
}

void MapSide::keyboardSpecialDown(int key) {
}
