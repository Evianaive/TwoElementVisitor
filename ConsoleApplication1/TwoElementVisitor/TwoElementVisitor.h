#pragma once
// #include "TCanVisitBase.h"
// #include "TArgsTuple.h"
#include "TVisitorVirtualFuncCreator.h"

template<typename... Args>
class TArgsTuple;

template<typename AcceptVisitorType, typename ReturnType, typename Base>
class TCanVisitBase;

template<template <typename,typename> class TV,typename DerviedVisitor, typename TypeToReturn, class TypeToVisit, typename... DerivedType>
class TTwoElemVisitor
	: public TVisitorVirtualFuncCreator<TV,DerviedVisitor, TypeToReturn, TypeToVisit, DerivedType>...
{
	protected:
	/*using TemplateArgsCache = TArgsTuple<DerviedVisitor, ReturnType, TypeToVisit, DerivedType...>;*/
	using ReturnType = TypeToReturn;
	using BaseType = TypeToVisit;
	using DerivedArgsCache = TArgsTuple<DerivedType...>;
	~TTwoElemVisitor() = default;

	public:
	virtual TypeToReturn Visit(TCanVisitBase<DerviedVisitor,TypeToReturn,TypeToVisit>*) = 0;
};