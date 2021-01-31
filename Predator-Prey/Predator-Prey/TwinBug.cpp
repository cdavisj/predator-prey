#include "TwinBug.h"
#include "Organism.h"

TwinBug::TwinBug(World* aWorld, int xcoord, int ycoord) : Organism(aWorld, xcoord, ycoord)
{
    dead = false;
}

void TwinBug::move()
{
    if (world->getAt(x, y + 1) != NULL)
    {
        if (world->getAt(x, y + 1)->getType() == ANT || world->getAt(x, y + 1)->getType() == BUG)
        {
            delete world->getAt(x, y + 1);
            movesTo(x, y + 1);
            return;
        }
        else if (world->getAt(x, y + 1)->getType() == TWINBUG)
        {
            // delete twin bug that we have come into contact with
            delete world->getAt(x, y + 1);
            world->setAt(x, y + 1, NULL);

            // kill current twin bug
            dead = true;

            if (world->getAt(x, y - 1) != NULL)
            {
                delete world->getAt(x, y - 1);
                world->setAt(x, y - 1, NULL);
            }

            if (world->getAt(x - 1, y) != NULL)
            {
                delete world->getAt(x - 1, y);
                world->setAt(x - 1, y, NULL);
            }

            if (world->getAt(x + 1, y) != NULL)
            {
                delete world->getAt(x + 1, y);
                world->setAt(x + 1, y, NULL);
            }

            return;
        }
    }

    if (world->getAt(x, y - 1) != NULL)
    {
        if (world->getAt(x, y - 1)->getType() == ANT || world->getAt(x, y - 1)->getType() == BUG)
        {
            delete world->getAt(x, y - 1);
            movesTo(x, y - 1);
            return;
        }
        else if (world->getAt(x, y - 1)->getType() == TWINBUG)
        {
            // delete twin bug that we have come into contact with
            delete world->getAt(x, y - 1);
            world->setAt(x, y - 1, NULL);

            // kill current twin bug
            dead = true;

            if (world->getAt(x, y + 1) != NULL)
            {
                delete world->getAt(x, y + 1);
                world->setAt(x, y + 1, NULL);
            }

            if (world->getAt(x - 1, y) != NULL)
            {
                delete world->getAt(x - 1, y);
                world->setAt(x - 1, y, NULL);
            }

            if (world->getAt(x + 1, y) != NULL)
            {
                delete world->getAt(x + 1, y);
                world->setAt(x + 1, y, NULL);
            }

            return;
        }
    }

    if (world->getAt(x - 1, y) != NULL)
    {
        if (world->getAt(x - 1, y)->getType() == ANT || world->getAt(x - 1, y)->getType() == BUG)
        {
            delete world->getAt(x - 1, y);
            movesTo(x - 1, y);
            return;
        }
        else if (world->getAt(x - 1, y)->getType() == TWINBUG)
        {
            // delete twin bug that we have come into contact with
            delete world->getAt(x - 1, y);
            world->setAt(x - 1, y, NULL);

            // kill current twin bug
            dead = true;

            if (world->getAt(x, y + 1) != NULL)
            {
                delete world->getAt(x, y + 1);
                world->setAt(x, y + 1, NULL);
            }

            if (world->getAt(x, y - 1) != NULL)
            {
                delete world->getAt(x, y - 1);
                world->setAt(x, y - 1, NULL);
            }

            if (world->getAt(x + 1, y) != NULL)
            {
                delete world->getAt(x + 1, y);
                world->setAt(x + 1, y, NULL);
            }

            return;
        }
    }

    if (world->getAt(x + 1, y) != NULL)
    {
        if (world->getAt(x + 1, y)->getType() == ANT || world->getAt(x + 1, y)->getType() == BUG)
        {
            delete world->getAt(x + 1, y);
            movesTo(x + 1, y);
            return;
        }
        else if (world->getAt(x + 1, y)->getType() == TWINBUG)
        {
            // delete twin bug that we have come into contact with
            delete world->getAt(x + 1, y);
            world->setAt(x + 1, y, NULL);

            // kill current twin bug
            dead = true;

            if (world->getAt(x, y + 1) != NULL)
            {
                delete world->getAt(x, y + 1);
                world->setAt(x, y + 1, NULL);
            }

            if (world->getAt(x, y - 1) != NULL)
            {
                delete world->getAt(x, y - 1);
                world->setAt(x, y - 1, NULL);
            }

            if (world->getAt(x - 1, y) != NULL)
            {
                delete world->getAt(x - 1, y);
                world->setAt(x - 1, y, NULL);
            }

            return;
        }
    }

    Move mover = world->randomMove();

    switch (mover)
    {
    case UP:
        if (world->getAt(x, y + 1) == NULL && in_range(x, y + 1))
        {
            movesTo(x, y + 1);
        }
        break;

    case DOWN:
        if (world->getAt(x, y - 1) == NULL && in_range(x, y - 1))
        {
            movesTo(x, y - 1);
        }
        break;

    case LEFT:
        if (world->getAt(x - 1, y) == NULL && in_range(x - 1, y))
        {
            movesTo(x - 1, y);
        }
        break;

    case RIGHT:
        if (world->getAt(x + 1, y) == NULL && in_range(x + 1, y))
        {
            movesTo(x + 1, y);
        }
        break;

    default:
        break;
    }
}

void TwinBug::generateOffspring(int whereX, int whereY)
{
    // TwinBug does not generate offspring
}

void TwinBug::breed()
{
    // TwinBug does not breed
}

bool TwinBug::isDead() const
{
    if (dead)
    {
        return true;
    }
    else
    {
        return false;
    }
}

OrganismType TwinBug::getType() const
{
    return TWINBUG;
}

char TwinBug::representation() const
{
    return (char)232;
}

int TwinBug::size() const
{
    return 40;
}

bool TwinBug::in_range(int x, int y)
{
    return (x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE);
}
