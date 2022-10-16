#pragma once

template<typename... Args>
class TArgsTuple;

template<>
class TArgsTuple<>
{
public:
    static constexpr int Value = 0;
    static constexpr int value = 0;

    template<int Index>
    struct TypeOfIndex
    {
        using Type = void;
    };
    template<int Index>
    using Element = typename TypeOfIndex<Index>::Type;
};

template<typename CurrentType, typename... Args>
class TArgsTuple<CurrentType, Args...>
{
public:
    static constexpr int Value = sizeof...(Args) + 1;
    static constexpr int value = sizeof...(Args) + 1;

    template<int Index>
    struct TypeOfIndex
    {
        // static_assert(Index < Value, "Out of Index");
        using Type = typename TArgsTuple<Args...>::template TypeOfIndex<Index - 1>::Type;
    };
    template<>
    struct TypeOfIndex<0>
    {
        using Type = CurrentType;
    };
    template<int Index>
    using Element = typename TypeOfIndex<Index>::Type;
};