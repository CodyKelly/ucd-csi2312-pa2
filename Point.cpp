//
// Created by Cody Kelly on 10/4/15.
//

#include "Point.h"
#include <cmath>

namespace Clustering
{

    Point::Point()
    {
        dim = 3;
        values = new double[dim];
        for (int x = 0; x < dim; x++)
        {
            values[x] = 0;
        }
    }

    Point::Point(int dimension) : dim(dimension)
    {
        values = new double[dim];
    }

    Point::Point(int dimension, double *vals) : dim(dimension)
    {
        values = new double[dim];

        for (int x = 0; x < dim; x++)
        {
            values[x] = vals[x];
        }
    }

    Point::Point(const Point &pointB) : dim(pointB.dim)
    {
        values = new double[dim];
        for (int x = 0; x < dim; x++)
        {
            values[x] = pointB.values[x];
        }
    }

    Point::~Point()
    {
        delete values;
    }

    Point &Point::operator=(const Point &p)
    {
        if (this == &p)
        {
            return *this;
        }
        else
        {
            if (values != nullptr)
            {
                delete values;
            }

            this->dim = p.dim;
            this->values = new double[dim];

            for (int x = 0; x < this->dim; x++)
            {
                this->values[x] = p.values[x];
            }
        }

        return *this;
    }

    Point &Point::operator*=(double value)
    {
        for (int x = 0; x < this->dim; x++)
        {
            this->values[x] *= value;
        }

        return *this;
    }

    const Point Point::operator*(double value) const
    {
        Point newPoint(this->getDims());

        for (int x = 0; x < this->dim; x++)
        {
            newPoint.values[x] = value * this->values[x];
        }

        return newPoint;
    }

    Point &Point::operator/=(double value)
    {
        if (value != 0)
        {
            for (int x = 0; x < this->dim; x++)
            {
                this->values[x] /= value;
            }
        }

        return *this;
    }

    const Point Point::operator/(double value) const
    {
        Point newPoint(this->getDims());

        if (value != 0)
        {
            for (int x = 0; x < this->dim; x++)
            {
                newPoint.values[x] = this->values[x] / value;
            }
        }

        return newPoint;
    }

    Point &operator+=(Point &lhs, const Point &rhs)
    {
        for (int x = 0; x < lhs.getDims(); x++)
        {
            double newValue = lhs.getValue(x) + rhs.getValue(x);
            lhs.setValue(x, newValue);
        }

        return lhs;
    }

    Point &operator-=(Point &lhs, const Point &rhs)
    {
        for (int x = 0; x < lhs.getDims(); x++)
        {
            double newValue = lhs.getValue(x) - rhs.getValue(x);
            lhs.setValue(x, newValue);
        }

        return lhs;
    }

    const Point operator+(const Point& lhs, const Point& rhs)
    {
        Point newPoint(lhs.getDims());

        for(int x = 0; x < lhs.getDims(); x++)
        {
            double value = lhs.getValue(x) + rhs.getValue(x);
            newPoint.setValue(x, value);
        }

        return newPoint;
    }

    const Point operator-(const Point& lhs, const Point& rhs)
    {
        Point newPoint(lhs.getDims());

        for(int x = 0; x < lhs.getDims(); x++)
        {
            double value = lhs.getValue(x) - rhs.getValue(x);
            newPoint.setValue(x, value);
        }

        return newPoint;
    }

    bool operator==(const Point& lhs, const Point& rhs)
    {
        for (int x = 0; x < lhs.getDims(); x++)
        {
            if(lhs.getValue(x) != rhs.getValue(x))
            {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const Point& lhs, const Point& rhs)
    {
        return(!(lhs==rhs));
    }

    bool operator<(const Point& lhs, const Point& rhs)
    {
        for (int x = 0; x < lhs.getDims(); x++)
        {
            if(lhs.getValue(x) < rhs.getValue(x))
            {
                return true;
            }
        }

        return false;
    }

    bool operator>(const Point& lhs, const Point& rhs)
    {
        for (int x = 0; x < lhs.getDims(); x++)
        {
            if(lhs.getValue(x) > rhs.getValue(x))
            {
                return true;
            }
        }

        return false;
    }

    bool operator<=(const Point& lhs, const Point& rhs)
    {
        for (int x = 0; x < lhs.getDims(); x++)
        {
            if (lhs.getValue(x) > rhs.getValue(x))
            {
                return false;
            }
        }

        return true;
    }

    bool operator>=(const Point& lhs, const Point& rhs)
    {
        for (int x = 0; x < lhs.getDims(); x++)
        {
            if(lhs.getValue(x) < rhs.getValue(x))
            {
                return false;
            }
        }

        return true;
    }

//    std::ostream &operator<<(std::ostream& stream, const Point& point)
//    {
//        stream << '(';
//
//        for (int x = 0; x < point.getDims(); x++)
//        {
//            stream << point.getValue(x);
//
//            if (x != point.getDims() - 1)
//            {
//                stream << ',' << ' ';
//            }
//        }
//
//        stream << ')';
//
//        return stream;
//    }

    double Point::distanceTo(const Point &point) const
    {
        double distance;  // Holds end result
        double sum;  // Holds the sum of all squared deltas

        for (int x = 0; x < dim; x++)
        {
            sum += pow((point.values[x] - values[x]), 2); // find delta value and square it, then add result to sum
        }

        distance = sqrt(sum); // distance is the square root of the sum

        return distance;
    }

    double Point::getValue(int index) const
    {
        return (values[index]);
    }

    void Point::setValue(int i, double d)
    {
        if (i >= 0 || i < dim)
        {
            values[i] = d;
        }
    }

}