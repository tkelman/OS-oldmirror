/* $Id: getIntegerCandidate.cpp 154 2009-06-16 18:52:53Z pbelotti $ */
/*
 * Name:    getIntegerCandidate.cpp
 * Author:  Pietro Belotti
 * Purpose: generate integer NLP point Y starting from fractional 
 *          solution using bound tightening
 *
 * (C) Carnegie-Mellon University, 2007-08.
 * This file is licensed under the Common Public License (CPL)
 */

#include "CoinTime.hpp"
#include "CouenneProblem.hpp"

// lose patience after this many iterations of non-improving valid
// tightening (step 1)
#define VALID_ONLY_THRESHOLD 5 

/// GRASP for finding integer feasible solutions
///
/// Generate integer NLP point xInt starting from fractional solution
/// xFrac, using (feasibility-based, i.e. cheap) bound tightening
///
/// return -1 if the problem is infeasible

int CouenneProblem::getIntegerCandidate (const double *xFrac, double *xInt, 
					 double *lb, double *ub) const {
  fillIntegerRank ();

  if (numberInRank_.size () == 0) // there is no original integer to fix
    return 0;

  CouNumber *store_optimum = optimum_; // temporary place for debug optimal solution
  optimum_ = NULL;

  int
    ncols  = nVars (), 
    retval = 0;

  double
    *olb   = new double [ncols],       *oub   = new double [ncols],      // outer bounds
    *dualL = new double [nOrigVars_],  *dualR = new double [nOrigVars_]; // lb[objind] per fix index/direction

  // copy in current bounds
  CoinCopyN (Lb (), ncols, olb);
  CoinCopyN (Ub (), ncols, oub);

  // for now save fractional point into integer point
  CoinCopyN (xFrac, nOrigVars_, xInt);

  domain_.push (nVars (), xInt, lb, ub);

  CoinCopyN (lb, nVars (), Lb ());
  CoinCopyN (ub, nVars (), Ub ());

  enum fixType *fixed = new enum fixType [nOrigVars_]; // integer variables that were fixed

  for (int i=0; i<nOrigVars_; i++) 
    fixed [i] = (Var (i) -> isInteger () &&        // work on integer variables only
		 Var (i) -> Multiplicity () > 0) ? // don't care if unused variable
      UNFIXED : CONTINUOUS;

  // A more sophisticated rounding procedure
  //
  // Call aggressive tightening for all integer variables, setting
  // each first at floor(x_i) and then at ceil(x_i).
  //
  //
  // for each value r of the rank: 1 .. maxrank {
  //
  //   restrict search of unfixed original variables with rank r to
  //   [floor,ceil] box around LP value
  //
  //   do {
  //
  //     threshold = nVarWithThisRank / k
  //     niter = 0;
  //     for each such (unfixed) variable {
  //
  //       try left
  //       try right
  //
  //       if      both infeasible, abort
  //       else if one infeasible, fix
  //       else if both feasible
  //         if niter < threshold skip
  //         else                 fix based on lb(left<>right)
  //     }
  //
  //     if no variables fixed, fix first unfixed
  //     ++niter
  //
  //   } while there are unfixed variables at this rank
  // }   
  //
  // check value of objective -> set cutoff and run bound tightening
  //

  const int infeasible = 1;

  try {

    // for all values of the integer rank

    int rank = 1;

    if (jnlst_ -> ProduceOutput (Ipopt::J_MOREVECTOR, J_NLPHEURISTIC)) {
      printf ("=       ===========================================\n");
      printf ("= BEGIN ===========================================\n");
      printf ("=       ===========================================\n");
      for (int i=0; i<nOrigVars_; i++)
	if (variables_ [i] -> Multiplicity () > 0)
	  printf ("#### %4d: %d %c %2d frac %20g  [%20g,%20g]\n", 
		  i, fixed [i], 
		  variables_ [i] -> isInteger () ? 'I' : ' ',
		  integerRank_ ? integerRank_ [i] : -1,
		  xFrac [i], Lb (i), Ub (i));
      printf ("---\n");
      for (int i=nOrigVars_; i<nVars (); i++)
	if (variables_ [i] -> Multiplicity () > 0)
	  printf ("#### %4d:   %c    frac %20g   [%20g,%20g]\n", 
		  i, variables_ [i] -> isInteger () ? 'I' : ' ',
		  //(integerRank_ && integerRank_ [i]) ? 'F' : ' ',
		  X (i), Lb (i), Ub (i));
      printf ("===================================================\n");
      printf ("===================================================\n");
      printf ("===================================================\n");
    }


    const int 
      N_VARS_HUGE   = 10000,
      N_VARS_LARGE  = 1000,
      N_VARS_MEDIUM = 100,
      N_VARS_SMALL  = 10,
      N_VARS_TINY   = 5;

    int 
      ntrials   = 0, 
      nvars = nVars (),
      maxtrials =
      (nvars >= N_VARS_HUGE)   ? 0 :
      (nvars >= N_VARS_LARGE)  ? 1 :
      (nvars >= N_VARS_MEDIUM) ? 2 :
      (nvars >= N_VARS_SMALL)  ? 4 :
      (nvars >= N_VARS_TINY)   ? 8 : 16;

    for (std::vector <int>::iterator rNum = numberInRank_.begin(); 
	 ++rNum != numberInRank_.end(); rank++) 

      if (*rNum > 0) {

	if (CoinCpuTime () > maxCpuTime_)
	  break;

	// *rNum is the number of variable with integer rank equal to rank

	// start restricting around current integer box
	for (int i=0; i<nOrigVars_; i++) 
	  if ((Var (i) -> Multiplicity () > 0) && // alive variable
	      (Var (i) -> isInteger    ())     && // integer, may fix if independent of other integers
	      (integerRank_ [i] == rank)) {

	    Lb (i) = CoinMax (Lb (i), floor (xFrac [i])); 
	    Ub (i) = CoinMin (Ub (i), ceil  (xFrac [i]));
	  }

	// translate current NLP point+bounds into higher-dimensional space
	initAuxs ();

	if (jnlst_ -> ProduceOutput (Ipopt::J_MOREVECTOR, J_NLPHEURISTIC)) {
	  printf ("= RANK LEVEL = %d [%d] ==================================\n", rank, *rNum);
	  for (int i=0; i<nOrigVars_; i++)
	    if (Var (i) -> Multiplicity () > 0) // alive variable
	      printf ("#### %4d: %d %c %2d frac %20g -> int %20g [%20g,%20g]\n", 
		      i, fixed [i], 
		      variables_ [i] -> isInteger () ? 'I' : ' ',
		      integerRank_ ? integerRank_ [i] : -1,
		      xFrac [i], xInt [i], Lb (i), Ub (i));
	  printf ("--------------------\n");
	  for (int i=nOrigVars_; i<nVars (); i++)
	    if (Var (i) -> Multiplicity () > 0) // alive variable
	      printf ("#### %4d:   %c    frac %20g   [%20g,%20g]\n", 
		      i, variables_ [i] -> isInteger () ? 'I' : ' ',
		      //(integerRank_ && integerRank_ [i]) ? 'F' : ' ',
		      X (i), Lb (i), Ub (i));
	  printf ("=================================================\n");
	}

	//CoinCopyN (xFrac, nOrigVars_, xInt);// TODO: re-copy first nOrigVars_ variables into xInt?

	int remaining = *rNum;

	do {

	  bool one_fixed = false;

	  for (int i=0; i<nOrigVars_; i++) 

	    if ((Var (i) -> Multiplicity () > 0) && // alive 
		(integerRank_ [i] == rank)       && // at this rank
		(fixed [i] == UNFIXED)           && // still to be fixed
		Var (i) -> isInteger ()) {          // and integer

	      if (CoinCpuTime () > maxCpuTime_)
		break;

	      // check if initAuxs() closed any bound; if so, fix variable
	      //if (Lb (i) == Ub (i)) { // doesn't work
	      if (ceil (Lb (i) - COUENNE_EPS) + COUENNE_EPS >= floor (Ub (i) + COUENNE_EPS)) {

		X (i) = xInt [i] = ceil (Lb (i) - COUENNE_EPS);
		fixed [i] = FIXED;
		one_fixed = true;
		--remaining;
		continue;
	      }

	      // otherwise, test rounding up and down
	      int result = testIntFix (i, xFrac [i], fixed, xInt,
				       dualL, dualR, olb, oub, ntrials < maxtrials);

	      jnlst_ -> Printf (J_MOREVECTOR, J_NLPHEURISTIC, 
				"testing %d [%g -> %g], res = %d\n", i, xFrac [i], xInt [i], result);

	      if (result > 0) {
		one_fixed = true;
		--remaining;
	      } else if (result < 0) 
		throw infeasible;
	    }

	  // if none fixed, fix first unfixed variable with this rank

	  if (!one_fixed) {

	    int index = 0;

	    // find first unfixed integer at this rank
	    while ((index < nOrigVars_) && 
		   (!(Var (index) -> isInteger ()) ||
		    (integerRank_ [index] != rank) ||
		    (fixed [index] != UNFIXED)))
	      index++;

	    assert (index < nOrigVars_);

	    jnlst_ -> Printf (J_MOREVECTOR, J_NLPHEURISTIC, 
			      "none fixed, fix %d from %g [%g,%g] [L=%g, R=%g]", 
			      index, xFrac [index], Lb (index), Ub (index), 
			      dualL [index], dualR [index]);

	    Lb (index) = Ub (index) = X (index) = xInt [index] = 
	      ((dualL [index] < dualR [index] - COUENNE_EPS) ? floor (xFrac [index]) :
	       (dualL [index] > dualR [index] + COUENNE_EPS) ? ceil  (xFrac [index]) :
	       ((CoinDrand48 () > xFrac [index] - floor (xFrac [index])) ? 
		floor (xFrac [index]) : ceil (xFrac [index])));

	    jnlst_ -> Printf (J_MOREVECTOR, J_NLPHEURISTIC, " to %g\n", xInt [index]);

	    fixed [index] = FIXED;

	    --remaining;
	  }

	  ntrials++;

	  if (jnlst_ -> ProduceOutput (Ipopt::J_MOREVECTOR, J_NLPHEURISTIC)) {
	    printf ("--- remaining = %d --------------------------- \n", remaining);
	    for (int i=0; i<nOrigVars_; i++)
	      if (variables_ [i] -> Multiplicity () > 0)
		printf ("#### %4d: %d %c %2d frac %20g -> int %20g  [%20g,%20g]\n", 
			i, fixed [i], 
			variables_ [i] -> isInteger () ? 'I' : ' ',
			integerRank_ ? integerRank_ [i] : -1,
			xFrac [i], xInt [i], Lb (i), Ub (i));
	    printf ("---------------------------\n");

	  }
	} while (remaining > 0);
      } // for

    // save tightened bounds in NLP space. Sanity check
    for (int i = nOrigVars_; i--;)
      if (Var (i) -> Multiplicity () > 0) {

	if (fixed [i] == FIXED)       // integer point, fixed
	  lb [i] = ub [i] = X (i) = xInt [i];

	else if (Lb (i) > Ub (i))     // non-sense bounds, fix them
	  xInt [i] = X (i) = lb [i] = ub [i] = 
	    (fixed [i] == CONTINUOUS) ?
	                  (0.5 * (Lb (i) + Ub (i))) :
	    COUENNE_round (0.5 * (Lb (i) + Ub (i)));

	else {                        // normal case
	  lb [i] = Lb (i);
	  ub [i] = Ub (i);
	  if      (xInt [i] < lb [i]) X (i) = xInt [i] = lb [i];
	  else if (xInt [i] > ub [i]) X (i) = xInt [i] = ub [i];
	}
      }

    restoreUnusedOriginals (xInt);

    // if initial point is feasible, compute corresponding objective
    // and update if upper bound improves
    initAuxs ();
    int objind = Obj (0) -> Body () -> Index ();

    if (X (objind) < getCutOff ()) {

      const CouNumber *x = X ();
      CouNumber xp = x [objind];

      if (checkNLP (x, xp, true)) { // true for recomputing xp
	setCutOff (xp);
	jnlst_ -> Printf (J_DETAILED, J_NLPHEURISTIC, 
			  "new cutoff from getIntCand: %g\n", xp);
      }
    }
  } // try

  catch (int i) {

    if (i == infeasible)
      retval = -1;
  }

  ////////////////////////////////////////////////////////////////////////////////

  if (jnlst_->ProduceOutput(Ipopt::J_MOREVECTOR, J_NLPHEURISTIC)) {
    if (retval >= 0) {
      printf ("- Done: retval %d ----------------------------------------------------------------\n", 
	      retval);
      for (int i=0; i<nOrigVars_; i++)
	if (variables_ [i] -> Multiplicity () > 0)
	  printf ("#### %4d: %d %c frac %20g -> int %20g [%20g,%20g]\n", 
		  i, fixed [i], variables_ [i] -> isInteger () ? 'I' : ' ',
		  xFrac [i], xInt [i], lb [i], ub [i]);
    } else printf ("no good point was found\n");
  }

  delete [] fixed;

  delete [] olb;   delete [] oub;
  delete [] dualL; delete [] dualR;

  domain_.pop ();

  jnlst_ -> Printf (J_MOREVECTOR, J_NLPHEURISTIC, "Done with GetIntegerCandidate\n");

  optimum_ = store_optimum; // restore 

  return retval;
}
