# Allpix² Monte Carlo Simulations for Pixel Detectors

This repository contains the configuration and setup files for performing Monte Carlo simulations of silicon pixel detectors using the **Allpix² framework**. These simulations were conducted to characterize detector performance, specifically focusing on spatial resolution and charge collection efficiency.

## Simulation Overview

The project simulates the passage of high-energy particles (5 GeV electrons) through a silicon pixel sensor, modeling the entire physical process from initial energy deposition to digitized electronic signals.

### Core Configuration Files

* **`detector.conf`**: Defines the experimental geometry, specifying the sensor type (`cmsp1`), its physical position, and its orientation in 3D space.
* **`start.conf`**: The primary simulation steering file. It configures the Geant4 physics list, the particle beam parameters (energy, divergence, position), and the internal electric field (linear model) of the sensor.
* **`visual.conf`**: A dedicated configuration for the Geant4-based graphical user interface (GUI). It allows for the visual inspection of the detector geometry and particle trajectories.
* **`replay.conf`**: Used for fast-reprocessing of previously simulated data. It allows for the adjustment of digitization parameters (electronics noise, thresholds, QDC resolution) without re-running the computationally expensive Geant4 deposition stage.

## The Simulation Chain

The configuration files implement a multi-stage simulation pipeline:

1. **Deposition (`DepositionGeant4`)**: Simulates the interaction of 5 GeV electrons with the silicon material, creating electron-hole pairs.
2. **Propagation (`GenericPropagation`)**: Models the drift and diffusion of charge carriers through the sensor under the influence of the applied bias voltage (-150V).
3. **Transfer (`SimpleTransfer`)**: Maps the propagated charges to the individual pixel implants.
4. **Digitization (`DefaultDigitizer`)**: Converts the collected charge into digital signals, accounting for electronics noise, threshold effects, and QDC (Analog-to-Digital) conversion.
5. **Analysis (`DetectorHistogrammer`)**: Automatically generates performance histograms, including cluster sizes and in-pixel hit maps.

## How to Run

To run the full simulation, ensure Allpix² is installed and sourced in your environment, then execute:

```bash
allpix -c start.conf

```

To visualize the setup:

```bash
allpix -c visual.conf

```

## Key Results Analyzed

Using these configurations, the project explored:

* **Spatial Resolution**: How the physical pixel size and charge sharing affect tracking precision.
* **Angular Dependence**: The effect of sensor rotation on cluster size and resolution.
* **Lorentz Drift**: The impact of a magnetic field on the charge carrier trajectory (configured via `MagneticFieldReader`).

* [Allpix² Website](https://project-allpix-squared.web.cern.ch/)
* [Allpix² User Manual](https://project-allpix-squared.web.cern.ch/project-allpix-squared/usermanual/allpix-manual.pdf)
