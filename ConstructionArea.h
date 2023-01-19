#ifndef _CONSTRUCTIONAREA_H_
#define _CONSTRUCTIONAREA_H_
using namespace std;

class ConstructionArea
{
private:
    int length = 1;
    int width = 1;

public:
    int **construction_area;
    // ConstructionArea(/* args */);
    ConstructionArea(int length, int width);
    ~ConstructionArea();

    void set_length(int _length);
    void set_width(int _width);
    void set_construction_area(int _length, int _width);
    // void set_construction_area_value(int n, int i, int j);

    int get_length();
    int get_width();
    // int **get_construction_area();
    // int get_construction_area_value(int i, int j);

    bool removable(int l, int w);
    void print();
};
#endif
