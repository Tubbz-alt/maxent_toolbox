// Main functions for maximum entropy toolbox.
// The platform-specific parts are abstracted from these functions so that they can work in more than one environment.
// Ori Maoz, August 2016

#include "EnergyFunction.h"

void getLogProbability(EnergyFunction * energy, uint32_t npatterns, uint32_t * patterns_in, double * logprobs_out, bool bNormalize = true);


// Performs a Metropolis-Hasting type MCMC random walk on the state space and returns samples.
// For an n-bit word, n bit flips are performed between each returned sample. This can be scaled up with the "nSeparation" argument.
// The bits are flipped in a sequential order unless specified otherwise by the global bSequentialBits argument.
//
// Input:
//		pModel (in)			- model to generate the samples from
//		nsteps (in)			- number of samples to generate
//		x0 (in/out)			- accepts initial state and returns the final state of the random walk.
//		pOutputSamples (out)- pointer to preallocated array that will contain the output samples, or NULL if we don't want to return samples (for burn-in)
//		nSeparation (in)	- how many samples between every returned sample. Is used to generate less-correlated data.
//		bSequentialBits (in)- true if we want bits to be flipped in a sequential order, false for random order
//
// Returns:  
//		The energy (un-normalized log probability) of the new state.
void runGibbsSampler(EnergyFunction * pModel, uint32_t nsteps, uint32_t * x0, unsigned char * pOutputSamples, uint32_t nSeparation, bool bSequentialBits);


// Returns the marginals of a model (exhaustively computed)
// Input:
//		pModel (in)			- model to generate the samples from
//		pMarginals (out		- preallocated buffer in which the marginals are returned
void getMarginals(EnergyFunction * pModel, double * pMarginals);