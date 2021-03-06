# OpenMS-playground

🎢 Playing with OpenMS functionalities

## Intro

This repo is created in preparation for the upcoming Google Summer of Code (GSoC) 2022.

## Goal

`OpenMS` is a framework for computational mass spectrometry. Modern mass spectrometers produce large files (e.g., 100 GB) that can’t be easily stored or accessed in the established `XML` file format `mzML`. Recently, an update to `mzML` has been developed that uses `HDF5` to store `Blosc` compressed spectra in binary format: called `mzMLb`.
In this project, the student will add a reader and writer for the `mzMLb` file format to `OpenMS`. To some extent, code from the `OpenMS` reader and writer for the `mzML` file format can be reused, as well as inspiration can be taken from reference implementations by other parties.

## mzML format and mzMLb format reference

### mzML file schema

![mzML schema](img/20220416170157.png)

### mzMLb internal data structure

![mzMLb internal data structure](img/20220416170245.png)

## HDF5 + blosc

There's a well-wrapped [HDF5 plugin](https://github.com/Blosc/hdf5-blosc) for
HDF5 provided by the BLOSC team. It currently utilizes [BLOSC](https://github.com/Blosc/c-blosc).

We can install the provided plugin globally by copy the built dynamic lib to
`/path/to/hdf5/plugins` (e.g. `/usr/local/hdf5/lib/plugins` as in the documentation
 or `/usr/lib/x86_64-linux-gnu/hdf5/plugins` as on **Ubuntu 20.04 LTS**)

It's also possible to register the filter ad hoc using `register_blosc()` provided
in `blosc_filter.h`.

## Misc

While running `ctest`, some of the tests will always fail even if we build on the latest develop branch:

```diff
99% tests passed, 12 tests failed out of 2505

Total Test time (real) =  86.46 sec

The following tests FAILED are listed below. Note that the tests marked by `!` only fail on machines without GUI.

```diff
-        495 - PrecursorIonSelectionPreprocessing_test (Failed)
-        575 - DetectabilitySimulation_test (Failed)
-        615 - MRMFeatureSelector_test (Failed)
!        643 - TOPPView_test (Child aborted)
!        644 - TSGDialog_test (Child aborted)
-        2283 - TOPP_OpenPepXL_1_out_2 (Failed)
-        2288 - TOPP_OpenPepXLLF_1_out_2 (Failed)
!        2373 - UTILS_INIUpdater_1 (Child aborted)
!        2374 - UTILS_INIUpdater_1_out (Failed)
!        2376 - UTILS_INIUpdater_3 (Child aborted)
!        2377 - UTILS_INIUpdater_3_out (Failed)
!        2472 - TOPP_ExecutePipeline_1 (Child aborted)
```

## Reference

1. [Mass Spectrometer Output File Format mzML](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3073315/)
2. [mzMLb: A Future-Proof Raw Mass Spectrometry Data Format Based on Standards-Compliant mzML and Optimized for Speed and Storage Requirements](https://pubs.acs.org/doi/10.1021/acs.jproteome.0c00192)
