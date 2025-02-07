# Basic Saturator (Harmonic Distortion) Plugin
By Edmund Paquin

Created in C++ with the JUCE plugin framework.

Working vst3 for mac is in this directory. It is called BasicSaturator.vst3. 

Some demo screenshots are in the demo_images directory. 

Saturation method uses tanh(sample_value * scalar) to overwrite each consecutive sample. This works well because tanh(x) is approximately linear for small values. This means the saturator introduces very little harmonic distortion for scalar values close to 1, and thus the output value is approximately equal to whatever the incoming sample_value was. As the scalar value increases (2 and beyond), the x-input to tanh will be large enough that the y inout approaches 1 (max). This is good because we don't clip, but we do have that large incoming sample_values are hard-limited. This causes the pleasing distortion effect--the wave gradually approaches a square wave thus introducing more high harmonics. 

