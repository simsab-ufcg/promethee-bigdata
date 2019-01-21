#pragma once

#include "../../types.h"

/**
 * Abstract structure of a function for PrometheeUmbu
 * */

struct PrometheeUmbuFunction {

    vector<ldouble> params;

    PrometheeUmbuFunction(){}

    PrometheeUmbuFunction(vector<ldouble> params);

    virtual ldouble getPositiveDelta(vector<ldouble> &values, ldouble queryValue, vector<ldouble> &cummulative, ldouble weight, vector<unsigned int> &cnt);

    virtual ldouble getNegativeDelta(vector<ldouble> &values, ldouble queryValue, vector<ldouble> &cummulative, ldouble weight, vector<unsigned int> &cnt);
};