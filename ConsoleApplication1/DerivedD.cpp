#include "DerivedD.h"
#include "IVisitorOfBase.h"

DerivedD::DerivedD()
{
    CanVisit = new TCanVisitOfDerived<DerivedD>(this);
}
