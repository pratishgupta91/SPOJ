#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point 
{
    float x;
    float y;

    Point(float a, float b) : x(a), y(b) {}
    ~Point() {}
} p0(0, 0);

int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int ccw(Point a, Point b, Point c)
{
    float  area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area < 0) return -1;           // clockwise
    else if (area > 0) return 1;       // counter-clockwise
    else return 0;                      // collinear
}

bool compare(Point p1, Point p2)
{
   // Find orientation
   int orientation = ccw(p0, p1, p2);
   cout<<p1.x<<" "<<p1.y<<" "<<p2.x<<" "<<p2.y<<" "<<orientation<<"\n";
   if (orientation == 1)
   {
       return true;
   }
   if(orientation == 0)
   {
       return distSq(p0, p1) < distSq(p0, p2);
   }
   return false;
}
 

vector<Point> convexHull(vector<Point> points)
{
    vector<Point> hull;
    
    if(points.size() == 0) return hull;

    // Step 1 - Get the point with minimum Y coordinate
    int minY = points[0].y;
    for(int i = 0; i < points.size(); ++i)
    {
        if(points[i].y < minY) 
        {
            minY = i;
        }
    }

    swap(points[0], points[minY]);
    p0 = points[0];

    cout<<p0.x<<" "<<p0.y<<"\n";

    // Step 2 - Sort the points by polar angle w.r.t start
    sort(points.begin() + 1, points.end(), compare);

    for(int i = 0; i < points.size(); i++)
    {
        cout<<points[i].x<<" "<<points[i].y<<"\n";
    }
    return hull;
}

int main()
{
    vector<Point> points;
    points.push_back(Point(-1, 1));
    points.push_back(Point(1, 1));
    points.push_back(Point(0, 0));
    points.push_back(Point(0, 2));
    convexHull(points);
    return 0;
}