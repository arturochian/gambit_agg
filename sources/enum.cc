//
// FILE: enum.cc -- Nash Enum module
//
// $Id$
// 

#include "enum.imp"

//---------------------------------------------------------------------------
//                        EnumParams: member functions
//---------------------------------------------------------------------------

EnumParams::EnumParams(gStatus &s)
  : AlgParams(s), cliques(false)
{ }

int Enum(const NFSupport &support, const EnumParams &params,
	 gList<MixedSolution> &solutions, long &npivots, double &time)
{
  if (params.precision == precDOUBLE)  {
    EnumModule<double> module(support, params);
    module.Enum();
//    module.DoubleEnum();
    npivots = module.NumPivots();
    time = module.Time();
    solutions = module.GetSolutions();
    if(params.cliques) module.GetCliques();
  }
  else if (params.precision == precRATIONAL)  {
    EnumModule<gRational> module(support, params);
    module.Enum();
//    module.DoubleEnum();
    npivots = module.NumPivots();
    time = module.Time();
    solutions = module.GetSolutions();
    if(params.cliques) module.GetCliques();
  }
  return 1;
}

#include "rational.h"

template class EnumModule<double>;
template class EnumModule<gRational>;











