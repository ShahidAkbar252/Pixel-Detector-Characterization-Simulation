# ALiBaVa: Silicon Strip Sensor Calibration & Landau Distribution

This project focuses on the characterization of a silicon strip sensor using the **ALiBaVa (A Little Box of Variable Applications)** readout system. The primary goal was to measure the energy loss of charged particles in silicon and verify the theoretical **Landau distribution**.

## Experiment Overview

Using a ^{90}\text{Sr} radioactive source, we analyzed the response of a silicon strip sensor. The analysis pipeline involved processing raw ADC (Analog-to-Digital Converter) counts to extract physical properties like noise levels, gain linearity, and the most probable energy loss (MPV).

### Data Files in this Repository

* **`Pedestals.txt`**: Contains the baseline (pedestal) and RMS noise values for each channel of the readout chips.
* **`Charge.txt`**: Data from the calibration run used to determine the linearity and gain of the system by injecting known charges.
* **`RS_C.txt`**: The reconstructed signal data from the radioactive source run, including seed pixel information and common mode corrections.

## Key Analysis Stages

### 1. Pedestal and Noise Analysis

* Calculated the **pedestal** (baseline offset) and **noise** (RMS) for 256 channels.
* Distinguished between bonded and unbonded strips to visualize the impact of sensor capacitance on noise levels.
* *Result:* Observed a mean pedestal of 517.8 \pm 11.2 ADC with typical noise levels around 9 ADC.

### 2. Charge Calibration

* Performed a linear fit of injected charge vs. measured ADC value.
* Determined the **gain** of the system to convert raw digital values into electrons (e^-).
* *Result:* Demonstrated a highly linear response with a slope of 0.0026 \pm 0.0002 ADC/e^-.

### 3. Landau Distribution & Sensor Thickness

* Processed the radioactive source data (`RS_C.txt`) using the determined calibration constants.
* Applied **Common Mode Correction** and identified **Seed Pixels** to reconstruct the clusters.
* Fitted the resulting charge spectrum with a **Landau distribution**.
* *Result:* Extracted the **Most Probable Value (MPV)** to estimate the active thickness of the silicon sensor.

## Skills & Tools

* **Data Processing:** Python (NumPy, Pandas), HDF5 data handling.
* **Physics Modeling:** Landau-Vavilov theory, Bethe-Bloch equation.
* **Statistics:** Linear regression, Chi-square minimization, and distribution fitting.
