#include "DerivedC.h"
#include "IVisitorOfBase.h"

DerivedC::DerivedC()
{
    CanVisit = new TCanVisitOfDerived<DerivedC>(this);
}

template<>
template<>
TVisitorOfBaseRe TVisitorOfBase<DerivedC>::Match(TCanVisitOfDerived<DerivedD>* In)
{
    std::cout << "Very Good C to D" << std::endl;
}