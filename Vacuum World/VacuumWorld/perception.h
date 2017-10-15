#ifndef PERCEPTION_H
#define PERCEPTION_H


class Perception
{
public:
    Perception();

    bool location;
    bool isDirty;

    void setisDirty(bool x);

    void setlocation(bool x);
};

#endif // PERCEPTION_H
