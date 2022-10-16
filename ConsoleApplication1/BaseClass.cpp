#include "BaseClass.h"
// #include "IVisitorOfBase.h"
#include "TwoElementVisitor/TCanVisitBase.h"

void BaseClass::Accept(const BaseClass* Other)
{
    this->CanVisit->Accept(Other->CanVisit);
}
