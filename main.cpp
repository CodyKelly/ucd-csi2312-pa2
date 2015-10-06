#include <iostream>
#include "Point.h"
#include "Cluster.h"
#include <cassert>

using namespace std;

int main()
{
    Clustering::PointPtr point = new Clustering::Point(3, new double[3]{2, 3, 4});

    Clustering::Cluster clust;
    clust.add(point);

    return 0;
}