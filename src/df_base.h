/** \file    df_base.h
    \brief   Base class for action-based distribution functions
    \date    201?-2015
    \authors Payel Das, Eugene Vasiliev
*/
#pragma once
#include "actions_base.h"

/** Classes for dealing with action-base distribution functions */
namespace df{

/** Base class defining the action-based distribution function (DF) */
class BaseDistributionFunction{
public:
    BaseDistributionFunction() {};
    virtual ~BaseDistributionFunction() {};

    /** Compute the total mass, i.e., integral of DF over the entire phase space.
        The actions range between 0 and +inf for Jr and Jz, and between -inf and +inf for Jphi,
        and there is an additional factor (2*pi)^3 from the integration over angles
        (we assume that DF does not depend on angles, but we still need to integrate
        over the entire 6d phase space).
        Derived classes may return an analytically computed value if available,
        and the default implementation performs multidimension integration numerically.
        \param[in]  reqRelError - relative tolerance;
        \param[in]  maxNumEval - maximum number of evaluations of DF during integration;
        \param[out] error (optional) if not NULL, store the estimate of the error;
        \param[out] numEval (optional) if not NULL, store the actual number of DF evaluations.
        \returns    total mass
    */
    virtual double totalMass(const double reqRelError, const int maxNumEval,
        double* error=0, int* numEval=0) const;

    /** Value of distribution function for the given set of actions
        \param[in] J - actions
    */
    virtual double value(const actions::Actions &J) const=0;

    /** Maximum possible value of DF */
    virtual double maxValue() const=0;
};

}  // namespace distributionfunction

