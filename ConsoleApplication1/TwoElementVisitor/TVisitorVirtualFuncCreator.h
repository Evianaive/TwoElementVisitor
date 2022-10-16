#pragma once

template<template <typename,typename> class TV,typename AcceptVisitorType, typename ReturnType, typename Derived, typename Base>
class TCanVisit;

template<template <typename,typename> class TV,typename DerviedVisitor, typename ReturnType, typename TypeToVisit, typename DerivedType>
class TVisitorVirtualFuncCreator
{
protected:
    ~TVisitorVirtualFuncCreator() = default;
public:
    virtual ReturnType VisitOther(TCanVisit<TV,DerviedVisitor,ReturnType,DerivedType,TypeToVisit>*) = 0;
};
