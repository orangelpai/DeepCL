# What's done / what's planned

## To do

### Planned, short-term

  * Currently, I'm interested in:
    * the [Atari paper](http://arxiv.org/abs/1312.5602)
    * LTSM, ftp://ftp.idsia.ch/pub/juergen/lstm.pdf , eg as used in the [Google caption](http://arxiv.org/pdf/1411.4555v1.pdf) paper, and as alluded to a lot in [Hinton's AMA](http://www.reddit.com/r/MachineLearning/comments/2lmo0l/ama_geoffrey_hinton/), eg [http://www.reddit.com/r/MachineLearning/comments/2lmo0l/ama_geoffrey_hinton/clyl2dh](http://www.reddit.com/r/MachineLearning/comments/2lmo0l/ama_geoffrey_hinton/clyl2dh)
    * So, anything which furthers being able to pursue either of these is likely to be sooner rather than later
    * Specifically, these need things like:
      * [Q-learning](http://www.dtic.mil/dtic/tr/fulltext/u2/a261434.pdf) (for Atari)
      * probably more generalized network, maybe even more general than a DAG even, for LTSM
  * I'm also running kgs-go dataset in the background, but at 2 days per epoch (32 million records, and 12 layers...), I'm mostly just sitting and waiting :-)
  * Standardize lua wrapper build, generalize to other platforms

### Plausible, medium-term (pull requests welcome)

  * [drop-out](http://arxiv.org/abs/1207.0580) ... pretty important :-)
  * scaling? rotations? mirroring?
  * testing result averaged over several propagations (used in conjunction with `rp`)
  * sparse connectivity between feature maps in adjacent layers
  * ~~skip~~ stride, (skip is described in [Ciresan et al, 2011](http://arxiv.org/pdf/1102.0183v1.pdf) , and stride is a similar, but plausibly more standard concept? )
  * symmetric filters
  * fuse convolutional and max-pooling layers, so can optimize more
  * maybe L2 regularization?
  * generalization to non-square images
  * more general DAGs?

### Maybe sometime, possibly

  * mpi so can run over several gpus, spread across multiple hosts???
    * implemented mpi in `testmnist-mpi`.  If works ok, will generalize to something more permanent => since it didnt seem obvious how to use it, ie you have to divide the learningrate by the number of nodes, I never use this at the moment

### On hold

  * migrate to use `async_work_group_copy`? => on hold, seems it's actually slower, in my experiments, at least on nvidia?
  * [DropConnect](http://cs.nyu.edu/~wanli/dropc/dropc.pdf) => on hold, since, per [Sandle Dieleman's solution to the Galaxy Zoo challenge](http://benanne.github.io/2014/04/05/galaxy-zoo.html), seems like dropconnect is slower and doesnt convincingly add value, compared to dropout

## Deprecated, in next version, 4.x.x

* templates removed; everything is `float` now, no `unsigned char`, or `T`
  * basically, templates work not great with pure virtual inheritance, nor are they very
    supported by scripting languages we might be using to run DeepCL
* removing callbacks from BatchLearner, NetLearner, NetLearnerOnDemand, BatchLearnerOnDemand

## Done

  * forward/backward propagation, for convolutional networks, using OpenCL
  * square loss
  * zero-padding
  * relu activation
  * tanh activation
  * linear activation
  * some optimization of the OpenCL kernels
  * can save/load weights
  * can use 'fluent' style to setup the networks
  * unit-tests for forward propagation
  * numerical validation for backward propagation
  * softmax activation function
  * cross entropy loss
  * multinomial cross entropy loss
  * get working with [kgs go data](https://github.com/hughperkins/kgsgo-dataset-preprocessor)
    * created GenericLoader, which automatically detects filetype
    * created Kgsv2Loader, which handles kgsgo v2 data files
    * added loadondemand, so can load data as we go, during learning, rather than trying to load the entire dataset in one go
  * create a 'transforming input' layer, to handle things like:
    * conversion from `unsigned char *` to `float *`
    * translation and scaling by mean and standard deviation
  * MCDNN
  * randomly translating input layer
  * Python bindings =>  Done (though could be improved of course...)
  * Q-learning Done (though could be improved of course)
  * generalization to larger images => kind of done, ish, for NORB
  * max-pooling
  * read network from a config file => soft of done with the `netdef` syntax
  * write a LuaJIT wrapper since Yann LeCun mentioned LuaJIT in his [AMA](http://www.reddit.com/r/MachineLearning/comments/25lnbt/ama_yann_lecun/) , ie at [http://www.reddit.com/r/MachineLearning/comments/25lnbt/ama_yann_lecun/chiyqzw](http://www.reddit.com/r/MachineLearning/comments/25lnbt/ama_yann_lecun/chiyqzw)
  * write the weights to file more often than once an epoch, so each time my machine goes down, after 1 day and 23 hours, I dont lose 2 days of learning :-P => added writeweightsinterval option

