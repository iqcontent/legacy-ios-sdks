/*
     File:       AudioUnitParameters.h
 
     Contains:   Parameter constants for Apple AudioUnits
 
     Copyright:  (c) 2002-2008 by Apple, Inc., all rights reserved.
 
     Bugs?:      For bug reports, consult the following page on
                 the World Wide Web:
 
                     http://developer.apple.com/bugreporter/
 
*/

#ifndef __AudioUnitParameters
#define __AudioUnitParameters

#pragma mark General Declarations

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The following specifies the equivalent parameterID's for the Group scope for standard
MIDI Controllers. This list is not exhaustive. It represents the parameters, and their corresponding 
MIDI messages, that should be supported in Group scope by MIDI capable AUs.

Group scope parameter IDs from 0 < 512 are reserved for mapping MIDI controllers.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
enum {
	kAUGroupParameterID_Volume					= 7,	// value 0 < 128
	kAUGroupParameterID_Sustain					= 64, 	// value 0-63 (off), 64-127 (on)
	kAUGroupParameterID_Sostenuto				= 66, 	// value 0-63 (off), 64-127 (on)
	kAUGroupParameterID_AllNotesOff				= 123,	// value ignored
	kAUGroupParameterID_ModWheel				= 1,	// value 0 < 128
	kAUGroupParameterID_PitchBend				= 0xE0,	// value -8192 - 8191
	kAUGroupParameterID_AllSoundOff				= 120,	// value ignored
	kAUGroupParameterID_ResetAllControllers		= 121,	// value ignored
	kAUGroupParameterID_Pan						= 10,	// value 0 < 128
	kAUGroupParameterID_Foot					= 4,	// value 0 < 128
	kAUGroupParameterID_ChannelPressure			= 0xD0,	// value 0 < 128
	kAUGroupParameterID_KeyPressure				= 0xA0,	// values 0 < 128
	kAUGroupParameterID_Expression				= 11,	// value 0 < 128
	kAUGroupParameterID_DataEntry				= 6,	// value 0 < 128

	kAUGroupParameterID_Volume_LSB				= kAUGroupParameterID_Volume + 32,		// value 0 < 128
	kAUGroupParameterID_ModWheel_LSB			= kAUGroupParameterID_ModWheel + 32,	// value 0 < 128
	kAUGroupParameterID_Pan_LSB					= kAUGroupParameterID_Pan + 32,			// value 0 < 128
	kAUGroupParameterID_Foot_LSB				= kAUGroupParameterID_Foot + 32,		// value 0 < 128
	kAUGroupParameterID_Expression_LSB			= kAUGroupParameterID_Expression + 32,	// value 0 < 128
	kAUGroupParameterID_DataEntry_LSB			= kAUGroupParameterID_DataEntry + 32,	// value 0 < 128
	
	kAUGroupParameterID_KeyPressure_FirstKey	= 256,	// value 0 < 128
	kAUGroupParameterID_KeyPressure_LastKey		= 383	// value 0 < 128
};
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Supporting the kAUGroupParameterID_KeyPressure parameter indicates to hosts that your audio unit
supports polyphonic "aftertouch" key pressure. 

Each of the 128 MIDI key numbers can have its own value for polyphonic aftertouch. To respond to 
aftertouch for a particular key, your audio unit needs to support an additional parameter 
specifically for that key. The aftertouch parameter ID for a given MIDI key is equal to the MIDI 
key number plus 256. For example, the aftertouch parameter ID for MIDI key #60 (middle C) is:

	60 + kAUGroupParameterID_KeyPressure_FirstKey = 316
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
The following sections specify the parameter IDs for the audio units included in Mac OS X.
Host applications can use these IDs to directly address these parameters without first discovering 
them through the AUParameterInfo mechanism (see the AudioUnitProperties.h header file)

Each parameter is preceeded by a comment that indicates scope, unit of measurement, minimum
value, maximum value, and default value.
    
See the AudioUnitProperties.h header file for additional information that a parameter may report

When displaying to the user information about a parameter, a host application should always
get the parameter information from the audio unit itself.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if !TARGET_OS_IPHONE
// Parameters for all Panner AudioUnits
enum {
        // Global, Linear, 0->1, 1
	kPannerParam_Gain = 0,			
	
        // Global, Degrees, -180->180, 0
	kPannerParam_Azimuth = 1,		
        // Global, Degrees, -90->90, 0
	kPannerParam_Elevation = 2,	
		
        // Global, Linear, 0->1, 1
	kPannerParam_Distance = 3,		// 0 .. 1
	
        // Global, Meters, 0.01->1000, 1
	kPannerParam_CoordScale = 4,	
        // Global, Meters, 0.01->1000, 1
	kPannerParam_RefDistance = 5,	
};
#endif // !TARGET_OS_IPHONE



#pragma mark Apple Specific

// Parameters for the AUMixer3D unit
enum {
        // Input, Degrees, -180->180, 0
    k3DMixerParam_Azimuth		= 0,
        
		// Input, Degrees, -90->90, 0
    k3DMixerParam_Elevation		= 1,
        
		// Input, Metres, 0->10000, 0
    k3DMixerParam_Distance		= 2,
        
		// Input/Output, dB, -120->20, 0
    k3DMixerParam_Gain			= 3,
	
		// Input, rate scaler	0.5 -> 2.0
    k3DMixerParam_PlaybackRate	= 4,
	
#if TARGET_OS_IPHONE
		// iPhone specific 3D mixer parameters

		// bus enable : 0.0 or 1.0
    k3DMixerParam_Enable       = 5,

		// Minimum input gain constraint : 0.0 -> 1.0 (available on iphone only)
    k3DMixerParam_MinGain      = 6,

		// Maximum input gain constraint : 0.0 -> 1.0 (available on iphone only)
    k3DMixerParam_MaxGain      = 7,
	
		// Input, Dry/Wet equal-power blend, %	  0.0 -> 100.0
    k3DMixerParam_ReverbBlend		= 8,

		// Global, dB,		-40.0 -> +40.0
    k3DMixerParam_GlobalReverbGain	= 9,
	
		// Input, Lowpass filter attenuation at 5KHz :		decibels -100.0dB -> 0.0dB
		// smaller values make both direct and reverb sound more muffled; a value of 0.0 indicates no filtering
		// Occlusion is a filter applied to the sound prior to the reverb send
    k3DMixerParam_OcclusionAttenuation	= 10,
	
		// Input, Lowpass filter attenuation at 5KHz :		decibels -100.0dB -> 0.0dB
		// smaller values make direct sound more muffled; a value of 0.0 indicates no filtering
		// Obstruction is a filter applied to the "direct" part of the sound (so is post reverb send)
    k3DMixerParam_ObstructionAttenuation = 11
#else
		// Desktop specific 3D mixer parameters

		// Input, Dry/Wet equal-power blend, %	  0.0 -> 100.0
    k3DMixerParam_ReverbBlend		= 5,

		// Global, dB,		-40.0 -> +40.0
    k3DMixerParam_GlobalReverbGain	= 6,
	
		// Input, Lowpass filter attenuation at 5KHz :		decibels -100.0dB -> 0.0dB
		// smaller values make both direct and reverb sound more muffled; a value of 0.0 indicates no filtering
		// Occlusion is a filter applied to the sound prior to the reverb send
    k3DMixerParam_OcclusionAttenuation	= 7,
	
		// Input, Lowpass filter attenuation at 5KHz :		decibels -100.0dB -> 0.0dB
		// smaller values make direct sound more muffled; a value of 0.0 indicates no filtering
		// Obstruction is a filter applied to the "direct" part of the sound (so is post reverb send)
    k3DMixerParam_ObstructionAttenuation = 8,

		// Input/Output, dB, -120->20, 0
    k3DMixerParam_MinGain		= 9,
	
		// Input/Output, dB, -120->20, 0
    k3DMixerParam_MaxGain		= 10,

		// read-only
		//
		// For each of the following, use the parameter ID plus the channel number
		// to get the specific parameter ID for a given channel.
		// For example, k3DMixerParam_PostAveragePower indicates the left channel
		// while k3DMixerParam_PostAveragePower + 1 indicates the right channel.
	k3DMixerParam_PreAveragePower	= 1000,
	k3DMixerParam_PrePeakHoldLevel	= 2000,
	k3DMixerParam_PostAveragePower	= 3000,
	k3DMixerParam_PostPeakHoldLevel	= 4000
#endif
};

// Reverb parameters applicable to the 3DMixer
enum {
		// Global, Hertz, 10.0 -> 20000.0, 800.0
	kReverbParam_FilterFrequency					= 14,

		// Global, Octaves, 0.05 -> 4.0, 3.0
	kReverbParam_FilterBandwidth					= 15,

		// Global, Decibels, -18.0 -> +18.0, 0.0
	kReverbParam_FilterGain							= 16
};

// Parameters for the AUMultiChannelMixer unit
// these are available for both desktop and iphone
enum {
		// Global, Linear Gain, 0->1, 1
	kMultiChannelMixerParam_Volume 	= 0,
		// Global, Boolean, 0->1, 1
	kMultiChannelMixerParam_Enable 	= 1,
		// Global, Pan
	kMultiChannelMixerParam_Pan     = 2,			// -1 - 0 - 1, only valid when output is not mono
													// relationship to mix matrix: last one in wins

		// read-only
	// these report level in dB, as do the other mixers
	kMultiChannelMixerParam_PreAveragePower		= 1000,
	kMultiChannelMixerParam_PrePeakHoldLevel	= 2000,
	kMultiChannelMixerParam_PostAveragePower	= 3000,
	kMultiChannelMixerParam_PostPeakHoldLevel	= 4000
};


// Parameters for the AUMatrixMixer unit
enum {
	kMatrixMixerParam_Volume 	= 0,
	kMatrixMixerParam_Enable 	= 1,
	
		// read-only
	// these report level in dB, as do the other mixers
	kMatrixMixerParam_PreAveragePower	= 1000,
	kMatrixMixerParam_PrePeakHoldLevel	= 2000,
	kMatrixMixerParam_PostAveragePower	= 3000,
	kMatrixMixerParam_PostPeakHoldLevel	= 4000,

	// these report linear levels - for "expert" use only.
	kMatrixMixerParam_PreAveragePowerLinear			= 5000,
	kMatrixMixerParam_PrePeakHoldLevelLinear		= 6000,
	kMatrixMixerParam_PostAveragePowerLinear		= 7000,
	kMatrixMixerParam_PostPeakHoldLevelLinear		= 8000
};


// Output Units
// Parameters for the AudioDeviceOutput, DefaultOutputUnit, and SystemOutputUnit units
enum {
		// Global, LinearGain, 0->1, 1
	kHALOutputParam_Volume 		= 14 
};

// Parameters for the AUTimePitch, AUTimePitch (offline), AUPitch units
enum {
	kTimePitchParam_Rate						= 0,
#if !TARGET_OS_IPHONE
	kTimePitchParam_Pitch						= 1,
	kTimePitchParam_EffectBlend					= 2		// only for the AUPitch unit
#endif
};

// Parameters for AUNewTimePitch
enum {
		// Global, rate, 1/32 -> 32.0, 1.0
	kNewTimePitchParam_Rate							= 0,
		// Global, Cents, -2400 -> 2400, 1.0
	kNewTimePitchParam_Pitch						= 1,
		// Global, generic, 3.0 -> 32.0, 8.0
	kNewTimePitchParam_Overlap						= 4,
		// Global, Boolean, 0->1, 1
	kNewTimePitchParam_EnablePeakLocking			= 6
};

// Parameters for the AUSampler unit
enum {
		// Global, dB, -90->12, 0
	kAUSamplerParam_Gain				= 900,

		// Global, Semitones, -24->24, 0
	kAUSamplerParam_CoarseTuning		= 901,

		// Global, Cents, -99->99, 0
	kAUSamplerParam_FineTuning			= 902,

		// Global, -1.0->1.0, 0
	kAUSamplerParam_Pan					= 903
};

// Effect units
// The values for some effect unit parameters depend on the audio unit's sample rate.
// For example, maximum values are typically the Nyquist frequency (indicated here as 
// SampleRate/2).

// Parameters for the AUBandpass unit
enum {
		// Global, Hz, 20->(SampleRate/2), 5000
	kBandpassParam_CenterFrequency 			= 0,

		// Global, Cents, 100->12000, 600
	kBandpassParam_Bandwidth 				= 1
};

// Parameters for the AUHipass unit
enum {
		// Global, Hz, 10->(SampleRate/2), 6900
	kHipassParam_CutoffFrequency 			= 0,
		
		// Global, dB, -20->40, 0
	kHipassParam_Resonance					= 1
};

// Parameters for the AULowpass unit
enum {
		// Global, Hz, 10->(SampleRate/2), 6900
	kLowPassParam_CutoffFrequency 			= 0,
		
		// Global, dB, -20->40, 0
	kLowPassParam_Resonance 				= 1
};

// Parameters for the AUHighShelfFilter unit
enum {
		// Global, Hz, 10000->(SampleRate/2), 10000
	kHighShelfParam_CutOffFrequency 		= 0,
		
		// Global, dB, -40->40, 0
	kHighShelfParam_Gain 					= 1
};

// Parameters for the AULowShelfFilter unit
enum {
		// Global, Hz, 10->200, 80
	kAULowShelfParam_CutoffFrequency = 0,
		
		// Global, dB, -40->40, 0
	kAULowShelfParam_Gain = 1
};

// Parameters for the AUDCFilter unit
enum {
		// Global, Seconds, .0001->1., .03
	kAUDCFilterParam_DecayTime = 0,		
};

// Parameters for the AUParametricEQ unit
enum {
		// Global, Hz, 20->(SampleRate/2), 2000
    kParametricEQParam_CenterFreq = 0,
		
		// Global, Hz, 0.1->20, 1.0
    kParametricEQParam_Q = 1,
		
		// Global, dB, -20->20, 0
    kParametricEQParam_Gain = 2
};

// Parameters for the AUPeakLimiter unit
enum {
		// Global, Secs, 0.001->0.03, 0.012
	kLimiterParam_AttackTime 			= 0,
		
		// Global, Secs, 0.001->0.06, 0.024
	kLimiterParam_DecayTime 			= 1,
		
		// Global, dB, -40->40, 0
	kLimiterParam_PreGain 				= 2
};

// Parameters for the AUDynamicsProcessor unit
enum {
		// Global, dB, -40->20, -20
	kDynamicsProcessorParam_Threshold 			= 0,
		
		// Global, dB, 0.1->40.0, 5
	kDynamicsProcessorParam_HeadRoom	 		= 1,
		
		// Global, rate, 1->50.0, 2
	kDynamicsProcessorParam_ExpansionRatio		= 2,
		
		// Global, dB
	kDynamicsProcessorParam_ExpansionThreshold	= 3,
		
		// Global, secs, 0.0001->0.2, 0.001
	kDynamicsProcessorParam_AttackTime 			= 4,
		
		// Global, secs, 0.01->3, 0.05
	kDynamicsProcessorParam_ReleaseTime 		= 5,
		
		// Global, dB, -40->40, 0
	kDynamicsProcessorParam_MasterGain 			= 6,
	
		// Global, dB, read-only parameter
	kDynamicsProcessorParam_CompressionAmount 	= 1000,
	kDynamicsProcessorParam_InputAmplitude		= 2000,
	kDynamicsProcessorParam_OutputAmplitude 	= 3000
};


// Parameters for the AUVarispeed unit
enum {
		// Global, Rate, 0.25 -> 4.0, 1.0
	kVarispeedParam_PlaybackRate				= 0,
		// Global, Cents, -2400 -> 2400, 0.0
	kVarispeedParam_PlaybackCents				= 1
};


// Parameters for the Distortion unit 
enum {
		// Global, Milliseconds, 0.1 -> 500, 0.1
	kDistortionParam_Delay = 0,
		// Global, Rate, 0.1 -> 50, 1.0
	kDistortionParam_Decay = 1,
		// Global, Percent, 0 -> 100, 50
	kDistortionParam_DelayMix = 2,
	
		// Global, Percent, 0 -> 100
	kDistortionParam_Decimation = 3,
		// Global, Percent, 0 -> 100, 0
	kDistortionParam_Rounding = 4,
		// Global, Percent, 0 -> 100, 50
	kDistortionParam_DecimationMix = 5,
	
		// Global, Linear Gain, 0 -> 1, 1
	kDistortionParam_LinearTerm = 6,  
		// Global, Linear Gain, 0 -> 20, 0
	kDistortionParam_SquaredTerm = 7,	
		// Global, Linear Gain, 0 -> 20, 0
	kDistortionParam_CubicTerm = 8,  
		// Global, Percent, 0 -> 100, 50
	kDistortionParam_PolynomialMix = 9,
	
		// Global, Hertz, 0.5 -> 8000, 100
	kDistortionParam_RingModFreq1 = 10,
		// Global, Hertz, 0.5 -> 8000, 100
	kDistortionParam_RingModFreq2 = 11,
		// Global, Percent, 0 -> 100, 50
	kDistortionParam_RingModBalance = 12,
		// Global, Percent, 0 -> 100, 0
	kDistortionParam_RingModMix = 13,
				
		// Global, dB, -80 -> 20, -6
	kDistortionParam_SoftClipGain = 14,
		
		// Global, Percent, 0 -> 100, 50
	kDistortionParam_FinalMix = 15
};

// Parameters for the AUDelay unit
enum {
		// Global, EqPow Crossfade, 0->100, 50
	kDelayParam_WetDryMix 				= 0,
		
		// Global, Secs, 0->2, 1
	kDelayParam_DelayTime				= 1,
		
		// Global, Percent, -100->100, 50
	kDelayParam_Feedback 				= 2,
		
		// Global, Hz, 10->(SampleRate/2), 15000
	kDelayParam_LopassCutoff	 		= 3
};

#pragma mark Apple Specific - Desktop

#if !TARGET_OS_IPHONE

// Some parameters for the AUGraphicEQ unit
enum {
		// Global, Indexed, currently either 10 or 31
	kGraphicEQParam_NumberOfBands 			= 10000
};

// Parameters for the AUMatrixReverb unit
enum {
		// Global, EqPow CrossFade, 0->100, 100
	kReverbParam_DryWetMix 							= 0,
		
		// Global, EqPow CrossFade, 0->100, 50
	kReverbParam_SmallLargeMix						= 1,
		
		// Global, Secs, 0.005->0.020, 0.06
	kReverbParam_SmallSize							= 2,
		
		// Global, Secs, 0.4->10.0, 3.07
	kReverbParam_LargeSize							= 3,
		
		// Global, Secs, 0.001->0.03, 0.025
	kReverbParam_PreDelay							= 4,
		
		// Global, Secs, 0.001->0.1, 0.035
	kReverbParam_LargeDelay							= 5,
		
		// Global, Genr, 0->1, 0.28
	kReverbParam_SmallDensity						= 6,
		
		// Global, Genr, 0->1, 0.82
	kReverbParam_LargeDensity						= 7,
		
		// Global, Genr, 0->1, 0.3
	kReverbParam_LargeDelayRange					= 8,
		
		// Global, Genr, 0.1->1, 0.96
	kReverbParam_SmallBrightness					= 9,
		
		// Global, Genr, 0.1->1, 0.49
	kReverbParam_LargeBrightness					= 10,

		// Global, Genr, 0->1 0.5
	kReverbParam_SmallDelayRange					= 11,

		// Global, Hz, 0.001->2.0, 1.0
	kReverbParam_ModulationRate						= 12,

		// Global, Genr, 0.0 -> 1.0, 0.2
	kReverbParam_ModulationDepth					= 13,
};

// Parameters for the AUMultibandCompressor unit
enum {
		// Global, dB, -40 -> 40, 0
	kMultibandCompressorParam_Pregain 			= 0,
		// Global, dB, -40 -> 40, 0
	kMultibandCompressorParam_Postgain 			= 1,
		// Global, Hertz, 20 -> (SampleRate/2), 120.0
	kMultibandCompressorParam_Crossover1 		= 2,
		// Global, Hertz, 20 -> (SampleRate/2), 700.0
	kMultibandCompressorParam_Crossover2 		= 3,
		// Global, Hertz, 20 -> (SampleRate/2), 3000.0
	kMultibandCompressorParam_Crossover3 		= 4,
		// Global, dB, -100.0 -> 0.0, -22.0
	kMultibandCompressorParam_Threshold1 		= 5,
		// Global, dB, -100.0 -> 0.0, -32.0
	kMultibandCompressorParam_Threshold2 		= 6,
		// Global, dB, -100.0 -> 0.0, -33.0
	kMultibandCompressorParam_Threshold3 		= 7,
		// Global, dB, -100.0 -> 0.0, -36.0
	kMultibandCompressorParam_Threshold4 		= 8,
		// Global, dB, 0.1 -> 40.0, 5.0
	kMultibandCompressorParam_Headroom1 		= 9,
		// Global, dB, 0.1 -> 40.0, 12.0
	kMultibandCompressorParam_Headroom2 		= 10,
		// Global, dB, 0.1 -> 40.0, 5.0
	kMultibandCompressorParam_Headroom3 		= 11,
		// Global, dB, 0.1 -> 40.0, 7.5
	kMultibandCompressorParam_Headroom4 		= 12,
		// Global, Secs, 0.001 -> 0.200, 0.080
	kMultibandCompressorParam_AttackTime 		= 13,
		// Global, Secs, 0.010 -> 3.0, 0.120
	kMultibandCompressorParam_ReleaseTime 		= 14,
		// Global, dB, -20 -> 20, 0
	kMultibandCompressorParam_EQ1 				= 15,
		// Global, dB, -20 -> 20, 0
	kMultibandCompressorParam_EQ2 				= 16,
		// Global, dB, -20 -> 20, 0
	kMultibandCompressorParam_EQ3 				= 17,
		// Global, dB, -20 -> 20, 0
	kMultibandCompressorParam_EQ4 				= 18,
	
	// read-only parameters
		// Global, dB, 0 -> 20
	kMultibandCompressorParam_CompressionAmount1 = 1000,
		// Global, dB, 0 -> 20
	kMultibandCompressorParam_CompressionAmount2 = 2000,
		// Global, dB, 0 -> 20
	kMultibandCompressorParam_CompressionAmount3 = 3000,
		// Global, dB, 0 -> 20
	kMultibandCompressorParam_CompressionAmount4 = 4000,

		// Global, dB, -120 -> 20
	kMultibandCompressorParam_InputAmplitude1 = 5000,
		// Global, dB, -120 -> 20
	kMultibandCompressorParam_InputAmplitude2 = 6000,
		// Global, dB, -120 -> 20
	kMultibandCompressorParam_InputAmplitude3 = 7000,
		// Global, dB, -120 -> 20
	kMultibandCompressorParam_InputAmplitude4 = 8000,

		// Global, dB, -120 -> 20
	kMultibandCompressorParam_OutputAmplitude1 = 9000,
		// Global, dB, -120 -> 20
	kMultibandCompressorParam_OutputAmplitude2 = 10000,
		// Global, dB, -120 -> 20
	kMultibandCompressorParam_OutputAmplitude3 = 11000,
		// Global, dB, -120 -> 20
	kMultibandCompressorParam_OutputAmplitude4 = 12000
};

// Parameters for the AUFilter unit
enum
{
		// Global, indexed, 0 -> 1, 0
	kMultibandFilter_LowFilterType  = 0,
		// Global, Hertz, 10 -> (SampleRate/2), 100
	kMultibandFilter_LowFrequency   = 1,
		// Global, dB, -18 -> +18, 0
	kMultibandFilter_LowGain		= 2,

		// Global, Hertz, 10 -> (SampleRate/2), 100
	kMultibandFilter_CenterFreq1	= 3,
		// Global, dB, -18 -> +18, 0
	kMultibandFilter_CenterGain1	= 4,
		// Global, Octaves, 0.05 -> 3.0, 2.0
	kMultibandFilter_Bandwidth1		= 5,
	
		// Global, Hertz, 10 -> (SampleRate/2), 100
	kMultibandFilter_CenterFreq2	= 6,
		// Global, dB, -18 -> +18, 0
	kMultibandFilter_CenterGain2	= 7,
		// Global, Octaves, 0.05 -> 3.0, 2.0
	kMultibandFilter_Bandwidth2		= 8,
	
		// Global, Hertz, 10 -> (SampleRate/2), 100
	kMultibandFilter_CenterFreq3	= 9,
		// Global, dB, -18 -> +18, 0
	kMultibandFilter_CenterGain3	= 10,
		// Global, Octaves, 0.05 -> 3.0, 2.0
	kMultibandFilter_Bandwidth3		= 11,

		// Global, indexed, 0 -> 1, 0
	kMultibandFilter_HighFilterType	= 12,
		// Global, Hertz, 10 -> (SampleRate/2), 100
	kMultibandFilter_HighFrequency  = 13,
		// Global, dB, -18 -> +18, 0
	kMultibandFilter_HighGain		= 14
};

// Parameters for AURogerBeep
enum {
		// Global, dB, -80 -> 0, -6
	kRogerBeepParam_InGateThreshold = 0,
		// Global, Milliseconds, 0 -> 1000, 1000
	kRogerBeepParam_InGateThresholdTime = 1,
		// Global, dB, -80 -> 0, -6
	kRogerBeepParam_OutGateThreshold = 2,
		// Global, Milliseconds, 0 -> 1000, 1000
	kRogerBeepParam_OutGateThresholdTime = 3,	
		// Global, indexed, 0 -> 2, 2
	kRogerBeepParam_Sensitivity = 4,	
		// Global, indexed, 0 -> 2, 0
	kRogerBeepParam_RogerType = 5,
		// Global, dB, -80 -> 20, -6
	kRogerBeepParam_RogerGain = 6
};

// Mixer Units

// Parameters for the Stereo Mixer unit
enum {
		// Input/Output, Mixer Fader Curve, 0->1, 1
	kStereoMixerParam_Volume 	= 0,
		
		// Input, Pan, 0->1, 0.5
	kStereoMixerParam_Pan		= 1,
	
		// read-only
		//
		// For each of the following, use the parameter ID for the left channel
		// and the parameter ID plus one for the right channel.
		// For example, kStereoMixerParam_PostAveragePower indicates the left channel
		// while kStereiMixerParam_PostAveragePower + 1 indicates the right channel.
	kStereoMixerParam_PreAveragePower	= 1000,
	kStereoMixerParam_PrePeakHoldLevel	= 2000,
	kStereoMixerParam_PostAveragePower	= 3000,
	kStereoMixerParam_PostPeakHoldLevel	= 4000
};

// Parameters for the AUNetReceive unit
enum {
		// Global, indexed, 0 -> 5, read only
	kAUNetReceiveParam_Status = 0,
	kAUNetReceiveParam_NumParameters = 1
};

// Parameters for the AUNetSend unit
enum {
		// Global, indexed, 0 -> 5, read only
	kAUNetSendParam_Status = 0,
	kAUNetSendParam_NumParameters = 1
};


// Status values for the AUNetSend and AUNetReceive units
enum {
	kAUNetStatus_NotConnected = 0,
	kAUNetStatus_Connected = 1,
	kAUNetStatus_Overflow = 2,
	kAUNetStatus_Underflow = 3,
	kAUNetStatus_Connecting = 4,
	kAUNetStatus_Listening = 5
};

// Music Device
// Parameters for the DLSMusicDevice unit - defined and reported in the global scope
enum {
		// Global, Cents, -1200, 1200, 0
	kMusicDeviceParam_Tuning 	= 0,

		// Global, dB, -120->40, 0
	kMusicDeviceParam_Volume	= 1,

		// Global, dB, -120->40, 0
	kMusicDeviceParam_ReverbVolume	= 2
};
// In Mac OS X v10.5, the DLSMusicDevice audio unit does not report parameters in the Group scope.
// However, parameter values can be set in Group scope that correspond to controller values defined  
// by the MIDI specification. This includes the standard MIDI Controller values (such as Volume and
// Mod Wheel) as well as MIDI status messages (such as Pitch Bend and Channel Pressure) and the 
// MIDI RPN control messages.

// For MIDI status messages, use a value of 0 for the "channel part" (lower four bits) when setting  
// these parameters. This allows audio units to distinguish these IDs from the 0-127 
// values used by MIDI controllers in the first byte of status messages.
// 
// The element ID represents the group or channel number.
//
// You can use the MusicDeviceMIDIEvent function to send a MIDI formatted control command to a device.
//
// You can use the SetParameter API calls, declared in the AUComponent.h header file, as follows:
//
//	scope == kAudioUnitScope_Group
//	element == groupID -> in MIDI equivalent to channel number 0->15, 
//			but this is not a limitation of the MusicDevice and values greater than 15 can be specified
//	paramID == midi controller value (0->127), (status bytes corresponding to pitch bend, channel pressure)
//	value == typically the range associated with the corresponding MIDI message	(7 bit, 0->127)
//			pitch bend is specified as a 14 bit value
	
// See the MusicDevice.h header file for more about using the extended control semantics 
// of this API.	

// Parameters for the AURoundTripAACParam unit
enum {
		// Global, indexed : AAC, AAC HE, AAC HEv2, AAC ELD
	kRoundTripAACParam_Format				= 0,
	
		// Global, indexed
	kRoundTripAACParam_EncodingStrategy = 1,

		// Global, indexed
	kRoundTripAACParam_RateOrQuality = 2,
	
		// These are deprecated:
	kRoundTripAACParam_BitRate				= 1,
	kRoundTripAACParam_Quality 				= 2,
	kRoundTripAACParam_CompressedFormatSampleRate = 3
};
#endif // !TARGET_OS_IPHONE


#pragma mark Apple Specific - iOS

#if TARGET_OS_IPHONE


// Parameters for the AUNBandEQ unit
// Note that the parameter IDs listed correspond to band 0 (zero) of the unit. The parameter IDs for
// higher bands can be obtained by adding the zero-indexed band number to the corresponding band 0
// parameter ID up to the number of bands minus one, where the number of bands is described by the
// AUNBandEQ property kAUNBandEQProperty_NumberOfBands. For example, the parameter ID corresponding
// to the filter type of band 4 would be kAUNBandEQParam_FilterType + 3.
// kAUNBandEQParam_GlobalsGain is an overall gain and does not have a band. 
enum {
		// Global, dB, -96->24, 0
	kAUNBandEQParam_GlobalGain								= 0,
	
		// Global, Boolean, 0 or 1, 1
	kAUNBandEQParam_BypassBand								= 1000,
	
		// Global, Indexed, 0->kNumAUNBandEQFilterTypes-1, 0
	kAUNBandEQParam_FilterType								= 2000,
	
		// Global, Hz, 20->(SampleRate/2), 1000
	kAUNBandEQParam_Frequency								= 3000,
	
		// Global, dB, -96->24, 0
	kAUNBandEQParam_Gain									= 4000,
	
		// Global, octaves, 0.05->5.0, 0.5
	kAUNBandEQParam_Bandwidth								= 5000
};

/*!
	@enum			AUNBandEQ filter types
	@discussion		Constants available as values for the kAUNBandEQParam_FilterType parameter defined above
	
	@constant		kAUNBandEQFilterType_Parametric
					Parametric filter based on Butterworth analog prototype. Uses parameterization where
					the bandwidth is specifed as the relationship of the upper bandedge frequency to the
					lower bandedge frequency in octaves, where the upper and lower bandedge frequencies are
					the respective frequencies above and below the center frequency at which the gain is
					equal to half the peak gain.
						Applicable parameters:
							- kAUNBandEQParam_Frequency (center frequency)
							- kAUNBandEQParam_Gain (peak gain)
							- kAUNBandEQParam_Bandwidth
	
	@constant		kAUNBandEQFilterType_2ndOrderButterworthLowPass
					Simple Butterworth 2nd order low pass filter
						Applicable parameters:
							- kAUNBandEQParam_Frequency (-3 dB cutoff frequency)
	
	@constant		kAUNBandEQFilterType_2ndOrderButterworthHighPass
					Simple Butterworth 2nd order high pass filter
						Applicable parameters:
							- kAUNBandEQParam_Frequency (-3 dB cutoff frequency)

	@constant		kAUNBandEQFilterType_ResonantLowPass
					Low pass filter with resonance support (via bandwidth parameter)
						Applicable parameters:
							- kAUNBandEQParam_Frequency (-3 dB cutoff frequency)
							- kAUNBandEQParam_Bandwidth

	@constant		kAUNBandEQFilterType_ResonantHighPass
					High pass filter with resonance support (via bandwidth parameter)
						Applicable parameters:
							- kAUNBandEQParam_Frequency (-3 dB cutoff frequency)
							- kAUNBandEQParam_Bandwidth

	@constant		kAUNBandEQFilterType_BandPass
					Band pass filter
						Applicable parameters:
							- kAUNBandEQParam_Frequency (center frequency)
							- kAUNBandEQParam_Bandwidth

	@constant		kAUNBandEQFilterType_BandStop
					Band stop filter (aka "notch filter")
						Applicable parameters:
							- kAUNBandEQParam_Frequency (center frequency)
							- kAUNBandEQParam_Bandwidth

	@constant		kAUNBandEQFilterType_LowShelf
					Low shelf filter
						Applicable parameters:
							- kAUNBandEQParam_Frequency (center frequency)
							- kAUNBandEQParam_Gain (shelf gain)

	@constant		kAUNBandEQFilterType_HighShelf
					High shelf filter
						Applicable parameters:
							- kAUNBandEQParam_Frequency (center frequency)
							- kAUNBandEQParam_Gain (shelf gain)
	
	@constant		kAUNBandEQFilterType_ResonantLowShelf
					Low shelf filter with resonance support (via bandwidth parameter)
						Applicable parameters:
							- kAUNBandEQParam_Frequency (center frequency)
							- kAUNBandEQParam_Gain (shelf gain)
							- kAUNBandEQParam_Bandwidth

	@constant		kAUNBandEQFilterType_ResonantHighShelf
					High shelf filter with resonance support (via bandwidth parameter)
						Applicable parameters:
							- kAUNBandEQParam_Frequency (center frequency)
							- kAUNBandEQParam_Gain (shelf gain)
							- kAUNBandEQParam_Bandwidth
	
*/
enum {
	kAUNBandEQFilterType_Parametric							= 0,
	kAUNBandEQFilterType_2ndOrderButterworthLowPass			= 1,
	kAUNBandEQFilterType_2ndOrderButterworthHighPass		= 2,
	kAUNBandEQFilterType_ResonantLowPass					= 3,
	kAUNBandEQFilterType_ResonantHighPass					= 4,
	kAUNBandEQFilterType_BandPass							= 5,
	kAUNBandEQFilterType_BandStop							= 6,
	kAUNBandEQFilterType_LowShelf							= 7,
	kAUNBandEQFilterType_HighShelf							= 8,
	kAUNBandEQFilterType_ResonantLowShelf					= 9,
	kAUNBandEQFilterType_ResonantHighShelf					= 10,
	
	kNumAUNBandEQFilterTypes								= 11
};



// Parameters for the iOS reverb unit
enum {
		// Global, CrossFade, 0->100, 100
	kReverb2Param_DryWetMix 						= 0,
		// Global, Decibels, -20->20, 0
	kReverb2Param_Gain								= 1,
		
		// Global, Secs, 0.0001->1.0, 0.008
	kReverb2Param_MinDelayTime						= 2,
		// Global, Secs, 0.0001->1.0, 0.050
	kReverb2Param_MaxDelayTime						= 3,
		// Global, Secs, 0.001->20.0, 1.0
	kReverb2Param_DecayTimeAt0Hz					= 4,
		// Global, Secs, 0.001->20.0, 0.5
	kReverb2Param_DecayTimeAtNyquist				= 5,
		// Global, Integer, 1->1000
	kReverb2Param_RandomizeReflections				= 6,
};
#endif // TARGET_OS_IPHONE

#endif //__AudioUnitParameters
