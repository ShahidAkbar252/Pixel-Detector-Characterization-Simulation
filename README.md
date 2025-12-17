# Silicon Pixel Detector Characterization: From Simulation to Test-Beam Analysis

This repository documents my work and findings from the **"Measurements with a Pixel Telescope"** intensive course held at the **University of Bonn** (BCGS Intensive Week, September 2025).

The project covers the full lifecycle of experimental detector physics: calibrating hardware, simulating particle interactions, and reconstructing real-world test-beam data.

## Project Overview

The curriculum was divided into three core technical pillars, each focusing on a different aspect of semiconductor detector R&D:

### 1. ALiBaVa: Hardware Calibration & Physics Validation

* **Focus:** Raw data processing and sensor physics.
* **Objective:** Calibrated a silicon strip sensor using a ^{90}\text{Sr} source.
* **Key Tasks:** Pedestal/noise analysis and fitting a Landau distribution to determine sensor thickness.
* **Tech:** Python, HDF5, NumPy, Matplotlib.

### 2. Allpix²: Monte Carlo Simulations

* **Focus:** Computational modeling and predictive analysis.
* **Objective:** Simulated the response of a CMS Phase-1 pixel sensor to 5 GeV electron beams.
* **Key Tasks:** Investigated how spatial resolution is affected by digitization, sensor rotation (theta/phi), and Lorentz drift in magnetic fields.
* **Tech:** Allpix² framework, Geant4, C++.

### 3. Corryvreckan: Test-Beam Reconstruction

* **Focus:** Data analysis of complex detector systems.
* **Objective:** Reconstructed particle tracks through a 7-plane Timepix3 telescope to characterize an ATLASpix DUT (Device Under Test).
* **Key Tasks:** Geometry alignment, track fitting, and calculation of hit detection efficiency and spatial residuals.
* **Tech:** Corryvreckan framework, ROOT (C++).

---

## Technical Stack

* **Languages:** C++, Python, Bash.
* **Frameworks:** [ROOT](https://root.cern.ch/), [Allpix²](https://project-allpix-squared.web.cern.ch/), [Corryvreckan](https://gitlab.cern.ch/corryvreckan/corryvreckan).
* **Concepts:** Monte Carlo methods, Semiconductor Physics, Signal Processing, Tracking Algorithms, Statistical Data Analysis.

## Repository Structure

```text
.
├── Alibava/       # Python scripts & data for strip sensor calibration
├── Allpix/        # Simulation config files (deposition, propagation, digitization)
├── Corryvreckan/  # ROOT macros for tracking and residual analysis
└── Report/        # Final summary of results and physical interpretations

```

## Acknowledgments

This work was supervised by researchers from **DESY (Deutsches Elektronen-Synchrotron)** and the **University of Bonn**. Special thanks to Dr. Ingrid-Maria Gregor and Mr. Simon Spannagel for providing the frameworks and experimental data.

---

### How to use this repository

1. Navigate to the individual subdirectories for specific instructions on how to run the simulations or analysis scripts.
2. Refer to `Report_Measurement with Pixel Telescope_Git.pdf` for a detailed scientific discussion of the results.
