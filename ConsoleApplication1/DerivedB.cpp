#include "DerivedB.h"
#include "IVisitorOfBase.h"

DerivedB::DerivedB()
{
    CanVisit = new TCanVisitOfDerived<DerivedB>(this);
}

template<>
template<>
TVisitorOfBaseRe TVisitorOfBase<DerivedB>::Match(TCanVisitOfDerived<DerivedD>* In)
{
    std::cout << "Custom B to D" << std::endl;
}