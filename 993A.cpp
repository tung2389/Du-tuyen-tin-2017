#include <bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
};
point topleft,bottomright;
int maxx=-9999,minx=9999,maxy=-9999,miny=9999;
int maxpx=-9999,minpx=9999,maxpy=-9999,minpy=9999;
point diamond[6];
point p1,p2,p3,p4,h1,h2,h3,h4;
int main()
{
    int x1,y1,x2,y2;
    for(int i=1;i<=4;i++)
    {
        int x,y;
        cin >> x >> y;
        maxx=max(x,maxx);
        minx=min(x,minx);
        maxy=max(y,maxy);
        miny=min(y,miny);
    }
    h1.x=minx;
    h1.y=maxy;
    h2.x=maxx;
    h2.y=maxy;
    h3.x=maxx;
    h3.y=miny;
    h4.x=minx;
    h4.y=miny;
    topleft.x=minx;
    topleft.y=maxy;
    bottomright.x=maxx;
    bottomright.y=miny;
    for(int i=1;i<=4;i++)
    {
        cin >> diamond[i].x >> diamond[i].y;
        maxpx=max(maxpx,diamond[i].x);
        minpx=min(minpx,diamond[i].x);
        maxpy=max(maxpy,diamond[i].y);
        minpy=min(minpy,diamond[i].y);
    }
    if(diamond[1].x>bottomright.x && diamond[2].x>bottomright.x && diamond[3].x>bottomright.x && diamond[4].x>bottomright.x)
    {
        cout << "NO" << "\n";
        return 0;
    }
    if(diamond[1].x<topleft.x && diamond[2].x<topleft.x && diamond[3].x<topleft.x && diamond[4].x<topleft.x)
    {
        cout << "NO" << "\n";
        return 0;
    }
    if(diamond[1].y>topleft.y && diamond[2].y>topleft.y && diamond[3].y>topleft.y && diamond[4].y>topleft.y)
    {
        cout << "NO" << "\n";
        return 0;
    }
    if(diamond[1].y<bottomright.y && diamond[2].y<bottomright.y && diamond[3].y<bottomright.y && diamond[4].y<bottomright.y)
    {
        cout << "NO" << "\n";
        return 0;
    }
    p1.x=(maxpx+minpx)/2;
    p1.y=maxpy;
    p2.x=maxpx;
    p2.y=(maxpy+minpy)/2;
    p3.x=p1.x;
    p3.y=minpy;
    p4.x=minpx;
    p4.y=p2.y;
    if(p1.y>topleft.y && p2.y>topleft.y && p4.y>topleft.y && (((h1.x-p3.x)*(p2.y-p3.y) - (h1.y-p3.y)*(p2.x-p3.x)>0)||
                                                              (h2.x-p3.x)*(p4.y-p3.y) - (h2.y-p3.y)*(p4.x-p3.x)<0
                                                              ))
    {
        cout << "NO" << "\n";
        return 0;
    }
    if(p2.y<bottomright.y && p3.y<bottomright.y && p4.y < bottomright.y && (((h4.x-p2.x)*(p1.y-p2.y)-(h4.y-p2.y)*(p1.x-p2.x))>0||
                                                                            ((h3.x-p4.x)*(p1.y-p4.y)-(h3.y-p4.y)*(p1.x-p4.x))<0
                                                                            ))
    {
        cout << "NO" << "\n";
        return 0;
    }
    cout << "YES" << "\n";
}
