#ifndef POINT_H
#define POINT_H

class Point {
private:
    float x, y;

public:
    Point(float x, float y);
    void deplace(float dx, float dy);
    void affiche() const;
};

#endif