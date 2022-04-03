# OpenMS-playground
🎢 Playing with OpenMS functionalities

## Intro

This repo is created in preparation for the upcoming Google Summer of Code (GSoC) 2022.

## Goal

`OpenMS` is a framework for computational mass spectrometry. Modern mass spectrometers produce large files (e.g., 100 GB) that can’t be easily stored or accessed in the established `XML` file format `mzML`. Recently, an update to `mzML` has been developed that uses `HDF5` to store `Blosc` compressed spectra in binary format: called `mzMLb`.
In this project, the student will add a reader and writer for the `mzMLb` file format to `OpenMS`. To some extent, code from the `OpenMS` reader and writer for the `mzML` file format can be reused, as well as inspiration can be taken from reference implementations by other parties.

## Resources

1. [Mass Spectrometer Output File Format mzML](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC3073315/)
2. [mzMLb: A Future-Proof Raw Mass Spectrometry Data Format Based on Standards-Compliant mzML and Optimized for Speed and Storage Requirements](https://pubs.acs.org/doi/10.1021/acs.jproteome.0c00192)