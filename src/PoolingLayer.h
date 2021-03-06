// Copyright Hugh Perkins 2014 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "Layer.h"

#define VIRTUAL virtual
#define STATIC static

class CLKernel;
class CLWrapper;
class PoolingPropagate;
class PoolingBackprop;

class PoolingMaker;

class PoolingLayer : public Layer {
public:
    const bool padZeros;
    const int numPlanes;
    const int inputImageSize;
    const int poolingSize;

    const int outputImageSize;

    OpenCLHelper *const cl; // NOT owned by us
    PoolingPropagate *poolingPropagateImpl;
    PoolingBackprop *poolingBackpropImpl;

    float *results;
    int *selectors;
    float *errorsForUpstream;

    CLWrapper *resultsWrapper;
    CLWrapper *selectorsWrapper;
    CLWrapper *errorsForUpstreamWrapper;

    bool resultsCopiedToHost;
    bool errorsForUpstreamCopiedToHost;

    int batchSize;
    int allocatedSize;

    // [[[cog
    // import cog_addheaders
    // cog_addheaders.add()
    // ]]]
    // generated, using cog:
    PoolingLayer( OpenCLHelper *cl, Layer *previousLayer, PoolingMaker *maker );
    VIRTUAL ~PoolingLayer();
    VIRTUAL std::string getClassName() const;
    VIRTUAL void setBatchSize( int batchSize );
    VIRTUAL int getResultsSize();
    VIRTUAL float *getResults();
    VIRTUAL bool needsBackProp();
    VIRTUAL int getResultsSize() const;
    VIRTUAL int getOutputImageSize() const;
    VIRTUAL int getOutputPlanes() const;
    VIRTUAL int getPersistSize() const;
    VIRTUAL bool providesErrorsForUpstreamWrapper() const;
    VIRTUAL CLWrapper *getErrorsForUpstreamWrapper();
    VIRTUAL bool hasResultsWrapper() const;
    VIRTUAL CLWrapper *getResultsWrapper();
    VIRTUAL float *getErrorsForUpstream();
    VIRTUAL ActivationFunction const *getActivationFunction();
    VIRTUAL void propagate();
    VIRTUAL void backProp( float learningRate );
    VIRTUAL std::string asString() const;

    // [[[end]]]
};

