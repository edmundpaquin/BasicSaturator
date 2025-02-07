/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class GainAdjusterAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    GainAdjusterAudioProcessorEditor (GainAdjusterAudioProcessor&);
    ~GainAdjusterAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider* slider) override; //inherited from Slider::Listener

private:
    juce::Slider aGainSlider;
    
    juce::Image background;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    GainAdjusterAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GainAdjusterAudioProcessorEditor)
};
