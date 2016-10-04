#ifndef XNOALIAS_HPP
#define XNOALIAS_HPP

#include "xsemantic.hpp"

namespace qs
{

    template <class A>
    class noalias_proxy
    {

    public:

        noalias_proxy(A& a);

        template <class E>
        A& operator=(const xexpression<E>& e);

        template <class E>
        A& operator+=(const xexpression<E>& e);

        template <class E>
        A& operator-=(const xexpression<E>& e);

        template <class E>
        A& operator*=(const xexpression<E>& e);

        template <class E>
        A& operator/=(const xexpression<E>& e);

    private:

        A& m_array;
    };

    template <class A>
    noalias_proxy<A> noalias(A& a);


    /**********************************
     * noalias_proxy implementation
     **********************************/

    template <class A>
    inline noalias_proxy<A>::noalias_proxy(A& a)
        : m_array(a)
    {
    }

    template <class A>
    template <class E>
    inline A& noalias_proxy<A>::operator=(const xexpression<E>& e)
    {
        return m_array.assign(e);
    }

    template <class A>
    template <class E>
    inline A& noalias_proxy<A>::operator+=(const xexpression<E>& e)
    {
        return m_array.plus_assign(e);
    }

    template <class A>
    template <class E>
    inline A& noalias_proxy<A>::operator-=(const xexpression<E>& e)
    {
        return m_array.minus_assign(e);
    }

    template <class A>
    template <class E>
    inline A& noalias_proxy<A>::operator*=(const xexpression<E>& e)
    {
        return m_array.multiplies_assign(e);
    }

    template <class A>
    template <class E>
    inline A& noalias_proxy<A>::operator/=(const xexpression<E>& e)
    {
        return m_array.divides_assign(e);
    }

    template <class A>
    inline noalias_proxy<A> noalias(A& a)
    {
        return noalias_proxy<A>(a);
    }

}

#endif
