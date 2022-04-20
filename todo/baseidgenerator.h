#ifndef BASEIDGENERATOR_H
#define BASEIDGENERATOR_H

#include <QString>

class BaseIDGenerator
{
public:
    virtual QString get() = 0;
};

#endif // BASEIDGENERATOR_H
