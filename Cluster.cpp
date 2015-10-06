//
// Created by Cody Kelly on 10/4/15.
//

#include "Cluster.h"

namespace Clustering
{
    Cluster::Cluster(const Cluster &other) : __size(other.__size)
    {
        LNodePtr currentNode = other.__points->next;
        PointPtr newPoint;

        for (int x = 0; x < __size; x++)
        {
            newPoint = new Point(*currentNode->p);
            add(newPoint);
            currentNode = currentNode->next;
        }

        delete(currentNode, newPoint);
    }

    Cluster &Cluster::operator=(const Cluster &other)
    {
        if(this == &other)
        {
            return *this;
        }
        else
        {
            LNodePtr currentNode = nullptr;
            PointPtr newPoint = nullptr;

            if(this->__points != nullptr)
            {
                this->deleteNodes();
            }

            this->__size = other.__size;

            for (int x = 0; x < this->__size; x++)
            {
                newPoint = new Point(*currentNode->p);
                this->add(newPoint);
                currentNode = currentNode->next;
            }

            delete currentNode, newPoint;
        }
    }

    Cluster::~Cluster()
    {
        deleteNodes();
    }

    void Cluster::deleteNodes()
    {
        if(this->__points != nullptr)
        {
            LNodePtr currentNode = nullptr;
            LNodePtr nextNode = nullptr;

            currentNode = this->__points;

            for (int x = 0; x < this->__size; x++)
            {
                nextNode = currentNode->next;
                delete currentNode;
                currentNode = nextNode;
            }
            delete this->__points, nextNode, currentNode;
        }
    }

    void Cluster::add(const PointPtr &point)
    {
        LNodePtr oldHead = __points,
                 newHead = new LNode(point, oldHead);

        __points = newHead;
    }
}