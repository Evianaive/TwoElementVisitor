#pragma once
#include <iostream>

#include "TwoElementVisitor/TArgsTuple.h"
#include "TwoElementVisitor/MacroRepeat.h"
#include "TwoElementVisitor/TwoElementVisitor.h"
#include "BaseClass.h"
#include "DerivedB.h"
#include "DerivedC.h"
#include "DerivedD.h"

template<template <typename,typename> class TV,typename AcceptVisitorType, typename ReturnType, typename Derived, typename Base>
class TCanVisit;

#define LOCAL_VIRTUALFUNCTIONIMPL(INDEX)\
virtual ReturnType VisitOther(TCanVisit<TVisitorOfBase,AcceptVisitorType, ReturnType, typename DerivedArgsCache::template TypeOfIndex<INDEX>::Type,BaseType>* Out) override{return Match(Out);}

class IVisitorOfBase;

template<typename Derived,typename AcceptVisitorType = IVisitorOfBase>
class TVisitorOfBase final : public AcceptVisitorType
{
public:
    using BaseType = typename AcceptVisitorType::BaseType;
    using ReturnType = typename AcceptVisitorType::ReturnType;
    using DerivedArgsCache = typename AcceptVisitorType::DerivedArgsCache;
    explicit TVisitorOfBase(TCanVisit<TVisitorOfBase,AcceptVisitorType,ReturnType,Derived,BaseType>* CacheIn)
        : CacheIn(CacheIn)
    {}

    template<class T2>
    static ReturnType Match(TCanVisit<TVisitorOfBase, AcceptVisitorType, ReturnType, T2, BaseType>* Out)
    {
        std::cout<<typeid(CacheIn).name()<<" To "<<typeid(T2).name()<<std::endl;
    }
    
    virtual ReturnType Visit(TCanVisitBase<AcceptVisitorType,ReturnType,BaseType>* Out) override
    {
        return Out->Accept(this);
    }
    //此处与具体子类数量相关
    PP_REPEAT_3(LOCAL_VIRTUALFUNCTIONIMPL)
    // PP_REPEAT_3(LOCAL_STATICFUNCTIONIMPL)

    virtual ~TVisitorOfBase() override{}
private:
    TCanVisit<TVisitorOfBase,AcceptVisitorType,ReturnType,Derived,BaseType>* CacheIn;
};

// 此处需要继承一层以保证BaseClass头文件稳定，因为TCanVisitBase需要获取IVisitor，多一层间接性使得实际的头文件中只需要使用前置声明即可
class IVisitorOfBase :
public TTwoElemVisitor
<TVisitorOfBase,IVisitorOfBase,void,
    class BaseClass,
    class DerivedB,
    class DerivedC,
    class DerivedD
>
{
public:
    using ReturnType = ReturnType;
    using BaseType = BaseType;
    virtual ~IVisitorOfBase() = default;
};
// 若使用using则IVisitor,将导致BaseClass需要Include此文件，则随子类增长头文件会变动
//using IVisitor = TTwoElemVisitor<void, class UAA, class UBB, class UCC>;

using TVisitorOfBaseRe = TVisitorOfBase<DerivedC,IVisitorOfBase>::ReturnType;
template<typename Derived>
using TCanVisitOfDerived = TCanVisit<TVisitorOfBase, IVisitorOfBase, IVisitorOfBase::ReturnType, Derived, IVisitorOfBase::BaseType>;


#undef LOCAL_VIRTUALFUNCTIONIMPL
#undef LOCAL_STATICFUNCTIONIMPL

#include "TwoElementVisitor/TCanVisit.h"

