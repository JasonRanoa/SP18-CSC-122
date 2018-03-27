//
// Created by TheLoneWoof on 3/26/18.
//

#ifndef CH17_PR13_RUNNING_BACK_VMAC_IMAGEMAP_H
#define CH17_PR13_RUNNING_BACK_VMAC_IMAGEMAP_H

#include <list>

struct Coord {
    short x;
    short y;
    Coord() {
        x = 0;
        y = 0;
    }
    Coord(int argX, int argY) {
        x = argX;
        y = argY;
    }
};

class ImageMap : std::list<Coord> {
    void add(Coord[]);
    void add(short *);
};


#endif //CH17_PR13_RUNNING_BACK_VMAC_IMAGEMAP_H
