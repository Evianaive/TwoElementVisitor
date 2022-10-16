#pragma once
#include "TCanVisitBase.h"
#include "TVisitorVirtualFuncCreator.h"


template<template <typename,typename> class TV,typename AcceptVisitorType, typename ReturnType, typename Derived, typename Base>
class TCanVisit : public TCanVisitBase<AcceptVisitorType, ReturnType, Base>
{
public:
	TCanVisit(Derived* HolderDerivedObject) { ((TCanVisitBase<AcceptVisitorType, ReturnType, Base>*)(this))->Holder = HolderDerivedObject; }
	virtual ReturnType Accept(AcceptVisitorType* visitor) override
	{
		return static_cast<TVisitorVirtualFuncCreator<TV,AcceptVisitorType, ReturnType, Base, Derived>*>(visitor)->VisitOther(this);
	}
	virtual ReturnType Accept(TCanVisitBase<AcceptVisitorType, ReturnType, Base>* other) override
	{
		return TV<Derived,AcceptVisitorType>(this).Visit(other);
	}
};