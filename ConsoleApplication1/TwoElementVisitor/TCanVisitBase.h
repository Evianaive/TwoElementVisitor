#pragma once

// template<template <typename,typename> class TV,typename AcceptVisitorType, typename ReturnType, typename Derived, typename Base>
// class TCanVisit;

template<typename AcceptVisitorType, typename ReturnType, typename Base>
class TCanVisitBase
{
public:
    virtual ~TCanVisitBase() = default;
    virtual ReturnType Accept(AcceptVisitorType* visitor) { return ReturnType(); }
    virtual ReturnType Accept(TCanVisitBase<AcceptVisitorType, ReturnType, Base>* other) { return ReturnType(); }
    // protected:
    Base* Holder{ nullptr };
};