//
// Created by Cody Kelly on 10/4/15.
//

#ifndef CLUSTERING_POINT_H
#define CLUSTERING_POINT_H

#include <iosfwd>

namespace Clustering {

    class Point {
    private:
        int dim;        // number of dimensions of the point
        double *values; // values of the point's dimensions

    public:
        Point();
        Point(int);
        Point(int, double *);

        // Big three: cpy ctor, overloaded operator=, dtor
        Point(const Point &);
        Point &operator=(const Point &);
        ~Point();

        // Accessors & mutators
        int getDims() const { return dim; }
        void setValue(int, double);
        double getValue(int) const;

        // Functions
        double distanceTo(const Point &) const;

        // Overloaded operators

        // Members
        Point &operator*=(double);
        Point &operator/=(double);
        const Point operator*(double) const; // prevent (p1*2) = p2;
        const Point operator/(double) const;

        // Note: 1-based index!
        double &operator[](int index) { return values[index - 1]; } // TODO out-of-bds?

        // Friends
        friend Point &operator+=(Point &, const Point &);
        friend Point &operator-=(Point &, const Point &);
        friend const Point operator+(const Point &, const Point &);
        friend const Point operator-(const Point &, const Point &);

        friend bool operator==(const Point &, const Point &);
        friend bool operator!=(const Point &, const Point &);

        friend bool operator<(const Point &, const Point &);
        friend bool operator>(const Point &, const Point &);
        friend bool operator<=(const Point &, const Point &);
        friend bool operator>=(const Point &, const Point &);

        // TODO: Fix strange errors in these:
        /*
        friend std::ostream &operator<<(std::ostream &, const Point &);
        friend std::ostream &operator>>(std::ostream &, const Point &);
         */
    };

    Point &operator+=(Point &, const Point &);
    Point &operator-=(Point &, const Point &);
    const Point operator+(const Point &, const Point &);
    const Point operator-(const Point &, const Point &);

    bool operator==(const Point &, const Point &);
    bool operator!=(const Point &, const Point &);

    bool operator<(const Point &, const Point &);
    bool operator>(const Point &, const Point &);
    bool operator<=(const Point &, const Point &);
    bool operator>=(const Point &, const Point &);

    /*
    std::ostream &operator<<(std::ostream &, const Point &);
    std::ostream &operator>>(std::ostream &, const Point &);
     */
}
#endif //CLUSTERING_POINT_H
