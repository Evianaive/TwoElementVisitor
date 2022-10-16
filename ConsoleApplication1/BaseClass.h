#pragma once
#include "TwoElementVisitor/TCanVisitBase.h"

class BaseClass
{
public:
    void Accept(const BaseClass* Other);
protected:
    TCanVisitBase<class IVisitorOfBase,void,BaseClass>* CanVisit{ nullptr };
};

