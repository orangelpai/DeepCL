// Copyright Hugh Perkins 2014 hughperkins at gmail
//
// This Source Code Form is subject to the terms of the Mozilla Public License, 
// v. 2.0. If a copy of the MPL was not distributed with this file, You can 
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <cstring>
#include <iostream>

#include "DeepCLDllExport.h"
#include "LayerMaker.h"

class DeepCL_EXPORT InputLayerMaker : public LayerMaker2 {
public:
    int _numPlanes;
    int _imageSize;
    InputLayerMaker() :
//            LayerMaker( net, 0 ),
            _numPlanes(0),
            _imageSize(0) {
    }
    InputLayerMaker *numPlanes( int _numPlanes ) {
        this->_numPlanes = _numPlanes;
        return this;
    }    
    InputLayerMaker *imageSize( int _imageSize ) {
        this->_imageSize = _imageSize;
        return this;
    }    
    static InputLayerMaker *instance() {
        return new InputLayerMaker();
    }    
    virtual InputLayerMaker *clone() const {
        InputLayerMaker *thisClone = new InputLayerMaker();
        memcpy( thisClone, this, sizeof( InputLayerMaker ) );
        return thisClone;
    }
    virtual Layer *createLayer( Layer *previousLayer );
};

