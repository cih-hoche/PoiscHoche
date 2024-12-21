#ifndef POISCHOCHE_OFFSET_H
#define POISCHOCHE_OFFSET_H


namespace display{
    class Offset{
    public:
        unsigned int x{0}, y{0}, x_blocks{0}, y_blocks{0};
        void set(int _x, int _y);
        void setx(int _x);
        void sety(int _y);
    };
}


#endif //POISCHOCHE_OFFSET_H
