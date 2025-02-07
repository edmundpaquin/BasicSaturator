/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
GainAdjusterAudioProcessorEditor::GainAdjusterAudioProcessorEditor (GainAdjusterAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    aGainSlider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag); //sliderStyle is an Enum.
    aGainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    
    aGainSlider.setRange(1.0f, 50.0f, 1.0f);
    aGainSlider.setValue(0.0f);
    
    aGainSlider.addListener(this); //this editor is listening for changes in the slider
    
    addAndMakeVisible(aGainSlider); //child component of the editor

    setSize (400, 400);
    
}

GainAdjusterAudioProcessorEditor::~GainAdjusterAudioProcessorEditor()
{
}

//==============================================================================
void GainAdjusterAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll(juce::Colours::black);
    background = juce::ImageCache::getFromMemory(BinaryData::metal_jpg, BinaryData::metal_jpgSize);
    g.drawImageWithin(background,0,0, getWidth(), getHeight(), juce::RectanglePlacement::stretchToFit);
    
//    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
//
    g.setColour (juce::Colours::black);
    g.setFont (juce::FontOptions (20.0f));
    g.drawFittedText ("Basic Saturator (Harmonic Distortion)", getLocalBounds(), juce::Justification::centredTop, 1);
    g.setFont (juce::FontOptions (10.0f));
    g.drawFittedText ("Slider value represents integer multiplier\n before applying tanh distortion method.", getLocalBounds(), juce::Justification::centredBottom, 1);
}

void GainAdjusterAudioProcessorEditor::resized()
{
    
    aGainSlider.setBounds (getWidth()/2 - 100, getHeight()/2 - 100, 200, 200); //set location of slider

}

void GainAdjusterAudioProcessorEditor::sliderValueChanged(juce::Slider* slider)
{
    if (slider == &aGainSlider){
        audioProcessor.gain = aGainSlider.getValue();
    }
}
