#ifndef VEC_H
#define VEC_H

struct Vec{
    vector<float> data;

    Vec(int);
    void init(const vector<float>&) const;

    Vec add(const Vec&) const;
    Vec multiply(float) const;
    float dot(const Vec&) const;

    float model() const;
    int ndim() const;
    float getdim(int) const;

    Vec operator+(const Vec&) const;
    Vec operator*(float) const;
    float operator*(const Vec&) const;
    
    friend ostream& operator<<(ostream&, const Atom&);
};


#endif
