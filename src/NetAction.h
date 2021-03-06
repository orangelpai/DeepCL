// Copyright Hugh Perkins 2015 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include "DeepCLDllExport.h"

class Trainable;

#define VIRTUAL virtual
#define STATIC static

class DeepCL_EXPORT EpochResult {
public:
    float loss;
    int numRight;
    EpochResult( float loss, int numRight ) :
        loss( loss ),
        numRight( numRight ) {
    }
};

class DeepCL_EXPORT NetAction {
public:
    virtual ~NetAction() {}
    virtual void run( Trainable *net, float const*const batchData, int const*const batchLabels ) = 0;
};


class DeepCL_EXPORT NetLearnLabeledAction : public NetAction {
public:
    float learningRate;
    float getLearningRate() {
        return learningRate;
    }
    NetLearnLabeledAction( float learningRate ) :
        learningRate( learningRate ) {
    }   
    virtual void run( Trainable *net, float const*const batchData, int const*const batchLabels );
};


class DeepCL_EXPORT NetPropagateAction : public NetAction {
public:
    NetPropagateAction() {
    }
    virtual void run( Trainable *net, float const*const batchData, int const*const batchLabels );
};


class DeepCL_EXPORT NetBackpropAction : public NetAction {
public:
    float learningRate;
    float getLearningRate() {
        return learningRate;
    }
    NetBackpropAction( float learningRate ) :
        learningRate( learningRate ) {
    }
    virtual void run( Trainable *net, float const*const batchData, int const*const batchLabels );
};


